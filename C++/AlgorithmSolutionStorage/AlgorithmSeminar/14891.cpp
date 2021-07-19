#include <cstdio>
int gear[1005][8],idx[1005];
int dx[] = { 1,-1 },t;
bool differ(int a, int b) {	//d==1�̸� �ݽð�, d==-1�̸� �ð�
	if (a<b) {
		return gear[a][(idx[a] + 2) % 8] != gear[b][(idx[b] + 6) % 8];
	}else return gear[a][(idx[a] + 6) % 8] != gear[b][(idx[b] + 2) % 8];
}
void func(int num, int dir,int pre) {
	for (int i = 0; i < 2; i++) {
		int next = num + dx[i];
		if (next < 0 || next>=t || next == pre)continue;
		if (differ(num, next))
			func(next, dir * (-1), num);			
	}

	idx[num] = (idx[num] + dir + 8) % 8;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &gear[i][j]);

	int k,g,d;
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &g, &d);
		func(g-1, d*(-1),-1);
	}
	int ans = 0;
	for (int i = 0; i < t; i++)
		if (gear[i][idx[i]])ans++;

	printf("%d", ans);
}




























//#include <stdio.h>
//bool gear[4][8], visit[4], graph[4][4] = { 0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0 };
//int idx[4], n, k, r, ans;
//bool isSame(int next, int cur) {
//	if (next < cur)
//		return gear[next][(idx[next] + 2) % 8] == gear[cur][(idx[cur] + 6) % 8];
//	else
//		return gear[next][(idx[next] + 6) % 8] == gear[cur][(idx[cur] + 2) % 8];
//}
//void dfs(int cur, int rot) {
//	visit[cur] = true;
//	for (int next = 0; next < 4; next++)
//		if (!isSame(next, cur) && !visit[next] && graph[cur][next])
//			dfs(next, rot*(-1));
//	//�´��� ���� �ٸ��ٸ� ��� dfs(ȸ�������� �ݴ��!!)
//	idx[cur] = (idx[cur] - rot + 8) % 8;	//��Ϲ����� ������(���� �� �����°� �߿�)
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	for (int j = 0; j < 4; j++) {
//		for (int i = 0; i < 8; i++)
//			scanf("%1d", &gear[j][i]);
//	}
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		for (int i = 0; i < 4; i++)visit[i] = 0;
//		scanf("%d%d", &k, &r);
//		dfs(k - 1, r);	//dfs������
//	}
//	for (int i = 0, k = 1; i < 4; i++) {
//		ans += gear[i][idx[i]] * k;
//		k <<= 1;
//	}	//�������
//	printf("%d", ans);
//	return 0;
//}