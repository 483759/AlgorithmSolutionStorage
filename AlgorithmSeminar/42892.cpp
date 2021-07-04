#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef struct { int key, x; }node;
vector<int> level;
vector<vector<node>> tree(1000005);

vector<vector<int>> travle(node root, vector<int>& pre, vector<int>& post, int l, int left,int right) {
	vector<int> list;
	//list.push_back(root.key);
	pre.push_back(root.key);
	if (l < level.size()-1) {
		for (auto next : tree[level[l + 1]]) {
			if (next.x > left&& next.x < root.x) {
				auto lst= travle(next, pre, post, l+1, left, root.x)[0];
				list.insert(list.end(), lst.begin(), lst.end());
				break;
			}
		}

		for (auto next : tree[level[l + 1]]) {
			if (next.x > root.x&& next.x < right) {
				auto rst= travle(next, pre,post,l + 1, root.x, right);
				list.insert(list.end(), rst.begin(), rst.end());
				break;
			}
		}
	}
	
	return vector<vector<int>>(list.insert(list.begin(), root.key), list.insert(list.end(), root.key));;
}

vector<int> postorder(node root, int l, int left, int right) {
	vector<int> list;
	if (l < level.size() - 1) {
		for (auto next : tree[level[l + 1]]) {
			if (next.x > left&& next.x < root.x) {
				auto lst = postorder(next, l + 1, left, root.x);
				list.insert(list.end(), lst.begin(), lst.end());
				break;
			}
		}

		for (auto next : tree[level[l + 1]]) {
			if (next.x > root.x&& next.x < right) {
				auto rst = postorder(next, l + 1, root.x, right);
				list.insert(list.end(), rst.begin(), rst.end());
				break;
			}
		}
	}
	list.push_back(root.key);
	return list;
}

bool cmp(vector<int> a, vector<int> b) {
	if (a[1] == b[1])return a[0] < b[0];
	return a[1] > b[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer(2);
	set<int> s;

	int size = nodeinfo.size();
	for (int i = 0; i < size; i++) {
		tree[nodeinfo[i][1]].push_back({ i + 1, nodeinfo[i][0] });
		auto it = lower_bound(level.begin(), level.end(), nodeinfo[i][1]);
		s.insert(nodeinfo[i][1]);
	}

	for (auto k : s) {
		level.insert(level.begin(),k);
	}
	level.insert(level.begin(), 0);

	answer=travle(tree[level[1]][0], answer[0], answer[1], 1, -1, 100001);
	//for (auto k : preorder(tree[level[1]][0], 1, -1, 100001)) {
	//	cout << k << " ";
	//}
	return answer;
}


//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//typedef struct { int x, n, l; }node;
//vector<node> tree;
//
//bool cmp(node a, node b) {
//	if (a.l == b.l)return a.x < b.x;
//	else return a.l > b.l;
//}
//
//vector<int> preorder(int sx, int fx, int level) {
//	vector<int> v;
//	if (tree.back().l < level)return v;
//
//	for (auto t : tree) {
//		if (t.l != level)continue;
//		if (t.x >= sx && t.x <= fx) {
//			v.push_back(t.n);
//			vector<int> pre = preorder(sx, t.x - 1, level + 1);
//			v.insert(v.end(), pre.begin(), pre.end());
//			vector<int> post = preorder(t.x+1,fx, level + 1);
//			v.insert(v.end(), post.begin(), post.end());
//			break;
//		}
//	}
//	return v;
//}
//
//vector<int> postorder(int sx, int fx, int level) {
//	vector<int> v;
//
//	for (auto t : tree) {
//		if (t.l != level)continue;
//		if (t.x >= sx && t.x <= fx) {
//			vector<int> pre = postorder(sx, t.x - 1, level + 1);
//			v.insert(v.end(), pre.begin(), pre.end());
//			vector<int> post = postorder(t.x + 1, fx, level + 1);
//			v.insert(v.end(), post.begin(), post.end());
//			v.push_back(t.n);
//			break;
//		}
//	}
//	return v;
//}
//
//vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
//	vector<vector<int>> answer;
//	int minx = 100001, maxx = 0;
//
//	for (int i = 0; i < nodeinfo.size();i++) {
//		tree.push_back({ nodeinfo[i][0],i+1,nodeinfo[i][1] });
//		if (nodeinfo[i][0] < minx)minx = nodeinfo[i][0];
//		if (nodeinfo[i][0] > maxx)maxx = nodeinfo[i][0];
//	}
//	sort(tree.begin(), tree.end(), cmp);
//	int y = tree[0].l;	tree[0].l = 0;
//	for (int i = 1; i < tree.size(); i++) {
//		if (tree[i].l == y)
//			tree[i].l = tree[i - 1].l;
//		else {
//			y = tree[i].l;
//			tree[i].l = tree[i - 1].l + 1;
//		}
//	}
//
//	answer.push_back(preorder(minx, maxx, 0));
//	answer.push_back(postorder(minx, maxx, 0));
//	return answer;
//}

int main() {
	vector<vector<int>> v = { {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };

	v = solution(v);
	for (auto x : v) {
		for (auto y : x)
			cout << y << " ";
		cout << endl;
	}
	return 0;
}