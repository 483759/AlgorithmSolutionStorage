#include <cstdio>
int x, y, n;
char str[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT" , "SUN"};
int main() {
	scanf("%d%d", &x, &y);
	for (int i = 1; i < x; i++) {
		switch (i){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			n = (n + 3) % 7;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			n = (n + 2) % 7;
			break;
		default:
			break;
		}
	}
	n = (n + y-1) % 7;
	printf("%s", str[n]);
	return 0;
}