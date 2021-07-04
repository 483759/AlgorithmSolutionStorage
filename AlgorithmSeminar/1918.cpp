#include <iostream>
#include <string>
#include <stack>
using namespace std;
string str;
stack<char> s;
int oprank(char c) {
	if (c == '*' || c == '/')
		return 1;
	else if (c == '(')
		return -1;
	return 0;
}
int main() {
	cin >> str;
	for (char c : str) {
		switch (c) {
		case '(':
			s.push(c);
			break;
		case ')':
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
			break;
		case '+':
		case '*':
		case '-':
		case '/':
			while (!s.empty() && (oprank(s.top()) >= oprank(c))) {
				cout << s.top(); s.pop();
			}
			s.push(c);
			break;
		default:
			cout << c;
			break;
		}
	}
	while (!s.empty()) {
		cout << s.top(); s.pop();
	}
	return 0;
}
//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//int t;
//int main() {
//	cin >> t;
//	while (t--) {
//		stack<char> s;
//		bool b = true;
//		string ps;
//		cin >> ps;
//		for (char c : ps) {
//			if (c == '(')s.push('(');
//			else {
//				if (s.empty()) {
//					b = false;
//					break;
//				}
//				char top = s.top(); s.pop();
//				if (top != '(') {
//					b = false;
//					break;
//				}
//			}
//		}
//		if (b && s.empty())cout << "YES\n";
//		else cout << "NO\n";
//	}
//	return 0;
//}