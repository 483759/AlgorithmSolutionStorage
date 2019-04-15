#include <cstdio>
#include <stack>
using namespace std;

stack<int> s;
char str[50];

int main() {
	int n;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int j = 0;
		bool cnt = true;
		scanf("%s", str);

		while (str[j] != NULL) {
			if (str[j++] == '(')
				s.push(1);
			else {
				if (!s.size()) {
					cnt = false;
					break;
				}
				else
					s.pop();
			}
		}
		if (cnt && !s.size())printf("YES\n");
		else printf("NO\n");

		while (s.size())
			s.pop();
	}
	return 0;
}
