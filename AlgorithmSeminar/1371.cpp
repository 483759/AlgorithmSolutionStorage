#include <cstdio>
int arr[26];
int main() {
	char c;
	int max = 0;
	freopen("input.txt", "r", stdin);
	while (scanf("%c", &c) != EOF) {
		if (c >= 'a'&&c <= 'z')
			arr[c - 'a']++;
	}

	for (int i = 0; i < 26; i++)
		if (arr[i] >= max)
			max = arr[i];

	for (int i = 0; i < 26; i++)
		if (arr[i] == max)
			printf("%c", i + 'a');
	return 0;
}