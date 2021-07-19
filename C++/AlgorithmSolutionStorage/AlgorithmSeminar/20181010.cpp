//#include <cstdio>
//#include <iostream>
//#include <queue>
//using namespace std;
//bool visit[100];
//int N, graph[100][100];
//queue<int> q;
//void bfs(int node) {
//	visit[node] = true;	//현재 노드를 방문처리
//	q.push(node);	//큐에 현재 노드를 push
//	while (!q.empty()) {	//모든 노드를 순회할 때 까지
//		int cur = q.front(); q.pop();	//큐의 맨 앞에 있는 노드를 pop
//		printf("%d ", cur);
//		for(int next=0;next<N;next++)
//			if (graph[cur][next] && !visit[next]) {	//cur의 노드와 연결되어 있고 방문한 적이 없다면
//				visit[next] = true;	//그 노드를 방문처리
//				q.push(next);	//큐에 push
//			}
//	}
//}
//void bfs2(int cur) {
//	visit[cur] = true;
//	printf("%d ", cur);
//	for (int next = 0; next < N; next++) {
//		if (graph[cur][next] && !visit[next])
//			bfs2(next);
//	}
//}

//#include <cstdio>
//#include <iostream>
//#include <stack>
//using namespace std;
//bool visit[100];
//int N, graph[100][100];
//stack<int> st;
//void dfs(int node) {
//	st.push(node);
//	while (!st.empty()) {	//모든 노드 순회할 때까지
//		int cur = st.top(); st.pop();	//스택의 맨 위에 있는 노드를 pop하고
//		printf("%d", cur);
//		if (visit[cur]) continue;	//그 노드를 방문한 적이 없다면
//		visit[cur] = true;	//visit배열에 방문 체크
//		for (int next = 0; next < N; next++) {
//			if (!visit[next] && graph[cur][next])	//방문한 적이 없고, 현재 노드와 연결되어 있다면
//				st.push(next);	//스택에 push
//		}
//	}
//}
//void dfs2(int cur) {
//	visit[cur] = true;
//	for (int next = 0; next < N; next++)
//		if (!visit[next] && graph[cur][next])
//			dfs(next);
//}
//int main() {
//	int i, j;
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d %d", &i, &j) != EOF;
//		graph[i][j] = 1;
//		graph[j][i] = 1;
//	}
//	//dfs(0);
//	//bfs2(0);
//}

#include <cstdio>
#include <queue>
using namespace std;

struct p { int x, y; };
int m[1001][1001], v[1001][1001], dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int N, M, mx=1, zero;
queue<p> q;

bool safe(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}
void bfs() {
	while (!q.empty()) {	//연결된 모든 노드를 순회할 때 까지
		p cur = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = cur.x + dx[i], ty = cur.y + dy[i];	//네 방향 모두 검색
			if (safe(tx, ty) && !m[ty][tx] && !v[ty][tx]) {	//이동할 수 있는 위치이고 안 익은 토마토이고 방문한 적이 없다면
				zero--;	//안익은 토마토 개수 감소
				v[ty][tx] = v[cur.y][cur.x] + 1;	//visit 배열에 몇 일에 방문했는지 체크
				mx = mx < v[ty][tx] ? v[ty][tx] : mx;	//최대 일 수 저장
				q.push({ tx, ty });	//큐에 push
			}
		}
	}
}

int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &m[i][j]);	//토마토의 상태 입력받기
			if (m[i][j] == 1) {	//익은 토마토가 있으면
				q.push({ j, i });	//q에 인덱스 저장
				v[i][j] = 1;	//방문처리
			}
			if (!m[i][j])	//안익은 토마토의 개수 카운트
				zero++;
		}
	bfs();
	if (zero)printf("-1");
	else printf("%d", mx - 1);
	return 0;
}

//#include <cstdio>
//#include <queue>
//#include <vector>
//using namespace std;
//
//vector<int> graph[1001];
//bool visit[1001];
//int N, M;
//
//void bfs(int n) {
//	queue<int> q;
//	visit[n] = true;
//	q.push(n);
//	while (!q.empty()) {
//		int t = q.front(); q.pop();
//		for (int a : graph[t]) {
//			if (visit[a])continue;
//			visit[a] = true;
//			q.push(a);
//		}
//	}
//}
//
//int main() {
//	int cnt = 0;
//	scanf("%d%d", &N, &M);
//
//	for (int i = 0, from, to; i < M; i++) {
//		scanf("%d%d", &from, &to);
//		graph[from].push_back(to);
//		graph[to].push_back(from);
//	}
//	for (int i = 1; i <= N; i++) {
//		if (!visit[i]) {
//			bfs(i);
//			cnt++;
//		}
//	}
//	printf("%d", cnt);
//
//	return 0;
//}