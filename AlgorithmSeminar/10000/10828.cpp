#include <cstdio>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	int n;
	freopen("input.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char str[20];
		if (i == 0)
			scanf(" %s", str);
		else scanf("%s", str);

		if (str[0] = 'p') {
			if (str[1] = 'u') {
				int t;
				scanf("%d", &t);
				s.push(t);
			}
			else{
				if (!s.size()) {
					printf("-1\n");
					continue;
				}
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else if (str[0] = 's')
			printf("%d\n", s.size());
		else if (str[0] = 'e')
			printf("%d\n", s.size() == 0 ? 1 : 0);
		else if (str[0] = 't') {
			if (!s.size()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", s.top());
		}
	}
	return 0;
}