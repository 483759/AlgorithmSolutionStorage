#include <string>
#include <vector>
#include <queue>

using namespace std;

void dfs(int cur, vector<vector<int>> ug, vector<vector<int>>& og, vector<bool>& visit) {
	visit[cur] = true;

	for (auto x : ug[cur]) {
		if (!visit[x]) {
			og[cur].push_back(x);
			dfs(x, ug, og, visit);
		}
	}
}

bool toposort(int n, vector<vector<int>> og) {
	vector<int> indeg(n,0);

	for (int i = 0; i < n; i++)
		for (auto x : og[i])
			indeg[x]++;

	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		printf("%d ", cur);

		for (auto x : og[cur]) {
			if (!indeg[x])continue;

			if (--indeg[x] == 0)
				q.push(x);
		}
	}

	return q.empty();
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	bool answer = true;
	vector<vector<int>> ug(n), og(n);

	for (auto p : path) {
		ug[p[0]].push_back(p[1]);
		ug[p[1]].push_back(p[0]);
	}

	dfs(0, ug, og, vector<bool>(n,false));

	for (auto o : order) {
		og[o[0]].push_back(o[1]);
	}

	return toposort(n,og);
}

int main() {

	solution(9, { {0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5} }, { {8,5},{6,7},{4,1} });
	return 0;
}