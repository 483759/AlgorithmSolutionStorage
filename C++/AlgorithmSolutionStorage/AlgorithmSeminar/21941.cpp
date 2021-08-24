#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

string origin;
int m;
int cache[1001][1001];
map<string, int> r;

//int func(string origin) {
//	int len = origin.length();
//
//	if (!len)return 0;
//	if (cache.find(origin) != cache.end())return cache[origin];
//
//	auto& ref = cache[origin];
//	ref = 0;
//
//	for (int i = 0; i < origin.length(); i++) {
//		ref = max(ref, func(origin.substr(0, i) + origin.substr(i + 1, len))+1);
//	}
//
//	for (auto recode : r) {
//		string key = recode.first;
//		int value = recode.second;
//
//		int index = origin.find(key);
//		if (index == -1)continue;
//
//		ref = max(ref, func(origin.substr(0, index) + origin.substr(index + key.length()))+value);
//	}
//	
//	return ref;
//}

int dp(int s, int f) {
	if (s >= f)return 0;

	int& ref = cache[s][f];
	if (ref != -1)return ref;

	ref = 0;
	for (int i = s; i < f; i++) {
		ref = max(ref, dp(s, i) + dp(i + 1, f) + 1);
	}

	string sub = origin.substr(s, (f-s));
	for (auto x : r) {
		string key = x.first;
		int value = x.second;

		int idx = sub.find(key);
		if (idx == string::npos)continue;
		idx += s;
		ref = max(ref, dp(s, idx) + dp(idx + key.length(), f) + value);
	}
	return ref;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> origin >> m;
	for (int i = 0; i < m; i++) {
		string k; int v;
		cin >> k >> v;
		r[k] = v;
	}

	fill(&cache[0][0], &cache[origin.length() + 1][origin.length() + 1], -1);

	cout << dp(0, origin.length());
	return 0;
}