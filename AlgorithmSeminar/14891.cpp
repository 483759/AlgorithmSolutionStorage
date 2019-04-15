#include <stdio.h>
bool gear[4][8], visit[4], graph[4][4] = { 0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0 };
int idx[4], n, k, r, ans;
bool isSame(int next, int cur) {
	if (next < cur)
		return gear[next][(idx[next] + 2) % 8] == gear[cur][(idx[cur] + 6) % 8];
	else
		return gear[next][(idx[next] + 6) % 8] == gear[cur][(idx[cur] + 2) % 8];
}
void dfs(int cur, int rot) {
	visit[cur] = true;
	for (int next = 0; next < 4; next++)
		if (!isSame(next, cur) && !visit[next] && graph[cur][next])
			dfs(next, rot*(-1));
	//맞닿은 면이 다르다면 재귀 dfs(회전방향은 반대로!!)
	idx[cur] = (idx[cur] - rot + 8) % 8;	//톱니바퀴를 돌린다(판정 후 돌리는게 중요)
}
int main() {
	freopen("input.txt", "r", stdin);
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 8; i++)
			scanf("%1d", &gear[j][i]);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < 4; i++)visit[i] = 0;
		scanf("%d%d", &k, &r);
		dfs(k - 1, r);	//dfs돌린다
	}
	for (int i = 0, k = 1; i < 4; i++) {
		ans += gear[i][idx[i]] * k;
		k <<= 1;
	}	//점수계산
	printf("%d", ans);
	return 0;
}