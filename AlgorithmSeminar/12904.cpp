#include <iostream>
#include <algorithm>
using namespace std;
string s, t;
int main() {
	cin >> s >> t;
	while (t.size() != s.size()) {
		char c = t.back(); t.pop_back();
		if (c == 'B')reverse(t.begin(), t.end());
	}
	printf("%d", t==s);
	return 0;
}
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//string s, t;
//int t1, t2,a1,a2;
//bool func(string str, int a, int b) {
//	if (a > a1 || b > a2)return false;
//	if (str.length() == t.length())return str == t;
//	string r = str; reverse(r.begin(), r.end());
//	return func(str + 'A',a+1,b) || func(r + 'B',a,b+1);
//}
//int main() {
//	cin >> s;
//	cin >> t;
//	for (int i = 0; i < s.length(); i++)if (s[i] == 'a')t1++; else t2++;
//	for (int i = 0; i < t.length(); i++)if (t[i] == 'a')a1++; else a2++;
//	cout << func(s,t1,t2);
//	return 0;
//}
//B
//BA
//ABB
//ABBA