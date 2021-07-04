#include <cstdio>
#include <algorithm>
using namespace std;
int n, box[100];
int main() {
	for (int t = 1; t <= 10; t++) {
		scanf("%d", &n);
		for (int i = 0; i < 100; i++) scanf("%d", &box[i]);
		while (n--) {
			sort(box, box + 100);
			if (box[99] != box[0])
				box[0]++; box[99]--;
		}			sort(box, box + 100);
		printf("#%d %d\n", t, box[99] - box[0]);
	}
	return 0;
}