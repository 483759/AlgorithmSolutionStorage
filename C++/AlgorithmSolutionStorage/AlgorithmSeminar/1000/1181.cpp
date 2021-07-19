#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
struct p { int a,k; string s; };
p arr[100001];
bool cmp(const p& p1, const p& p2) {
	if (p1.a == p2.a)return p1.k<p2.k;
	return p1.a < p2.a;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].a;
		cin >> arr[i].s;
		arr[i].k = i;
	}
	sort(arr, arr + n, cmp);
	for(int i=0;i<n;i++)
		cout << arr[i].a << ' ' << arr[i].s << '\n';
	//while (--n>=0)cout << arr[n].a << ' ' << arr[n].s << '\n';
	return 0;
}
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int n, i;
//string s[20005];
//bool cmp(const string& s1, const string& s2) {
//	if (s1.length() == s2.length())
//		return (s1.compare(s2) < 0) ? 1 : 0;
//	return s1.length() < s2.length();
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n;
//	for (i = 0; i < n; i++) cin >> s[i];
//	sort(s, s + n, cmp);
//	for (i = 0; i < n; i++) {
//		if (s[i] == s[i + 1])continue;
//		cout << s[i] << '\n';
//	}
//	return 0;
//}