#include <cstdio>
int n, m1, m2;
char arr[51][51], tmp,pre;
void count() {
	int c1=1,c2=1;
	for (int i = 0; i < n; i++) {
		char pre = arr[i][0];
		for (int j = 1; j < n; j++) {
			if (arr[i][j] == pre)c1++;
			else { 
				if (c1 > m1)m1 = c1;
				c1 = 1; 
			}
			pre = arr[i][j];
		}
		if (c1 > m1)m1 = c1;
	}
	for (int i = 0; i < n; i++) {
		char pre = arr[0][i];
		for (int j = 1; j < n; j++) {
			if (arr[j][i] == pre)c2++;
			else {
				if (c2 > m2)m2 = c2;
				c2 = 1;
			}
			pre = arr[j][i];
		}
		if (c2 > m2)m2 = c2;
	}

}
void swap(char &c1, char &c2) {
	tmp = c1;
	c1 = c2;
	c2 = tmp;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d ", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++) {
			swap(arr[i][j], arr[i][j + 1]);
			count();
			swap(arr[i][j], arr[i][j + 1]);

			swap(arr[j][i], arr[j + 1][i]);
			count();
			swap(arr[j][i], arr[j + 1][i]);
		}
	printf("%d", m1>m2?m1:m2);
	return 0;
}