#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, tc, m, k, a, b, ans, time;
typedef struct {
	int t, rcp, mtn;
}user;
typedef struct {
	int num, tr;
}desk;
queue<int> wr, wm;
vector<user> v;
desk receive[10], maintain[10];
int tr[10], tm[10];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		time=ans = 0; int fin = 0;
		scanf("%d%d%d%d%d", &n, &m, &k, &a, &b);
		for (int i = 1; i <= n; i++)
			scanf("%d", &tr[i]);
		for (int i = 1; i <= m; i++)
			scanf("%d", &tm[i]);

		v.push_back({ 0,0,0 });
		for (int i = 1; i <= k; i++) {
			int tt;
			scanf("%d", &tt);
			v.push_back({ tt,0,0 });
			wr.push(i);
		}	//�������ť

		while (fin < k) {	//��� �� ����������

			for (int i = 1; i <= n; i++) {	//���� â�� ó��
				if (receive[i].num && !receive[i].tr) {
					wm.push(receive[i].num);	//���� ���ť
					receive[i] = { 0,0 };	//â�� �ʱ�ȭ
				}
			}
			for (int i = 1; i <= m; i++) {
				if (maintain[i].num && !maintain[i].tr) {
					maintain[i] = { 0,0 };
					fin++;
				}
			}

			while (!wr.empty() && v[wr.front()].t <= time) {
				int i;
				for (i = 1; i <= n; i++) {	//���� â����
					if (!receive[i].num) {
						receive[i] = { wr.front(),tr[i] };	//����â�� �ʱ�ȭ
						v[wr.front()].rcp = i;
						wr.pop();	//��
						break;
					}
				}
				if (i > n)break;
			}
			while (!wm.empty() && v[wm.front()].t <= time) {
				int i;
				for (i = 1; i <= m; i++) {
					if (!maintain[i].num) {
						maintain[i] = { wm.front(),tm[i] };
						v[wm.front()].mtn = i;
						wm.pop();
						break;
					}
				}
				if (i > m)break;
			}

			for (int i = 1; i <= n; i++)
				if (receive[i].num)
					receive[i].tr--;
			for (int i = 1; i <= m; i++)
				if (maintain[i].num)
					maintain[i].tr--;
			time++;
		}

		for (int i = 1; i <= k; i++)
			if (v[i].rcp == a && v[i].mtn == b)ans += i;
		printf("#%d %d\n", T, ans?ans:-1);
		v.clear();
	}
	return 0;
}