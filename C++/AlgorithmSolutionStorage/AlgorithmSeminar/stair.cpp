#include <cstdio>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#define INF 987654321

using namespace std;

typedef struct { int x, y; }point;

typedef struct {
	bool operator()(int a, int b) {
		return a > b;
	}
}cmp;

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ans = INF, n, p = 0, s = 0;
		scanf("%d", &n);

		vector<vector<int>> board(n);
		vector<point> stair;
		vector<point> people;

		for (int i = 0; i < n; i++) {
			board[i] = vector<int>(n);
			for (int j = 0; j < n; j++) {
				scanf("%d", &board[i][j]);
				point cur = { j,i };
				if (board[i][j] == 1) {
					p++;
					people.push_back(cur);
				}
				else if (board[i][j] > 1) {
					point cur = { j,i };
					stair.push_back(cur);
				}
			}
		}

		for (int k = 0; k < (1 << p); k++) {	//모든 경우의 수에 대해
			priority_queue<int, vector<int>, cmp> wait[2];
			queue<int> in[2];
			int fin = 0;

			for (int j = 0; j < p; j++) {
				int num = (k >> j) & 1;
				int dist = abs(stair[num].x - people[j].x) + abs(stair[num].y - people[j].y);
				wait[num].push(dist);
			}

			int time = 0;
			while (fin != p) {
				for (int i = 0; i < 2; i++) {
					int k = board[stair[i].y][stair[i].x];
					while (!in[i].empty() && (in[i].front() + k <= time)) {
						in[i].pop();
						fin++;
						if (fin == p)break;
					}


					while (!wait[i].empty() && (in[i].size() < 3 && wait[i].top() <= time)) {
						in[i].push(time);
						wait[i].pop();
					}

				}
				time++;
			}
			if (time < ans)
				ans = time;
		}
		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}