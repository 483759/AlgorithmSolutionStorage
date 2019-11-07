#include <cstdio>
#include <algorithm>
using namespace std;

struct student {
	char name[10];
	int first;
	int second;
	int third;
};

bool cmp(student a, student b) {
	if (a.first == b.first)
		if (a.second == b.second)
			if (a.third == b.third) {
				for (int i = 0; i < 10; i++) {
					if (a.name[i] == b.name[i])
						continue;
					else
						return a.name[i] < b.name[i];
				}
				return true;
			}
			else
				return a.third > b.third;
		else
			return a.second < b.second;

	return a.first > b.first;
}

int main() {
	int n;
	student std[100000];
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%s%d%d%d", std[i].name, &std[i].first, &std[i].second, &std[i].third);

	sort(std, std + n, cmp);

	for (int i = 0; i < n; i++)
		printf("%s\n", std[i].name);
	return 0;
}