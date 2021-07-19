#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;

void func(int left,int right, int state) {
	if (left >= right) {
		ans = min(ans, state);
		return;
	}

	if (s[left] == s[right]) {
		func(left + 1, right - 1, state);
		return;
	}

	if (s[left + 1] != s[right] && s[left] != s[right - 1])return;

	if (state == 0 && s[left + 1] == s[right])
		func(left + 1, right, 1);
	if (state == 0 && s[left] == s[right - 1])
		func(left, right - 1, 1);

}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	while (n--) {
		ans = 2;
		cin >> s;
		func(0, s.length() - 1, 0);
		cout << ans << '\n';
	}
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//
//string s;
//int n;
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	cin >> n;
//	while (n--) {
//		int apb[26] = { 0 };
//		cin >> s;
//		for (auto x : s)
//			apb[x - 'a'] ++;
//
//		int left = 0,right=s.length()-1, state=0;
//		while (left <= right) {
//			int k = 0;
//			if (s[left] == s[right]) {
//				left++;
//				right--;
//			}
//			else if (apb[s[left]-'a'] % 2) {
//				k = 0;
//			}
//			else if (apb[s[right]-'a'] % 2) {
//				k = 1;
//			}
//
//			state = 1;
//			if (k==0&&s[left + 1] == s[right] && state == 0) {
//				left++;
//			}
//			if (k==1&&s[left] == s[right - 1] && state == 0) {
//				right--;
//			}
//			else {
//				state = 2;
//				break;
//			}
//		}
//		cout << state << '\n';
//	}
//	return 0;
//}