#include <cstdio>
int a, b, c, x, y, sum, min, t;
int main() {
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
	t = c * 2 * (x > y ? x : y);
	//�ݹ�ġŲ���θ� ��ٰ� �������� �� �ݾ�
	if (a + b > c * 2) {	//���κ��� �ݹ����� ��°� �̵��� ��
		min = x > y ? y : x;	//�� or �� �� ���� ġŲ ���� ����
		sum = c * 2 * min;	//���� ġŲ���� ���缭 �ݹ�ġŲ�� ��Ų��
		x -= min; y -= min;	//�ݹ�ġŲ�� ��Ų��ŭ ���ѾߵǴ� ġŲ���� ����
	}
	sum += a * x + b * y;	//���� ���� ġŲ �� ���
	if (t < sum)
		sum = t;		//�ݹݸ� �缭 ���°� �� �̵��̶��
	printf("%d", sum);
	return 0;
}