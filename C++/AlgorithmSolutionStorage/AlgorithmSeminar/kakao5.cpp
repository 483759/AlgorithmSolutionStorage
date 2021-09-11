#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> ans;
int s;

void dfs(int cur, int sheep, int wolf, vector<int>& info, vector<int>& sub, vector<bool>& visit, vector<vector<int>>& graph) {
	if (wolf >= sheep)
		return;

	if (visit[cur])return;
	visit[cur] = true;
	if (sheep > s)s = sheep;
	if ((sheep) > ans.first) {
		ans = make_pair(sheep, wolf);
	}
	for (auto x : graph[cur]) {
		if (info[x]) {
			dfs(x, sheep, wolf + 1, info, sub, visit, graph);
		}
		else {
			dfs(x, sheep + 1, wolf, info, sub, visit, graph);
		}
		if (ans.first > sheep) {
			sheep = ans.first;
			wolf = ans.second;
		}
		//sheep = s;
	}
}

int solution(vector<int> info, vector<vector<int>> edges) {
	int answer = 0;
	vector<bool> visit(info.size(), false);
	vector<int> sub(info.size(), 0);
	vector<vector<int>> graph(info.size());

	for (auto e : edges) {
		graph[e[0]].push_back(e[1]);
	}

	queue<int> q;
	q.push(0); ans.first = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto x : graph[cur]) {
			q.push(x);
		}

		if (!visit[cur])
			dfs(cur, ans.first, ans.second, info, sub, visit, graph);
	}

	return ans.first;
}

int main() {
	//cout << solution({ 0,0,1,1,1,0,1,0,1,0,1,1 }, { {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9} });
	cout << solution({ 0,1,0,1,1,0,1,0,0,1,0 }, { {0,1},{0,2},{1,3},{1,4},{2,5},{2,6},{3,7},{4,8},{6,9},{9,10} });
}