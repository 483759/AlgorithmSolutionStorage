import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Boj5719 {
	
	// 아무리 거리가 길어도 최대 노드수(500) x 최대 거리(1000) + 1은 넘지 않아 무한을 500001로 정함!
	static final int INF = 1000 * 500 + 1;
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	// N : 노드의 수, M : 간선의 수, S : 출발점, D : 목적지, minDist : 최단거리 배열, adjMatrix : 인접 행렬
	static int N, M, S, D, minDist[], adjMatrix[][];
	// prev : 해당 인덱스의 노드로 오는 최단 경로에서 이 노드에 도달하기 바로 전 노드들의 리스트
	static List<Integer> prev[];
	
	// main 메서드 시작
	public static void main(String[] args) throws Exception {
		while(true) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			// N과 M이 0이면 테케 종료! (입력 조건임)
			if(N == 0 && M == 0) {
				break;
			}
			// 현재 테케의 입력 받는 메서드 실행
			input();
			// 현재 테케에 대해 문제를 푸는 메서드 실행
			solve();
		}
		System.out.println(sb);
	} // main 메서드 종료

	private static void solve() {
		// 먼저 다익스트라를 돌림
		dijkstra();
		// 그 다음 최단경로에 포함되는 모든 경로를 없애버림
		setZero(D);
		// 다시 다익스트라를 돌림
		dijkstra();
		// D에 도달할 수 없다면 -1 출력
		if(minDist[D] == INF) {
			sb.append(-1);
		// 도달 가능하면 최단경로 출력
		} else {
			sb.append(minDist[D]);
		}
		sb.append("\n");
	}

	// 최단경로에 포함되는 경로를 모두 지우는 (재귀) 메서드
	private static void setZero(int d) {
		// 현재 노드(d)의 이전 노드(p)에서 현재 노드로 오는 간선을 없애버림
		// 그리고 setZero(p)를 호출하며 최단경로를 다 지우는 방식임!
		for (int i = 0, len = prev[d].size(); i < len; i++) {
			int p = prev[d].get(i);
			adjMatrix[p][d] = 0;
			setZero(p);
		}
	}

	private static void dijkstra() {
		PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> (o1[1] - o2[1]));
		for (int i = 0; i < N; i++) {
			minDist[i] = INF;
		}
		minDist[S] = 0;
		pq.offer(new int[] {S, 0});
    int[] arr=new int[] {S,0};
    System.out.println(arr);
		
		while(!pq.isEmpty()) {
			int[] cur = pq.poll();
			int curNode = cur[0], curDist = cur[1];
			if(minDist[curNode] < curDist) {
				continue;
			}
			int[] adjNodes = adjMatrix[curNode];
			for (int i = 0; i < N; i++) {
				int nextDist = curDist + adjNodes[i];
				
				/** 
				 * nextDist == curDist 라는 것은 adjNodes[i] 가 0임을 뜻함
				 * adjNodes[i]가 0이면 내가 입력한 방식에서는
				 * curNode에서 i로 이동하는 간선이 없다는 뜻!
				 */
				if(nextDist == curDist || minDist[i] < nextDist) {
					continue;
				}
				// nextDist가 최단경로라면, 이전 노드 리스트를 초기화 해야함!
				if(minDist[i] > nextDist) {
					prev[i].clear();
				} 
				pq.offer(new int[] {i, nextDist});
				minDist[i] = nextDist;
				// nextDist가 최단경로이거나, 현재까지 최단경로와 같다면 이전 노드 리스트에 curNode를 추가함
				prev[i].add(curNode);
			}
		}
	}

	private static void input() throws Exception {
		st = new StringTokenizer(br.readLine());
		S = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		
		adjMatrix = new int[N][N];
		minDist = new int[N];
		prev = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			prev[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int dist = Integer.parseInt(st.nextToken());
			adjMatrix[from][to] = dist;
		}
	}
}