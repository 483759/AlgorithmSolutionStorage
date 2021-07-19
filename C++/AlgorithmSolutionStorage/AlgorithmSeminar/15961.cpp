#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
vector<int> sushi;
map<int, int> m;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0,t; i < n; i++) {
		cin >> t; sushi.push_back(t);
		if (m.find(t) == m.end())m.insert(make_pair(t, 0));
	}
	if (m.find(c) == m.end())m.insert(make_pair(c, 0));

	int left = 0, right = 0, cnt = 0, kind = 0, answer = 0;
	while (left != n - 1) {
		if (cnt >= k) {
			if (--m[sushi[left]] == 0)
				kind--;
			left = (left + 1) % n;
			cnt--;
		}
		else {
			if (m[sushi[right]]++ == 0)
				kind++;
			right = (right + 1) % n;
			cnt++;
		}
		if (kind >= answer) {
			answer = kind;
			if (m[c] == 0)answer++;
		}
	}
	cout << answer;
	return 0;
}