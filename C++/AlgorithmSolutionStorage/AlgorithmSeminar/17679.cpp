#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
string map[31];
bool check[31][31];
int dx[] = { 1,0,1,0 }, dy[] = { 1,1,0,0 };
int solution(int n, int m, vector<string> board) {
	int answer = 0;

	while (1) {
		bool B = true;
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < m - 1; j++) {
				char c = board[i][j];
				if (c=='0')continue;
				bool b = true;
				for (int k = 0; k < 3; k++)
					if (board[i + dy[k]][j + dx[k]] != board[i][j])
						b = false;
				if (b) {
					for (int k = 0; k < 4; k++)check[i + dy[k]][j + dx[k]] = 1;
					B = 0;
				}
			}
		for (int j = 0; j < m; j++) {
			queue<char> q;
			for (int i = n - 1; i >= 0; i--) {
				if (!check[i][j])q.push(board[i][j]);
				else answer++;
				board[i][j] = '0';
			}
			for (int i = n - 1; i >= 0; i--) {
				if (q.empty())break;
				board[i][j] = q.front(); q.pop();
			}
		}
		if (B)break;
	}
	return answer;
}
int main() {
	cout << solution(6, 6, { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" });
	return 0;
}