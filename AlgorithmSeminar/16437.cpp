//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//typedef pair<int, int> pii;
//int n;
//long long ans = 0;
//
//struct Node {
//	int value;
//	int parent;
//	vector<int> child;
//};
//
//void dfs(vector<Node>& arr, int idx, long long sum) {
//	int p = arr[idx].parent;
//	if (idx == 1) { //루트일때
//		if (sum > 0)ans += sum;
//		return;
//	}
//	if (arr[p].value < 0) { //부모가 늑대일때
//		if (sum >= (arr[p].value * -1)) { //양이 더 많을때
//			sum += arr[p].value;
//			arr[p].value = 0;
//		}
//		else { //늑대가 더 많을때
//			sum = 0;
//			arr[p].value += sum; //음수니까 덧셈
//		}
//	}
//	else { //부모가 양일때
//		sum += arr[p].value;
//		arr[p].value = 0;
//	}
//	dfs(arr, p, sum);
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n;
//	vector<Node> arr(n + 1);
//	vector<int> node;
//	for (int i = 2; i <= n; i++) {
//		char t;
//		int cnt, p;
//		cin >> t >> cnt >> p;
//		if (t == 'S')arr[i].value = cnt;
//		else arr[i].value = cnt * -1;
//		arr[p].child.push_back(i);
//		arr[i].parent = p;
//	}
//	for (int i = 2; i <= n; i++) {
//		if (arr[i].child.empty())node.push_back(i); //leafnode 찾기
//	}
//	for (int i : node) { //leafnode에서 하나씩 dfs출발
//		dfs(arr, i, arr[i].value > 0 ? arr[i].value : 0);
//	}
//	cout << ans;
//	return 0;
//}

#include <iostream>
#include <vector>
#define ll long long
#define pii pair<int,int>
using namespace std;

int n;
vector<vector<pii>> graph;
vector<int> animal;
vector<bool> visit;

ll dfs(int cur) {
	visit[cur] = true;
	ll sum = 0;

	for (auto x : graph[cur]) {
		if (visit[x.first])continue;
		ll k = dfs(x.first) + x.second;
		if (k > 0)sum += k;
	}
	return sum;

}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	graph = vector<vector<pii>>(n + 1);
	animal = vector<int>(n + 1);
	visit = vector<bool>(n + 1, false);

	for (int i = 2; i <= n; i++) {
		char t; int a, p;
		cin >> t >> a >> p;
		if (t == 'W') {
			graph[p].push_back(make_pair(i, -a));
			graph[i].push_back(make_pair(p, -a));
		}
		else {
			graph[p].push_back(make_pair(i, a));
			graph[i].push_back(make_pair(p, a));
		}
	}
	printf("%lld", dfs(1));
	return 0;
}