#include <iostream>
#include <algorithm>
#include <vector>
#define pi pair<point,point>		//��缱�� ���� ��(���� �Ʒ�), �� ��(������ ��)�� �����ϴ� �ڷᱸ��
#define fi first
#define se second
using namespace std;

typedef struct { int x, y; }point;
int n, k, m;

bool contain(pi a, pi b) {		//a������ b������ �����ϴ��� �˻��ϴ� �޼ҵ�
	return (a.first.x <= b.first.x)
		&& (a.first.y <= b.first.y)
		&& (a.second.x >= b.second.x)
		&& (a.second.y >= b.second.y);
}

int main() {
	int test_case;
	int T;
	std::ios::sync_with_stdio(false);
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		point MIN = { 305,305 }, MAX = { 0,0 };	//�˻��� ������ ������ �ּ�, �ִ� ��ǥ ����
		vector<pi> v;							//������ �������� ������ ����
		int mw = 987654321, ans = 987654321;	//mw: ��缱�� ������ �ּ� mw �̻��̾�� ��, ans: ������ m���Ϸ� ���� �� �ִ� ��缱�� �ּ� ũ��


		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			pi p;
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			p.fi.x = min(x1, x2);
			p.fi.y = min(y1, y2);
			p.se.x = max(x1, x2);
			p.se.y = max(y1, y2);

			MIN.x = min(p.fi.x, MIN.x);
			MIN.y = min(p.fi.y, MIN.y);
			MAX.x = max(p.se.x, MAX.x);
			MAX.y = max(p.se.y, MAX.y);
			//��ǥ ������ ���� ���� Ȥ�� ������ �ٸ��� ���� �� �ֱ� ������ (���� �Ʒ�, ������ ��)�� ���·� ���� ������ ����

			mw = min(max(p.se.x - p.fi.x, p.se.y - p.fi.y), mw);	//������ �ּ� ũ�� ����

			v.push_back(p);
		}

		int left = mw, right = max(MAX.x, MAX.y);	//��缱�� ��ġ�� �����ϴ� �κ��� �ʹ� ���� �ɸ� �� ���Ƽ�
													//��缱�� ũ��� �̺� Ž������ �����߽��ϴ�(�ִ� 300 -> �ݺ� Ƚ�� 10ȸ ���Ϸ� ����)
		while (left <= right) {
			int k = (left + right) / 2;				//���� �׽�Ʈ�غ� ��缱�� ����

			int MAX_Y = max(MAX.y - k, MAX.y);		//��缱�� Ž�� �ִ� ��ġ�� ����
			int MAX_X = max(MAX.x - k, MAX.x);

			int sub = -1;
			bool B = false;
			for (int i = MIN.y; i <= MAX_Y; i++) {
				for (int j = MIN.x; j <= MAX_X; j++) {		//��缱�� ���� ��ġ Ž��
					if (B)break;	//���� ������ m�� ���Ϸ� ���� �� �ִ� ��ġ�� �߰��ߴٸ� ���̻� �ݺ����� �ʴ´�
					int count = 0;
					pi cur;
					cur.fi.x = j;
					cur.fi.y = i;
					cur.se.x = j + k;
					cur.se.y = i + k;		//���� ��缱�� ���� �� ���� ��ǥ�� ����

					for (int i = 0; i < v.size(); i++) {	//��� ���翡 ���� ��缱�� ������ �����ϰ� �ִ��� ī��Ʈ
						if (contain(cur, v[i]))count++;
					}

					if (v.size() - count <= m) {	//������ m�� ���Ϸ� �ٿ��ٸ�
						sub = k;
						if (k < ans)ans = k;	//ans�� �ּҰ� ����
						B = true;
						break;
					}
				}
			}

			if (B) {	//���� �������� ��� ������ Ŀ���߾ �� ���� k���� ���� �� �ֱ� ������ Ž�� ũ�⸦ �����ش�
				right = k - 1;
			}
			else {		//���� �������� ��� ������ Ŀ���� �� ���ٸ� ������ �÷����ϱ� ������ Ž�� ũ�⸦ �÷��ش�
				left = k + 1;
			}
		}

		cout << "#" << test_case << ' ' << ans << '\n';
	}

	return 0;
}