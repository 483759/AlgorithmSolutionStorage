#include <stdio.h>
#define MAXN	13
#define MAXK	11

int x[MAXK];		//��
int y[MAXK];		//��
int d[MAXK];		//����
int up[MAXK];		//���� ����?
int down[MAXK];		//�Ʒ� ����?
int a[MAXN][MAXN];	//ü���� ����
int p[MAXN][MAXN];	//� ���� ���� �ؿ� �ִ���

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

	int cnt = 1;	//�� �ڽ� count
	int nx = x[t] + dx[d[t]];
	int ny = y[t] + dy[d[t]];

	//�Ķ����� ��� orü������ ����� ���
	if (nx <= 0 || nx > n || ny <= 0 || ny > n || a[nx][ny] == 2) {
		if (b) {
			//������ �ݴ�� �� �Ŀ� �̵��Ϸ��� ĭ�� �Ķ����� ��쿡�� �̵����� �ʰ� ���⸸ �ݴ�� �ٲ۴�.
			d[t] = rd[d[t]];
			return false;
		}
		d[t] = rd[d[t]];
		return go(t, 1);
	}

	//�ϴ� �����δ�.
	if (!down[t])  p[x[t]][y[t]] = 0;		//���� ���̾����� �����ڸ� �����. �ƴϸ� ����� �ȵȴ�.
	x[t] = nx;
	y[t] = ny;
	up[down[t]] = 0;		//�ؿ� �ִ� ���� ���� ������
	down[t] = 0;			//�ϴ� �̵��Ŀ� �ؿ� �ƹ��� ���°ɷ� ��� (���Ŀ� �ٸ� �� ���� �״� ��쿡 ���ŵ�)

							//���� ���� �ٸ� ���� �ִ� ��쿡�� A�� ���� ���� �ִ� ��� ���� �̵��Ѵ�.
	int top = t;
	while (up[top]) {
		++cnt;
		top = up[top];
		x[top] = nx;
		y[top] = ny;
	}
	//�������� ��쿡�� 
	if (a[nx][ny] == 1) {
		//�̵��� �Ŀ� ��� ���� �׿��ִ� ������ �ݴ�� �ٲ۴�
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

	//�̵��Ϸ��� ĭ�� ���� �̹� �ִ� ��쿡�� ���� ���� ���� �÷����´�.
	int &next = p[nx][ny];

	//���� ã��
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
		scanf("%d %d %d", &x[i], &y[i], &d[i]);	//���� ����ִ���
		p[x[i]][y[i]] = i;					//��ǥ�� �����ִ���
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