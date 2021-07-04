#include <cstdio>
int truck[1005], n, w, l, sum[1005],time[1005];
int front, rear,ans;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &w, &l);
	for(int i=1;i<=n;i++){
		scanf("%d", &truck[i]);
		sum[i] = sum[i - 1] + truck[i];
		time[i] = w;
	}
	while (front < n) {
		if ((sum[rear +1] - sum[front] <= l) && (rear<=n)) {
			rear++;
		}
		int f = 0;
		for (int i = front +1; i <= rear; i++) {
			time[i]--;
			if (!time[i])f++;
		}
		front += f;
		ans++;
	}
	printf("%d", ans+1);
	return 0;
}