#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string s;
vector<char> v;
int main() {
	cin >> s;
	for (char c : s)    //������ ���ĺ����� ������� vector�� push
		v.push_back(c);
	for (int i = 0; i < 26; i++)
		if (s.find('a' + i) >= s.length()) {    //���ĺ��� ó������ ��ȸ�ϸ鼭 s�� ���Ե��� �ʴ� ���ĺ����� Ž��
			v.push_back('a' + i);    //vector�� �� �ڿ� �߰�
		}
	if (s.length() < 26) {    //���ڿ��� ���̰� 26���� ���� ���
		for (int i = 0; i <= s.length(); i++)    //������ s�� ���� + 1��ŭ vector���� ���� ���
			cout << v[i];
		cout << '\n';
	}
	else if (s == "zyxwvutsrqponmlkjihgfedcba")    //������ �ܾ�
		cout << -1 << '\n';
	else {
		next_permutation(v.begin(), v.end());    //vector���� ���� ������ ���Ѵ�
		for (int i = 0; i < s.length(); i++) {    //������ ���ڿ��� �޶��� ������ ���� �� ���� ���
			cout << v[i];
			if (v[i] != s[i])break;	//��� �� ����
		}
		cout << '\n';
	}
}
//#include <cstdio>
//#include <queue>
//using namespace std;
//typedef struct { int w,x, y,d; }point;
//int n, m, k;
//int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//bool map[1001][1001], visit[11][1001][1001];
//queue<point> q;
//bool safe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }
//int bfs() {
//	visit[0][0][0] = 1;
//	q.push({ 0,0,0,1 });
//	while (!q.empty()) {
//		point cur = q.front(); q.pop();
//		if (cur.x == m - 1 && cur.y == n - 1)return cur.d;
//
//		for (int i = 0; i < 4; i++) {
//			int nx = cur.x + dx[i], ny = cur.y + dy[i];
//			
//			if (!safe(nx, ny))continue;
//
//			if (map[ny][nx]) {
//				if (cur.w >= k|| visit[cur.w + 1][ny][nx])continue;
//				visit[cur.w + 1][ny][nx] = 1;
//				q.push({ cur.w + 1,nx,ny,cur.d+1 });
//			}
//			else {
//				if (visit[cur.w][ny][nx])continue;
//				visit[cur.w][ny][nx] = 1;
//				q.push({ cur.w,nx,ny,cur.d + 1 });
//			}
//		}
//	}
//	return -1;
//}
//int main() {
//	scanf("%d%d%d", &n, &m, &k);
//	for(int i=0;i<n;i++)
//		for (int j = 0,a; j < m; j++) {
//			scanf("%1d", &a);
//			if (a)map[i][j] = 1;
//			else map[i][j] = 0;
//		}
//	printf("%d", bfs());
//	return 0;
//}