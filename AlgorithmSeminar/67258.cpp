#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

typedef struct {
	int s, f, d;
}str;

bool cmp(str a, str b) {
	if (a.d == b.d)return a.s < b.s;
	return a.d < b.d;
}

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	vector<int> v;
	map<string, int> m;
	int count = 1;

	for (int i = 0; i < gems.size(); i++) {
		map<string, int>::iterator it;
		it=m.find(gems[i]);

		if (it == m.end()) {
			m[gems[i]] = count;
			v.push_back(count);
			count++;
		}
		else
			v.push_back(m[gems[i]]);
	}

	int start = 0;
	vector<int> check(count);
	vector<str> ans;
	check[v[0]]++;
	for (int cur = 0; cur < gems.size(); cur++) {
		check[v[cur]]++;
		vector<int> tmp = check;
		while (start < cur) {
			tmp[v[start]]--;
			int i = 1;
			for(;i<tmp.size();i++)
				if (check[i]!=tmp[i]&&!tmp[i])break;
			if (i == tmp.size()) {
				check = tmp;
				start++;
			}
			else break;
		}
		bool b = 1;
		for (int i = 1; i < check.size(); i++)
			if (!check[i])b = 0;
		if (b)
			ans.push_back({ start,cur,cur-start+1 });
	}
	sort(ans.begin(), ans.end(), cmp);
	answer.push_back(ans[0].s+1);
	answer.push_back(ans[0].f+1);
	return answer;
}

int main() {
	vector<string> v{ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
	vector<int> ans=solution(v);
	cout << ans[0] << " " << ans[1] ;
	return 0;
}