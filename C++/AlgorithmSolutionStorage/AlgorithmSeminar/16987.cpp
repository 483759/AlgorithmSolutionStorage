#include <cstdio>
#include <vector>
using namespace std;
typedef struct { int s, w; }egg;
vector<egg> v;
int n;
int func(int dep, int e) {
	if (dep == n) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++)
			if (v[i].s <= 0)
				sum++;
		return sum;
	}

	int max = 0;
	if (v[dep].s <= 0||e==1)
		max = func(dep + 1,e);
	else {
		for (int i = 0; i < n; i++) {
			if (v[i].s <= 0 || i == dep)continue;
			v[i].s -= v[dep].w;
			v[dep].s -= v[i].w;

			int t = 0;
			if (v[i].s <= 0)t++;
			if (v[dep].s <= 0)t++;

			int k = func(dep + 1,e-t);
			max = k > max ? k : max;

			v[i].s += v[dep].w;
			v[dep].s += v[i].w;
		}
	}
	return max;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0,s,w; i < n; i++) {
		scanf("%d%d", &s, &w);
		v.push_back({ s,w });
	}
	printf("%d", func(0,n));
	return 0;
}