#include <cstdio>
#include <stack>
using namespace std;

stack<int> s;
int main() {
	char str[32];
	int i = 0, n = 0;
	//freopen("input.txt", "r", stdin);
	scanf("%s", str);

	while (str[i] != NULL) {
		int num = 0;
		switch (str[i++]) {
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
			if (!num) s.push(2);
			else s.push(num * 2);
			break;
		case ']':
			if (!s.empty) {
				printf("0");
				return 0;
			}
			while (s.top() != 1) {
				num += s.top();
				s.pop();
			}
			s.pop();
			if (!num) s.push(3);
			else s.push(num * 3);
			break;
		default:
			break;
		}
	}
	while (!s.empty()) {
		n += s.top();
		s.pop();
	}
	printf("%d", n);
}