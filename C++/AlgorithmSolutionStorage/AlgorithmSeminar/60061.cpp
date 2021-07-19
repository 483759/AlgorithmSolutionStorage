#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int frame[2][105][105], N, dx[] = { 1,1,1,0,-1,-1,-1,0 }, dy[] = { 1,0,-1,-1,-1,0,1,1 };

bool safe(int x, int y) {
	return x >= 0 && x <= N && y >= 0 && y <= N;
}

bool conductable(int x, int y, int a) {
	if (a == 1) {
		if ((frame[0][y - 1][x] || frame[0][y - 1][x + 1])
			|| (frame[1][y][x - 1] && frame[1][y][x + 1]))
			return 1;
	}
	else {
		if (y == 0	//바닥 위에 있거나
			|| frame[1][y][x - 1]	//보의 한쪽 끝
			|| frame[0][y - 1][x])	//다른 기둥 위
			return 1;
	}
	return 0;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	//fill(&frame[0][0][0], &frame[1][104][105], ); 
	N = n;

	for (auto cur : build_frame) {
		int x = cur[0], y = cur[1];
		if (cur[3]) {	//설치
				//보
			if (conductable(x, y, cur[2]))
				frame[cur[2]][y][x] = 1;
		}
		else {	//삭제
			bool b = true;
			int temp = frame[cur[2]][y][x];
			for (int i = 0; i < 8; i++) {
				if (!b)break;
				for (int a = 0; a < 2; a++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (!safe(nx, ny) || !frame[a][ny][nx])continue;	//범위를 벗어났거나, 해당 범위에 구조물이 없으면
					frame[cur[2]][y][x] = 0;
					if (!conductable(nx, ny, frame[a][ny][nx]))
						b = false;
					frame[cur[2]][y][x] = temp;
				}
			}
			if (b)
				frame[cur[2]][y][x] = 0;
		}

	}

	for (int j = 0; j <= n; j++)
		for (int i = 0; i <= n; i++)
			for (int a = 0; a < 2; a++) {
				if (frame[a][i][j]) {
					vector<int> v = { j,i,a };
					answer.push_back(v);
				}
			}
	return answer;
}

int main() {
	vector<vector<int>> v = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
	//{ {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
	//{ {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} };
	v = solution(5, v);
	for (auto x : v)
		cout << x[0] << x[1] << x[2] << endl;
	return 0;
}