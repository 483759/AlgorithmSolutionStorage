#include <cstdio>

bool stone(int n) {
	if (n == 1)
		return true;
	else if (n == 2)
		return false;
	else if (n == 3)
		return true;
	else
		return !stone(n - 3);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%s", stone(n) ? "SK" : "CY");
	return 0;
}