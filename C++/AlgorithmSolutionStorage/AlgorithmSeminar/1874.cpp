#include <cstdio>
#include <stack>
using namespace std;
stack<int> s;
char str[100];
int main() {
	int n, t = 0, arr[1000], index = 0, m = 0, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	s.push(++index);
	str[m++] = '+';
	while (t < n) {
		while (index < arr[t]) {
			s.push(++index);
			str[m++] = '+';
		}
		if (s.top() > arr[t]) {
			printf("NO");
			return 0;
		}
		while (s.top() == arr[t]) {
			str[m++] = '-';
			s.pop();
			t++;
			if (!s.size())
				break;
		}
	}
	i = 0;
	if (s.empty())	while (str[i] != NULL)	printf("%c\n", str[i++]);
	else printf("NO");
	return 0;
}