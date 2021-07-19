#include <bits/stdc++.h>
using namespace std;

map<string, int> name;
map<int, string> node;
vector<vector<int>> graph,tree;
vector<int> indeg;
int n,m;

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	indeg = vector<int>(n,0);
	graph = vector<vector<int>>(n);
	tree = vector<vector<int>>(n);

	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s; v.push_back(s);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		name.insert(make_pair(v[i], i));
		node.insert(make_pair(i, v[i]));

	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		indeg[name[a]]++;
		graph[name[b]].push_back(name[a]);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (!indeg[i])cnt++;
	cout << cnt<<'\n';

	queue<int> q;
	for (int i = 0; i < n; i++)
		if (!indeg[i]) {
			cout << node[i]<<" ";
			q.push(i);
		}
	cout << '\n';

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i : graph[cur]) {
			if (indeg[i]) {
				if (--indeg[i] == 0) {
					q.push(i);
					tree[cur].push_back(i);
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		sort(tree[i].begin(), tree[i].end());

	for (int i = 0; i < n; i++) {
		cout << v[i] << " " << tree[i].size() << " ";
		for (auto x : tree[i]) {
			cout << node[x]<<" ";
		}
		cout << '\n';
	}
	return 0;
}