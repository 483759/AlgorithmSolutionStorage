package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class solution2 {
    //  백 기준 (아래)
//  12시부터 시계방향
//  1 ~ 3은 루프로 체크 필요
//	0 : 사용하지 않음
//	1 : 퀸
//	2 : 룩
//	3 : 비숍
//	4 : 킹
    public static int[][] dr = {{},
        { -1, -1, 0, 1, 1, 1, 0, -1 },
        { -1, 0, 1, 0 },
        { -1, -1, 1, 1 },
        { -1, -1, 0, 1, 1, 1, 0, -1 }};

    public static int[][] dc = {{},
        { 0, 1, 1, 1, 0, -1, -1, -1 },
        { 0, 1, 0, -1 },
        { -1, 1, 1, -1 },
        { 0, 1, 1, 1, 0, -1, -1, -1 }};

    // swap시 check 결과 반환
    public static boolean moveAndCheck(int[][] map, int nr, int nc, int[] piece, Queue<int[]> whitePieces) {
        boolean result = true;

        int tmp = map[nr][nc];
        map[nr][nc] = map[piece[0]][piece[1]];
        map[piece[0]][piece[1]] = 0;

        result = check(map, whitePieces);

        map[piece[0]][piece[1]] = map[nr][nc];
        map[nr][nc] = tmp;

        return result;
    }

    // check 상태인지 판단
    public static boolean check(int[][] map, Queue<int[]> whitePieces) {
        boolean[][] v = new boolean[8][8];

        // 백색 기물 이동 가능 범위 계산
        for(int[] piece : whitePieces) {
            if(map[piece[0]][piece[1]] < 10) continue;
            int x = map[piece[0]][piece[1]] % 10;

            // 퀸, 룩, 비숍
            for(int i = 0; i < dr[x].length; i++) {
                for(int j = 1; j <= 8; j++) {
                    int nr = piece[0] + dr[x][i] * j;
                    int nc = piece[1] + dc[x][i] * j;

                    if(nr < 0 || nr >= 8 || nc < 0 || nc >= 8 || map[nr][nc] >= 10) break;
                    v[nr][nc] = true;
                    if(map[nr][nc] != 0) break;
                }
            }
        }

        // 킹을 공격 가능한지 반환
        boolean result = true;
        E:for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(map[i][j] == 4) {
                    result = v[i][j];
                    break E;
                }
            }
        }

        return result;
    }

    public static boolean checkmate(int[][] map, Queue<int[]> blackPieces, Queue<int[]> whitePieces) {
        // 흑색 기물 이동 및 check 여부 판단
        for(int[] piece : blackPieces) {
            int x = map[piece[0]][piece[1]];

            // 퀸, 룩, 비숍
            if(x <= 3) {
                for(int i = 0; i < dr[x].length; i++) {
                    for(int j = 1; j <= 8; j++) {
                        int nr = piece[0] + dr[x][i] * j;
                        int nc = piece[1] + dc[x][i] * j;

                        if(nr < 0 || nr >= 8 || nc < 0 || nc >= 8 || (map[nr][nc] > 0 && map[nr][nc] < 10)) break;
                        if(!moveAndCheck(map, nr, nc, piece, whitePieces)) return false;

                        if(map[nr][nc] >= 10) break;
                    }
                }

                // 킹
            } else {
                for(int i = 0; i < dr[x].length; i++) {
                    int nr = piece[0] + dr[x][i];
                    int nc = piece[1] + dc[x][i];

                    if(nr < 0 || nr >= 8 || nc < 0 || nc >= 8 || (map[nr][nc] > 0 && map[nr][nc] < 10)) continue;
                    if(!moveAndCheck(map, nr, nc, piece, whitePieces)) return false;
                }
            }
        }
        return true;
    }

    // 테스트용 출력 함수
    public static void print(int[][] map) {
        // 흑 : 대문자
        // 백 : 소문자
        char[][] text = {{ '*', 'Q', 'R', 'B', 'K', 'N', 'P' },
            { '*', 'q', 'r', 'b', 'k', 'n', 'p' }};

        System.out.println();
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                int idx = map[i][j] >= 10 ? 1 : 0;
                int x = map[i][j] % 10;

                if(x < 1 || x > 6) System.out.print(text[idx][0]);
                else System.out.print(text[idx][x]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("sample_input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= T; tc++) {
            String[] NM = br.readLine().split(" ");
            int N = Integer.parseInt(NM[0]);
            int M = Integer.parseInt(NM[1]);

            int[][] map = new int[8][8];
            Queue<int[]> blackPieces = new LinkedList<int[]>();
            Queue<int[]> whitePieces = new LinkedList<int[]>();

            // 흑
            for(int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                int r = 8 - (input[1].charAt(1) - '0');
                int c = input[1].charAt(0) - 'A';

                map[r][c] = Integer.parseInt(input[0]);
                blackPieces.offer(new int[] { r, c });
            }

            // 편의상 백의 말은 숫자 + 10으로 표시
            for(int i = 0; i < M; i++) {
                String[] input = br.readLine().split(" ");
                int r = 8 - (input[1].charAt(1) - '0');
                int c = input[1].charAt(0) - 'A';

                map[r][c] = Integer.parseInt(input[0]) + 10;
                whitePieces.offer(new int[] { r, c });
            }

            print(map);
            bw.write(String.format("#%d %d\n", tc, (checkmate(map, blackPieces, whitePieces) ? 1 : 0)));
        }
        br.close();
        bw.flush();
    }
}