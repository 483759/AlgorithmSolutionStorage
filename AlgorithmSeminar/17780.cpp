#include <stdio.h>
#define MAXN	13
#define MAXK	11

int x[MAXK];		//행
int y[MAXK];		//열
int d[MAXK];		//방향
int up[MAXK];		//위에 누구?
int down[MAXK];		//아래 누구?
int a[MAXN][MAXN];	//체스판 정보
int p[MAXN][MAXN];	//어떤 말이 가장 밑에 있는지

int n, k;
int dx[] = { 0, 0,0,-1,1 };
int dy[] = { 0, 1,-1,0,0 };
int rd[] = { 0,2,1,4,3 };

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

bool go(int t, int b) {

	int cnt = 1;	//나 자신 count
	int nx = x[t] + dx[d[t]];
	int ny = y[t] + dy[d[t]];

	//파란색인 경우 or체스판을 벗어나는 경우
	if (nx <= 0 || nx > n || ny <= 0 || ny > n || a[nx][ny] == 2) {
		if (b) {
			//방향을 반대로 한 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 방향만 반대로 바꾼다.
			d[t] = rd[d[t]];
			return false;
		}
		d[t] = rd[d[t]];
		return go(t, 1);
	}

	//일단 움직인다.
	if (!down[t])  p[x[t]][y[t]] = 0;		//가장 밑이었으면 원래자리 지운다. 아니면 지우면 안된다.
	x[t] = nx;
	y[t] = ny;
	up[down[t]] = 0;		//밑에 있던 말의 위는 없어짐
	down[t] = 0;			//일단 이동후에 밑에 아무도 없는걸로 취급 (추후에 다른 말 위에 쌓는 경우에 갱신됨)

							//말의 위에 다른 말이 있는 경우에는 A번 말과 위에 있는 모든 말이 이동한다.
	int top = t;
	while (up[top]) {
		++cnt;
		top = up[top];
		x[top] = nx;
		y[top] = ny;
	}
	//빨간색인 경우에는 
	if (a[nx][ny] == 1) {
		//이동한 후에 모든 말의 쌓여있는 순서를 반대로 바꾼다
		int next = t;
		while (next) {
			swap(up[next], down[next]);
			if (down[next] == 0) {
				t = next;
				break;
			}
			next = down[next];
		}

	}

	//이동하려는 칸에 말이 이미 있는 경우에는 가장 위에 말을 올려놓는다.
	int &next = p[nx][ny];

	//맨위 찾기
	if (next) {
		++cnt;
		if (cnt == 4) return true;
		top = p[nx][ny];
		while (up[top]) {
			top = up[top];
			++cnt;
			if (cnt == 4) return true;
		}
		up[top] = t;
		down[t] = top;
	}
	else {
		next = t;
	}

	return false;
}
int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= k; ++i) {
		scanf("%d %d %d", &x[i], &y[i], &d[i]);	//말이 어디있는지
		p[x[i]][y[i]] = i;					//좌표에 누가있는지
	}
	int ans = 1;
	bool flag;
	while (1) {
		for (int i = 1; i <= k; ++i) {
			if (flag = go(i, 0)) break;
		}
		if (flag) break;
		++ans;
		if (ans > 1000) {
			ans = -1;
			break;
		}
	}
	printf("%d", ans);
	return 0;
}
/*
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int n, k, map[14][14], ans, dx[] = { 0,1,-1,0,0 }, dy[] = { 0,0,0,-1,1 };
struct piece { int r, c, d; };
piece p[11];
vector<int> v[14][14];
stack<int> s;
queue<int> q;
bool safe(int r, int c) {
	return r > 0 && r <= n && c > 0 && c <= n;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &p[i].r, &p[i].c, &p[i].d);
		v[p[i].r][p[i].c].push_back(i);
	}
	while (++ans<1000) {
		for (int i = 1, idx; i <= k; i++) {
			vector<int>& cur = v[p[i].r][p[i].c];
			piece t = { p[i].r + dy[p[i].d],p[i].c + dx[p[i].d],p[i].d };
			if (!safe(t.r, t.c) || map[t.r][t.c] == 2) {
				if (p[i].d % 2)p[i].d++;
				else p[i].d--;
				t = { p[i].r + dy[p[i].d],p[i].c + dx[p[i].d],p[i].d };
				if (!safe(t.r, t.c) || map[t.r][t.c] == 2)continue;
				i--;
			}
			else if (map[t.r][t.c]) {
				for (idx = 0; cur[idx] != i; idx++);
				for (int j = idx; j < cur.size(); j++)s.push(cur[j]);
				while (cur.size() > idx)cur.pop_back();
				while (!s.empty()) {
					v[t.r][t.c].push_back(s.top());
					p[s.top()] = { t.r,t.c,p[s.top()].d };
					s.pop();
				}
			}
			else {
				for (idx = 0; cur[idx] != i; idx++);
				for (int j = idx; j < cur.size(); j++)q.push(cur[j]);
				while (cur.size() > idx)cur.pop_back();
				while (!q.empty()) {
					v[t.r][t.c].push_back(q.front());
					p[q.front()] = { t.r,t.c,p[q.front()].d };
					q.pop();
				}
			}
			if (v[t.r][t.c].size() >= 4) {
				printf("%d", ans);
				return 0;
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (v[i][j].size() >= 4) {
					printf("%d", ans);
					return 0;
				}
	}
	printf("-1");
	return 0;
}
*/