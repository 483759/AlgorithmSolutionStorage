//�κ�û�ұ�
#include <cstdio>
int n, m, dx[] = { 0, 1,0,-1 }, dy[] = { -1,0,1,0 }, r, c, d, ans;
int visit[51][51];
int main() {
	freopen("input.txt", "r", stdin);


	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &r, &c, &d);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &visit[i][j]);
	while (1) {	//��� �ݺ�
		int k = 0;
		if(!visit[r][c])ans++;	
		//���� û�Ҹ� ���޴ٸ� ans ����(û���Ұ� ��� ���������� ����ó��)
		visit[r][c] = 2;	//û���޴ٰ����ݴϴ�
		
		for (int i = (d + 3) % 4; k < 4; i = (i + 3) % 4, k++) {
			if (!visit[r + dy[i]][c + dx[i]]) {	//û���� �� ������?
				r += dy[i]; c += dx[i];	//�̵��Ѵ�
				d = i;
				break;
			}
		}
		if (k == 4) {	//�� ���� ���� üũ�ߴٸ�(û���� ���� ���ٸ�)
			if (visit[r + dy[(d + 2) % 4]][c + dx[(d + 2) % 4]] != 1) {
				//���� �ƴ϶�� ����
				r += dy[(d + 2) % 4]; c += dx[(d + 2) % 4];
			}
			else {	//�׹��� û�� ���޴µ� �ڰ� ���̸� ��
				printf("%d", ans);
				return 0;
			}
		}
	}
	return 0;
}