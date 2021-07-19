#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n, h, w, tc, ans = 5000, map[16][13], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool visit[13];

typedef struct {
	int x, y;
}point;

bool safe(int x, int y) { return x >= 0 && x < w && y >= 0 && y < h; }

void gravity() {	
	queue<int> q;		//�߷� �ۿ��ϱ� ���� ���� ���� ť
	for (int j = 0; j < w; j++) {		//��� ���� ����
		if (!visit[j])continue;			//** popBlock���� üũ���� ���� ���� ��ȭ�� ���� ������ pass **
		for (int i = h - 1; i >= 0; i--) {		//�Ʒ��������� ��´�
			if (map[i][j] != 0) {		//���� �ִ� ���̶�� ť�� ��� �ش� ĭ�� �����
				q.push(map[i][j]);
				map[i][j] = 0;
			}
		}

		for (int i = h - 1; i >= 0; i--) {	//�ٽ� �Ʒ��������� �ױ�
			if (q.empty())break;
			map[i][j] = q.front(); q.pop();
		}
	}
}

int popBlock(point p) {
	int k = map[p.y][p.x], b = 1;	//k: ���� ��Ͽ� ���� ���� ����, b: ���� ��Ͽ��� �����ؼ� ������ ������ ����
	visit[p.x] = 1;					//���� �������� ����� ��ȭ�� �Ͼ��
	map[p.y][p.x] = 0;				//���� ����
	for (int i = 0; i < 4; i++) {       //4 ���⿡ ���� �˻�
		for (int j = 1; j < k; j++) {       //��Ͽ� ���� ������ ������ŭ �ٸ� ������ ���߸�
			point next = { p.x + dx[i] * j, p.y + dy[i] * j };  //���� ��ǥ
			if (!safe(next.x,next.y))break;      //������ �Ѿ�� break
			if (map[next.y][next.x] == 0)continue;     //����ִ� ���� ��� ȣ���ϸ� �ȵ�
			b += popBlock(next);         //��� ȣ�� �ϸ鼭 ���� �ۿ����� ������ ���� ���� ����
		}
	}
	return b;       //���� ���� �� ��ȯ
}

void dfs(int dep, int b) {
	if (dep == n || !b) { //n���� ������ ���� ����߸��ų� ���̻� �� ������ ���� ��
		if (b < ans)		//�ּҰ� ����
			ans = b;
		return;
	}

	int temp[16][13];	//�� ������ ����ϱ� ���� �ӽ� �迭
	memcpy(temp, map, sizeof(map));
	for (int i = 0; i < w; i++) {
		point p = { i,0 };
		while (safe(p.x, p.y) && !map[p.y][p.x])p.y++;	//���� ���� �ִ� ������ ���� �� ���� ������

		if (!safe(p.x, p.y))continue;	//���� ���� �Ѿ��ٸ�? -> �ش� ������ ������ ����
                                        //���� �� �ʿ䰡 �����ϱ� pass 

		int a = popBlock(p);			//���� ���� top�� ���� ���� ������ �� ��ȯ & ��ȭ�� �Ͼ �� üũ
		gravity();						//�߷����� ��� ���� ����
		dfs(dep + 1, b - a);

		memcpy(map, temp, sizeof(temp));	//����س��� �迭 ����
		memset(visit, false, sizeof(visit));
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d%d%d", &n, &w, &h);

		memset(map, 0, sizeof(map));
		int b = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] != 0)b++;
			}

		dfs(0,b);
		printf("#%d %d\n", t, ans);
		ans = 5000;
	}
	return 0;
}

//boom({ 2,1 });
//gravity();
//for (int i = 0; i < h; i++) {
//	for (int j = 0; j < w; j++)
//		printf("%d ", map[i][j]);
//	printf("\n");
//}
//printf("\n");
//boom({ 2,2 });
//gravity();
//for (int i = 0; i < h; i++) {
//	for (int j = 0; j < w; j++)
//		printf("%d ", map[i][j]);
//	printf("\n");
//}
//boom({ 6,8 });
//gravity();
//printf("\n");
//for (int i = 0; i < h; i++) {
//	for (int j = 0; j < w; j++)
//		printf("%d ", map[i][j]);
//	printf("\n");
//}
//#include <cstdio>
//int n, w, h, count;
//int save[13], map[13][16], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
//bool safe(int r, int c) {
//	return r >= 0 && r < h && c >= 0 && c < w;
//}
//void breakBrick(int r, int c) {
//	int range = map[r][c], count = map[r][c] ? 1 : 0;
//	map[r][c] = 0;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 1; j < range; j++)
//			if (safe(r + dy[i], c + dx[i]))
//				breakBrick(r + dy[i] * j, c + dx[i] * j);
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &w, &h);
//	for (int i = 0; i < h; i++)
//		for (int j = 0; j < w; j++)scanf("%d", &map[i][j]);
//	for (int k = 0, temp; k < n; k++) {
//		scanf("%d", &temp);
//		for(int j=0;j<h;j++)
//			if (map[j][temp - 1]) {
//				breakBrick(j, temp - 1);
//				break;
//			}
//		for (int i = 0; i < w; i++) {
//			int idx = 0;
//			for (int j = h - 1; j >= 0; j--) {
//				if (map[j][i]) {
//					save[idx++] = map[j][i];
//					map[j][i] = 0;
//				}
//			}
//			for (int j = h - 1, t = 0; t < idx; j--, t++)
//				map[j][i] = save[t];
//		}
//	}
//	for (int i = 0; i < h; i++)
//		for (int j = 0; j < w; j++)
//			if (map[i][j]) count++;
//	printf("%d\n", count);
//		return 0;
//}

//#include <cstdio>
//int n, w, h, count;
//int save[13], map[13][16], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
//bool safe(int r, int c) {
//	return r >= 0 && r < h && c >= 0 && c < w;
//}
//void breakBrick(int r, int c) {
//	int range = map[r][c], count = map[r][c] ? 1 : 0;
//	map[r][c] = 0;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 1; j < range; j++)
//			if (safe(r + dy[i], c + dx[i]))
//				breakBrick(r + dy[i] * j, c + dx[i] * j);
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &w, &h);
//	for (int i = 0; i < h; i++)
//		for (int j = 0; j < w; j++)scanf("%d", &map[i][j]);
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++)
//			printf("%d ", map[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//	for (int k = 0, temp; k < n; k++) {
//		scanf("%d", &temp);
//		for (int j = 0; j<h; j++)
//			if (map[j][temp - 1]) {
//				breakBrick(j, temp - 1);
//				break;
//			}
//		for (int i = 0; i < w; i++) {
//			int idx = 0;
//			for (int j = h - 1; j >= 0; j--) {
//				if (map[j][i]) {
//					save[idx++] = map[j][i];
//					map[j][i] = 0;
//				}
//			}
//			for (int j = h - 1, t = 0; t < idx; j--, t++)
//				map[j][i] = save[t];
//		}
//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++) {
//				if (map[i][j]) count++;
//				printf("%d ", map[i][j]);
//			}
//			printf("\n");
//		}printf("\n");
//	}
//
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			if (map[i][j]) count++;
//			printf("%d ", map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("%d\n", count);
//
//	return 0;
//}