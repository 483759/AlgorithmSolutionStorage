package list;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//도저히 이해가 안 가서 다른 사람 코드 참고했습니다.
public class Swea3238 {
    static long Combination(long x, long y, long div){
        long ans = 1L;
        while(y > 0){
            if(y % 2 == 1){
                ans = (ans * x) % div;
            }
            x = (x * x) % div;
            y /= 2;
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for(int k = 0; k < T; k++){
            st = new StringTokenizer(br.readLine(), " ");

            long N = Long.parseLong(st.nextToken());
            long R = Long.parseLong(st.nextToken());
            long M = Integer.parseInt(st.nextToken());

            long[] fn = new long[(int) M];
            fn[0] = 1;
            for (int i = 1; i < M; i++)
                fn[i] = (fn[i - 1] * i) % M;

            long res = 1L;
            while(N > 0 || R > 0){
                long n = N % M;
                long r = R % M;
                if(n < r) res = 0L;
                if(res == 0L) break;
                res = (res * fn[(int) n]) % M;
                res = (res * Combination((fn[(int) r] * fn[(int) (n - r)]) % M, M - 2, M)) % M;
                N /= M;
                R /= M;
            }

            System.out.printf("#%d %d\n", k + 1, res);
        }
    }
}