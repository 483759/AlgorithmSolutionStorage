#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

typedef struct { int x, y; }point;

int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int block[][6] = { {0,0,0,0},{2,0,3,1},{2,3,1,0},{1,3,0,2},{3,2,0,1},{2,3,0,1} };

//int pinball(point s, int dir, vector<vector<int>> board) {
//	point cur = s;
//	int sum = 0, n=board.size()-2;
//
//	do {
//		cur.x += dx[dir], cur.y += dy[dir];
//		int k = board[cur.y][cur.x];
//
//		if (!k)continue;
//		else if (k == -1)
//			break;
//		else if (k <= 5) {
//			sum++;
//			dir = block[k][dir];
//		}
//		else if (k <= 10) {
//			bool check = 0;
//			for (int i = 1; i <= n; i++) {
//				for (int j = 1; j <= n; j++)
//					if (board[i][j] == k && (cur.x != j || cur.y != i)) {
//						cur.x = j, cur.y = i;
//						check = 1;
//						break;
//					}
//				if (check)break;
//			}
//		}
//	} while ((cur.x != s.x || cur.y != s.y)
//		&& board[cur.y][cur.x] != -1);
//	return sum;
//}

int pinball(point cur, int dir, int n, vector<vector<int>>& board) {
	point start = cur;
	int score = 0;
	do {
		cur.x += dx[dir]; cur.y += dy[dir];
		int boardNum = board[cur.y][cur.x];

		if (boardNum == 0) {
			continue;
		}
		else if (boardNum == -1) {
			return score;
		}
		else if (boardNum <= 5) {
			dir = block[boardNum][dir];
			score++;
		}
		else if (boardNum <= 10) {
			bool flag = true;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; (j <= n)&&flag; j++)
					if (board[i][j] == boardNum && !(i == cur.y && j == cur.x)) {
						cur = { j,i };
						flag = false;
						break;
					}
			}
		}
	} while (!(cur.x == start.x && cur.y == start.y) && board[cur.y][cur.x] != -1);

	return score;
}

int simulation(int n, vector<vector<int>>& board) {
	int answer = -1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 0) {
				int ret = 0;
				for (int k = 0; k < 4; k++) {
					ret = pinball({ j,i }, k, n, board);
					if (ret > answer)
						answer = ret;
				}
			}
		}
	return answer;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		scanf("%d", &n);

		vector<vector<int>> board(n + 2);
		for (int i = 0; i < n + 2; i++)
			board[i] = vector<int>(n + 2);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &board[i][j]);
			}
		}

		for (int i = 1; i <= n; i++) {
			board[0][i] = board[n + 1][i] = board[i][0] = board[i][n + 1] = 5;
		}

		cout << "#" << test_case << " " << simulation(n, board) << "\n";
	}
	return 0;
}