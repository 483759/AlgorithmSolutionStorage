#include <vector>
#include <queue>
using namespace std;
int N,M,dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool visit[101][101];
typedef struct { int x, y; }point;
bool safe(int x, int y) { return x >= 0 && x < M && y >= 0 && y < N; }
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int n, int m, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	N = n; M = m;
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
		if (visit[i][j] || !picture[i][j])continue;
		number_of_area++;

		int color = picture[i][j],size=0;
		queue<point> q;

		q.push({ j,i });
		visit[i][j] = 1;
		while(!q.empty()) {
			size++;
			point cur = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = cur.x + dx[k], ny = cur.y + dy[k];
				if (!safe(nx, ny) || visit[ny][nx] || picture[ny][nx] != color)continue;
				q.push({ nx,ny });
				visit[ny][nx] = 1;
			}
		}
		if (size > max_size_of_one_area)
			max_size_of_one_area = size;
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	vector<int> v = solution(6, 4, { {1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3} });
	printf("%d %d", v[0], v[1]);
	return 0;
}