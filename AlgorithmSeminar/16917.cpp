#include <cstdio>
int a, b, c, x, y, sum, min, t;
int main() {
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
	t = c * 2 * (x > y ? x : y);
	//반반치킨으로만 산다고 가정했을 때 금액
	if (a + b > c * 2) {	//따로보다 반반으로 사는게 이득일 때
		min = x > y ? y : x;	//양 or 후 중 적은 치킨 수를 저장
		sum = c * 2 * min;	//적은 치킨수에 맞춰서 반반치킨을 시킨다
		x -= min; y -= min;	//반반치킨을 시킨만큼 시켜야되는 치킨수를 뺀다
	}
	sum += a * x + b * y;	//남은 양의 치킨 값 계산
	if (t < sum)
		sum = t;		//반반만 사서 남는게 더 이득이라면
	printf("%d", sum);
	return 0;
}