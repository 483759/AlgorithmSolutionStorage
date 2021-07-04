#include <cstdio>
#include <cstring>
#define NUM 10
struct Trie {

	bool is_terminal; // this represents end of string
	Trie* children[NUM];

	// Constructor
	Trie() : is_terminal(false) {
		memset(children, 0, sizeof(children));
	}

	// Delete all children
	~Trie() {
		for (int i = 0; i < NUM; ++i) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(char* key) {
		if (*key == '\0') {
			is_terminal = true;
		}
		else {
			int index = (*key)-'0';
			if (children[index] == 0)
				children[index] = new Trie();
			children[index]->insert(key + 1);
		}
	}

	bool find(char* key) {
		if (*key == '\0')return true;

		int index = *key - '0';
		if (is_terminal)return false;

		return children[index]->find(key + 1);
	}

};
char str[10005][15]; 
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		Trie* root = new Trie();
		scanf(" %d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", str[i]);
			root->insert(str[i]);
		}bool b = 1;
		for (int i = 0; i < n; i++) {
			b = root->find(str[i]);
			if (!b)break;
		}
		if (b)printf("YES\n");
		else printf("NO\n");
		delete root;
	}
	return 0;
}
//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//using namespace std;
//typedef struct {int day[5];}time;
//int fd[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 },ans[101];
//time strToTime(string s) {
//	time t;
//	for (int i = 0; i < 5; i++) {
//		int a = s[i*3] - '0', b = s[i*3+1] - '0';
//		t.day[i] = a * 10 + b;
//	}
//	return t;
//}
//time when(time t,int min) {
//	bool b = 0;
//	t.day[3] += min;
//	if (t.day[3] >= 60) {
//		t.day[3] = t.day[3] % 60;
//		t.day[2]++;
//		if (t.day[2] >= 24) {
//			t.day[2] %= 24;
//			t.day[1] ++;
//			if (t.day[1] > fd[t.day[0]]) {
//				t.day[1] = 1;
//				t.day[0]++;
//				if (t.day[0] > 12)
//					t.day[0] = 1;
//			}
//		}
//	}
//	return t;
//}
//bool order(time a, time b) {
//	for (int i = 0; i < 5; i++) {
//		if (a.day[i] == b.day[i])continue;
//		if (a.day[i] > b.day[i])return 1;
//		return 0;
//	}
//	return 0;
//}
//int solution(int n, vector<string> cus) {
//	vector<queue<time>> v(n);
//	vector<time> no(n);
//	for (auto x : cus) {
//		time t = strToTime(x); int min = (x[15] - '0') * 10 + (x[16] - '0');
//		time next = when(t, min);
//		time k = { 12,31,23,59,59 }; int knum=0;
//		bool all = 1;
//		for (int i = 0; i < v.size();i++) {
//			//1이라는건? v[i]가 더 크다는거 아직 끝날시간 안됨
//			while (!v[i].empty()) {
//				bool b = order(v[i].front(), t);
//				if (!b)v[i].pop();
//				else break;
//			}
//			if (v[i].empty())all = 0;
//		}
//		if (all) {
//			for (int i = 0; i < v.size(); i++)
//				if (order(k, v[i].back())) {
//					k = v[i].back(); knum = i;
//				}
//			next = when(v[knum].back(),min);
//			v[knum].push(next); no[knum] = next;
//			ans[knum]++; continue;
//		}
//		k = { 12,31,23,59,59 }; knum = 0;
//		for (int i = 0; i < v.size(); i++) {
//			if (v[i].empty()) {
//				if (order(k, no[i])) {
//					k = no[i]; knum = i;
//				}
//			}
//		}
//		v[knum].push(next); no[knum] = next;
//		ans[knum]++;
//	}
//	return 1;
//}
//int main() {
//	time t = { 4,30,23,59,0 };
//	//t = when(t, 1);
//	//for (auto x : t.day)printf("%d ", x);
//	cout << solution(3, { "10/01 23:20:25 30", "10/01 23:25:50 26", "10/01 23:31:00 05", "10/01 23:33:17 24", "10/01 23:50:25 13", "10/01 23:55:45 20", "10/01 23:59:39 03", "10/02 00:10:00 10" });
//	return 0;
//}
//#include <iostream>
//#include <map>
//#include <vector>
//#include <string>
//using namespace std;
//int g[10005][10005],n,ans[2];
//void dfs(int cur,int des,int k) {
//	if (cur == des) {
//		ans[k]++;
//		return;
//	}
//	for (int i = 0; i < n; i++) 
//		if (g[cur][i]) {
//			dfs(i, des,k);
//		}
//	
//}
//int solution(string s, string h, string d, vector<vector<string>> r) {
//	map<string, int> m; map<string, int>::iterator it;
//	for (auto x : r) {
//		int v1, v2;
//		if ((it = m.find(x[0])) == m.end()) {
//			m.insert(make_pair(x[0], n));
//			v1 = n++;
//		}
//		else v1 = it->second;
//		if ((it = m.find(x[1])) == m.end()) {
//			m.insert(make_pair(x[1], n));
//			v2 = n++;
//		}
//		else v2 = it->second;
//		g[v1][v2] = 1;
//	}
//	dfs(m[s], m[h], 0);
//	dfs(m[h], m[d], 1);
//	return ans[0]*ans[1];
//}
//int main() {
//	cout << solution("SEOUL", "DAEGU", "YEOSU", 
//		{ {"ULSAN","BUSAN"},{"DAEJEON","ULSAN"},{"DAEJEON","GWANGJU"},{"SEOUL","DAEJEON"},{"SEOUL","ULSAN"},{"DAEJEON","DAEGU"},{"GWANGJU","BUSAN"},{"DAEGU","GWANGJU"},{"DAEGU","BUSAN"},{"ULSAN","DAEGU"},{"GWANGJU","YEOSU"},{"BUSAN","YEOSU"} });
//	return 0;
//}
