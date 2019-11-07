#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
vector<int> v1, v2;
bool p[30005] = { 1,1 };
int a, b, Answer, ans1, ans2;
int tonum(vector<int>& v) {
	int k = 0;
	for (int i = 0; i < v.size(); i++)
		k += v[i] * pow(10, i);
	return k;
}
int func(vector<int>& v, int score) {
	int num = tonum(v); int m;
	if (p[num])return 0;
	for (int i = 0, tmp; i < v.size(); i++) {
		tmp = v[i]; v.erase(v.begin() + i);

		m = max(m, func(v, score + 1) + 1);

		v.insert(v.begin() + i, tmp);
	}
	return m;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= 174; i++)
		for (int j = i * 2; j <= 30000; j += i)p[j] = 1;
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> a >> b;
		Answer = 0;
		while (a) { v1.push_back(a % 10); a /= 10; }
		while (b) { v2.push_back(b % 10); b /= 10; }
		ans1 = func(v1, 0);
		ans2 = func(v2, 0);

		if (ans1 > ans2)Answer = 1;
		else if (ans1 < ans2)Answer = 2;
		else Answer = 3;

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
		v1.clear(); v2.clear();
	}
	return 0;
}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <math.h>
//using namespace std;
//vector<int> v1, v2;
//bool p[30005] = { 1,1 };
//int a, b, ta, tb, ans1, ans2;
//int tonum(vector<int>& v) {
//	int k = 0;
//	for (int i = 0; i < v.size(); i++)
//		k += v[i] * pow(10, i);
//	return k;
//}
//int func(vector<int>& v, int score) {
//	int num = tonum(v); int m;
//	if (p[num])return 0;
//	for (int i = 0, tmp; i < v.size(); i++) {
//		tmp = v[i]; v.erase(v.begin() + i);
//
//		m = max(m, func(v, score + 1) + 1);
//
//		v.insert(v.begin() + i, tmp);
//	}
//	return m;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	for (int i = 2; i <= 174; i++)
//		for (int j = i * 2; j <= 30000; j += i)p[j] = 1;
//	cin >> a >> b;
//	ta = a; tb = b;
//	while (ta) { v1.push_back(ta % 10); ta /= 10; }
//	while (tb) { v2.push_back(tb % 10); tb /= 10; }
//	ans1 = func(v1, 0);
//	ans2 = func(v2, 0);
//	cout << ans1 << ' ' << ans2 << '\n';
//	if (ans1 > ans2)cout << 1;
//	else if (ans1 < ans2)cout << 2;
//	else cout << 3;
//	return 0;
//}