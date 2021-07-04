#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define INF 40000005
#define pii pair<int,int>

using namespace std;

void floyd(int n, vector<vector<int>>& map) {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

void print(vector<vector<int>> map) {
	for (int i = 1; i < map.size(); i++) {
		for (int j = 1; j < map[i].size(); j++)
			printf("%3d", map[i][j] == INF ? -1 : map[i][j]);
		cout << '\n';
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = INF;
	vector<vector<int>> map(n+1);

	for (int i = 1; i <= n; i++) {
		map[i] = vector<int>(n + 1, INF);
		map[i][i] = 0;
	}

	for (auto f : fares) {
		map[f[0]][f[1]] = f[2];
		map[f[1]][f[0]] = f[2];
	}

	floyd(n, map);
	print(map);
	for (int i = 1; i <= n; i++)
		answer = min(answer, map[s][i] + map[i][a] + map[i][b]);
	return answer;
}

int main() {

	//cout << solution(6, 4, 6, 2, { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} });
	cout << solution(7, 3, 4, 1, { {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6} });
	return 0;
}