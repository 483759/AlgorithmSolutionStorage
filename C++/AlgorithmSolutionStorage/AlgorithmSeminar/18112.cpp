#include <iostream> 
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define ull unsigned long long
using namespace std;

ull s, f;
bool visit[2500];

bool safe(ull num) {
	return num >= 0 && log2(num) < 11 && !visit[num];
}

ull binaryToDecimal(ull bs) {
	ull num = 0, bin = 1;

	while (bs) {
		if (bs % 2) num += bin;
		bin *= 2; bs /= 10;
	}

	return num;
}

int main() {
	scanf("%lld%lld", &s, &f);
	s = binaryToDecimal(s);
	f = binaryToDecimal(f);

	queue<ull> q;
	q.push(s);

	for (int time = 0;; time++) {
		int size = q.size();
		if (!size)break;

		while (size--) {
			ull cur = q.front(); q.pop();
			if (cur == f) {
				printf("%d", time);
				return 0;
			}

			int index = ceil(log2(cur));
			for (int i = 1; i < index; i++) {
				cur = cur ^ (1L << (ull)(index - 1 - i));
				if (safe(cur)) {
					q.push(cur); visit[cur] = true;
				}
				cur = cur ^ (1L << (ull)(index - 1 - i));
			}

			if (safe(cur + 1)) {
				q.push(cur + 1); visit[cur + 1] = true;
			}
			if (safe(cur - 1)) {
				q.push(cur - 1); visit[cur - 1] = true;
			}
		}
	}

	return 0;
}