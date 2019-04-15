#include <cstdio>
int N, dice[1001][3], money[1001], max_money;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &dice[i][j]);

	for (int i = 0; i < N; i++) {
		int cnt = 0, num = 0;
		if (dice[i][0] == dice[i][1]) {
			num = dice[i][0];
			cnt++;
		}
		if (cnt) {	//첫 번째와 두 번째가 똑같을 때
			if (dice[i][0] == dice[i][2]) {	//세 개가 똑같을 때
				num = dice[i][0];
				cnt++;
			}
		}
		else if (dice[i][0] == dice[i][2] || dice[i][1] == dice[i][2]) {
			cnt++;	//두 개만 똑같을 때
			num = dice[i][2];
		}

		switch (cnt) {
		case 0:
			num = (dice[i][0] > dice[i][1] ? dice[i][0] : dice[i][1]);
			num = (dice[i][2] > num ? dice[i][2] : num);
			money[i] = num * 100;
			break;
		case 1:
			money[i] = 1000 + num * 100;
			break;
		case 2:
			money[i] = 10000 + num * 1000;
			break;
		default:
			break;
		}
		max_money = money[i] > max_money ? money[i] : max_money;
	}

	printf("%d", max_money);

	return 0;
}