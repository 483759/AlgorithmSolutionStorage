#include <cstdio>
int arr[51], i, height = 10, state;
char c;
int main() {
	while (scanf("%1c", &c) != EOF) {
		if (c == '(')
			arr[i++] = 1;
		else if(c==')')
			arr[i++] = 0;
	}

	state = arr[0]? 1 : 0;

	for (int j = 1; j < i; j++) {
		if (state == arr[j])
			height += 5;
		else {
			height += 10;
			state = arr[j]? 1 : 0;
		}
	}
	printf("%d", height);

	return 0;
}