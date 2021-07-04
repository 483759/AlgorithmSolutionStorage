#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int> s;
int ans;
string str;
bool vps() {
	stack<char> s;
	for (char c : str) {
		switch (c) {
		case '(':
		case '[':
			s.push(c);
			break;
		case ')':
		case ']':
			char t = c == ')' ? '(' : '[';
			if (s.empty())return false;
			char top = s.top(); s.pop();

			if (top != t)return false;
		}
	}
	if (s.empty())return true;
	return false;
}
int main() {
	cin >> str;
	if (!vps()) {
		cout << 0;
		return 0;
	}
	for (char c : str) {
		int num = 0;
		switch(c) {
			case '(':
				s.push(0);
				break;
			case '[':
				s.push(1);
				break;
			case ')':
				while (s.top() != 0) {
					num += s.top();
					s.pop();
				}
				s.pop();
				if (num)
					s.push(2 * num);
				else s.push(2);
				break;
			case ']':
				while (s.top() != 1) {
					num += s.top();
					s.pop();
				}
				s.pop();
				if (num)
					s.push(3 * num);
				else s.push(3);
				break;
		}
	}
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans;
	return 0;
}
//#include <cstdio>
//#include <stack>
//using namespace std;
//
//stack<int> s;
//int main() {
//	char str[32];
//	int i = 0, n = 0;
//	//freopen("input.txt", "r", stdin);
//	scanf("%s", str);
//
//	while (str[i] != NULL) {
//		int num = 0;
//		switch (str[i++]) {
//		case '(':
//			s.push(0);
//			break;
//		case '[':
//			s.push(1);
//			break;
//		case ')':
//			while (s.top() != 0) {
//				num += s.top();
//				s.pop();
//			}
//			s.pop();
//			if (!num) s.push(2);
//			else s.push(num * 2);
//			break;
//		case ']':
//			if (!s.empty) {
//				printf("0");
//				return 0;
//			}
//			while (s.top() != 1) {
//				num += s.top();
//				s.pop();
//			}
//			s.pop();
//			if (!num) s.push(3);
//			else s.push(num * 3);
//			break;
//		default:
//			break;
//		}
//	}
//	while (!s.empty()) {
//		n += s.top();
//		s.pop();
//	}
//	printf("%d", n);
//}