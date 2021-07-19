//#include <cstdio>
//#include <iostream>
//#include <queue>
//using namespace std;
//bool visit[100];
//int N, graph[100][100];
//queue<int> q;
//void bfs(int node) {
//	visit[node] = true;	//���� ��带 �湮ó��
//	q.push(node);	//ť�� ���� ��带 push
//	while (!q.empty()) {	//��� ��带 ��ȸ�� �� ����
//		int cur = q.front(); q.pop();	//ť�� �� �տ� �ִ� ��带 pop
//		printf("%d ", cur);
//		for(int next=0;next<N;next++)
//			if (graph[cur][next] && !visit[next]) {	//cur�� ���� ����Ǿ� �ְ� �湮�� ���� ���ٸ�
//				visit[next] = true;	//�� ��带 �湮ó��
//				q.push(next);	//ť�� push
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
//	while (!st.empty()) {	//��� ��� ��ȸ�� ������
//		int cur = st.top(); st.pop();	//������ �� ���� �ִ� ��带 pop�ϰ�
//		printf("%d", cur);
//		if (visit[cur]) continue;	//�� ��带 �湮�� ���� ���ٸ�
//		visit[cur] = true;	//visit�迭�� �湮 üũ
//		for (int next = 0; next < N; next++) {
//			if (!visit[next] && graph[cur][next])	//�湮�� ���� ����, ���� ���� ����Ǿ� �ִٸ�
//				st.push(next);	//���ÿ� push
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
	while (!q.empty()) {	//����� ��� ��带 ��ȸ�� �� ����
		p cur = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = cur.x + dx[i], ty = cur.y + dy[i];	//�� ���� ��� �˻�
			if (safe(tx, ty) && !m[ty][tx] && !v[ty][tx]) {	//�̵��� �� �ִ� ��ġ�̰� �� ���� �丶���̰� �湮�� ���� ���ٸ�
				zero--;	//������ �丶�� ���� ����
				v[ty][tx] = v[cur.y][cur.x] + 1;	//visit �迭�� �� �Ͽ� �湮�ߴ��� üũ
				mx = mx < v[ty][tx] ? v[ty][tx] : mx;	//�ִ� �� �� ����
				q.push({ tx, ty });	//ť�� push
			}
		}
	}
}

int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &m[i][j]);	//�丶���� ���� �Է¹ޱ�
			if (m[i][j] == 1) {	//���� �丶�䰡 ������
				q.push({ j, i });	//q�� �ε��� ����
				v[i][j] = 1;	//�湮ó��
			}
			if (!m[i][j])	//������ �丶���� ���� ī��Ʈ
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