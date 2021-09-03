package Java;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Boj20056 {

    public static void main(String[] args) throws IOException {
        //input
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        //홀수 과정에서는 map->map2로 파이어볼 이동  짝수과정에서는 반대
        ArrayList<ArrayList<Fireball>> map = new ArrayList<>(N);
        ArrayList<ArrayList<Fireball>> map2 = new ArrayList<>(N);

        //map1과 map2는 2차원 어레이 리스트이므로 for문 돌면서 2차원 요소 넣어줌
        for(int i=0; i<N; i++) {
            map.add(new ArrayList<Fireball>(N)); map2.add(new ArrayList<Fireball>(N));
            for(int j=0; j<N; j++) {
                map.get(i).add(new Fireball());	map2.get(i).add(new Fireball());
            }
        }

        //파이어볼 초기값 map1에 입력받음
        for(int i=0; i<M; i++) {
            st=new StringTokenizer(br.readLine());
            map.get((Integer.parseInt(st.nextToken()))-1).set((Integer.parseInt(st.nextToken())-1),
                new Fireball( Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()) ) );
        }//input end
        Queue<Fireball> q=new LinkedList<>();




        //process
        //이차원 어레이리스트에는 Fireball 객체가 담겨져있는데, Fireball에는 파이어볼 기본정보(질량 무게 방향), stack(중첩수)가 저장되어있다.

        //문제에서는 파이어볼을 이동 후 , 중첩된 것이 있으면 분할해 주는데 이 코드에서는 파이어볼을 이동만 한 후 중첩되는 것은 다음 이동에서 처리한다.
        //이러면 마지막 수행 이후 중첩되는 파이어볼이 처리되지 않은 상태로 있기 때문에, 질량을 세줄때 중첩되어있는것은 질량을 5로 나눈 후 4를 곱해서 처리해준다.



        //t는 시행횟수
        for(int t=0; t<K; t++) {
            //시행이 짝수,홀수번째이냐에 따라서 map->map2로 map2->map으로 이동
            if(t%2 == 0)	excuteSpell(map, map2);
            else	excuteSpell(map2, map);
        }
        int totalWeight=0;
        if(K%2==0) {totalWeight=calTotalWeight(map);}
        else {totalWeight=calTotalWeight(map2);}

        System.out.println(totalWeight);
    }



    //모든 이동 및 분열이 끝난 후 정답 출력을 위해 질략을 계산하는 함수. 마지막 분열된것은 처리되지 않았기 때문에 stack이 2이상인 경우 분열된 무게로 계산해준다.
    private static int calTotalWeight(ArrayList<ArrayList<Fireball>> map) {
        int totalWeight = 0;

        for (int i = 0; i < map.size(); i++) for (int j = 0; j < map.get(i).size(); j++) {
            Fireball fb = map.get(i).get(j);
            if(fb.stack == 0)	continue;
            else if(fb.stack == 1)	totalWeight+=fb.m;
            else    totalWeight += (int)(fb.m/5)*4;
        }

        return totalWeight;
    }


    //처음에 중복되는 경우를 따로 처리하기 위해 moveFireball()과 checkOverrap()을 돌리기 위해 만든 함수인데 moveFireball()에서 두 경우를 다 체크해주는걸로 변경해서 나중에 삭제할 함수
    private static void excuteSpell(ArrayList<ArrayList<Fireball>> map, ArrayList<ArrayList<Fireball>> map2) {


        for(int i=0; i<map.size(); i++)	for(int j=0; j<map.get(i).size(); j++) {
            Fireball fb=map.get(i).get(j);
            if(fb.stack==0) continue;


            //map의 파이어볼을 꺼내서  map2에 속성값을 더해주는 펑션
            moveFireball(i,j, map, map2);
        }
    }


    //이차원 어레이리스트를 순회하면서, stack이 1인경우 그냥 옮겨주고 stack이 2인경우 분할해서 옮겨준다.
    private static void moveFireball(int r, int c, ArrayList<ArrayList<Fireball>> map, ArrayList<ArrayList<Fireball>> map2) {
        int[] dr = {-1, -1, 0, 1, 1, 1, 0, -1};
        int[] dc = {0, 1, 1, 1, 0, -1, -1, -1};

        int N=map.size();
        //옮길 파이어볼 Ctrl+X
        Fireball fb = map.get(r).get(c);	//옮길 파이어볼 객체 복사
        map.get(r).set(c, new Fireball());	//원복 파이어볼 빈 파이어볼 덮어쓰기


        if(fb.stack == 1) {	//옮길 파이어볼이 낱개일 경우
            r+=(dr[fb.d]*(fb.s%N)+N);	r%=N;
            c+=(dc[fb.d]*(fb.s%N)+N);	c%=N;

            //map2의 옮길 위치 파이어볼 += (질량, 속력, 방향일치 체크)
            Fireball fb2 = map2.get(r).get(c);
            //방향 체크
            if(fb2.isAllEvenOdd && fb2.stack>=1 && fb2.d%2 != fb.d%2) fb2.isAllEvenOdd=false;

            fb2.m+=fb.m;
            fb2.s+=fb.s;
            fb2.stack+=1;
            fb2.d=fb.d;

            map2.get(r).set(c, fb2);
        }else {	//옮길 파이어볼이 중첩되어 있는 경우
            int nr=0, nc=0;

            fb.m /= 5;
            fb.s /= fb.stack;

            if(fb.m == 0) return;


            for(int d=fb.isAllEvenOdd?0:1; d<8; d+=2) {
                nr=r+(dr[d]*(fb.s%N)+N);	nr%=N;
                nc=c+(dc[d]*(fb.s%N)+N);	nc%=N;

                Fireball fb2 = map2.get(nr).get(nc);
                if(fb2.isAllEvenOdd && fb2.stack>=1 && fb2.d%2 != fb.d%2) fb2.isAllEvenOdd=false;
                fb2.m+=fb.m;	fb2.s+=fb.s;	fb2.stack+=1;
                fb2.d=d;
                map2.get(nr).set(nc, fb2);
            }
        }

    }

    static class Fireball{
        int m,s,d, stack;
        boolean isAllEvenOdd;

        public Fireball() {
            super();
            this.m = 0;
            this.s = 0;
            this.d = 0;
            this.stack = 0;
            this.isAllEvenOdd = true;
        }

        public Fireball(int m, int s, int d) {
            super();
            this.m = m;
            this.s = s;
            this.d = d;
            this.stack = 1;
            this.isAllEvenOdd = true;
        }

    }

}