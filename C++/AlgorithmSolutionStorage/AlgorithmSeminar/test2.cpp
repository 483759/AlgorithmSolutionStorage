#include <iostream>
#include <algorithm>
#include <vector>
#define pi pair<point,point>		//방사선의 시작 점(왼쪽 아래), 끝 점(오른쪽 위)를 저장하는 자료구조
#define fi first
#define se second
using namespace std;

typedef struct { int x, y; }point;
int n, k, m;

bool contain(pi a, pi b) {		//a영역이 b영역을 포함하는지 검사하는 메소드
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
		point MIN = { 305,305 }, MAX = { 0,0 };	//검사의 범위를 제한할 최소, 최대 좌표 저장
		vector<pi> v;							//종양의 정보들을 저장할 벡터
		int mw = 987654321, ans = 987654321;	//mw: 방사선의 면적은 최소 mw 이상이어야 함, ans: 종양을 m이하로 없앨 수 있는 방사선의 최소 크기


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
			//좌표 정보가 순서 없이 혹은 방향이 다르게 나올 수 있기 때문에 (왼쪽 아래, 오른쪽 위)의 형태로 종양 정보를 저장

			mw = min(max(p.se.x - p.fi.x, p.se.y - p.fi.y), mw);	//종양의 최소 크기 갱신

			v.push_back(p);
		}

		int left = mw, right = max(MAX.x, MAX.y);	//방사선의 위치를 선정하는 부분이 너무 오래 걸릴 것 같아서
													//방사선의 크기는 이분 탐색으로 구현했습니다(최대 300 -> 반복 횟수 10회 이하로 제한)
		while (left <= right) {
			int k = (left + right) / 2;				//현재 테스트해볼 방사선의 면적

			int MAX_Y = max(MAX.y - k, MAX.y);		//방사선의 탐색 최대 위치를 제한
			int MAX_X = max(MAX.x - k, MAX.x);

			int sub = -1;
			bool B = false;
			for (int i = MIN.y; i <= MAX_Y; i++) {
				for (int j = MIN.x; j <= MAX_X; j++) {		//방사선의 시작 위치 탐색
					if (B)break;	//만약 종양을 m개 이하로 줄일 수 있는 위치를 발견했다면 더이상 반복하지 않는다
					int count = 0;
					pi cur;
					cur.fi.x = j;
					cur.fi.y = i;
					cur.se.x = j + k;
					cur.se.y = i + k;		//현재 방사선의 시작 및 끝점 좌표를 설정

					for (int i = 0; i < v.size(); i++) {	//모든 종양에 대해 방사선이 종양을 포함하고 있는지 카운트
						if (contain(cur, v[i]))count++;
					}

					if (v.size() - count <= m) {	//종양을 m개 이하로 줄였다면
						sub = k;
						if (k < ans)ans = k;	//ans의 최소값 갱신
						B = true;
						break;
					}
				}
			}

			if (B) {	//현재 면적으로 모든 종양을 커버했어도 더 작은 k값이 있을 수 있기 때문에 탐색 크기를 좁혀준다
				right = k - 1;
			}
			else {		//현재 면적으로 모든 종양을 커버할 수 없다면 면적을 늘려야하기 때문에 탐색 크기를 늘려준다
				left = k + 1;
			}
		}

		cout << "#" << test_case << ' ' << ans << '\n';
	}

	return 0;
}