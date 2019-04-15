#include <stdio.h>
int main() {
	printf("Hello World!");
	return 0;
}

//#include <cstdio>
//#include <algorithm>
//typedef struct Edge {
//	int u, v, w;
//}edge;
//edge e[1000001];
//int N, M, p[100001], r[100001], max;
//
//void make_set(int x) {
//	p[x] = x;
//	r[x] = 0;
//}
//int find_set(int x) {
//	if (p[x] != x)	p[x] = find_set(p[x]);
//	return p[x];
//}
//void union_set(int x, int y) {
//	x = find_set(x), y = find_set(y);
//	if (r[x] > r[y])
//		p[y] = x;
//	else {
//		p[x] = y;
//		if (r[x] == r[y])r[y]++;
//	}
//}
//bool cmp(edge e1, edge e2) {
//	return e1.w < e2.w;
//}
//int mst() {
//	int ret = 0;
//	for (int i = 1; i <= N; i++)	make_set(i);
//	std::sort(e, e + M, cmp);
//	for (int i = 0, u, v; i < M; i++) {
//		u = e[i].u, v = e[i].v;
//		if (find_set(u) != find_set(v)) {
//			ret += e[i].w;
//			max = e[i].w;
//			union_set(u, v);
//		}
//	}
//	return ret - max;
//}
//int main() {
//	scanf("%d%d", &N, &M);
//	for (int i = 0, u, v, w; i < M; i++) {
//		scanf("%d%d%d", &u, &v, &w);
//		e[i] = { u, v, w };
//	}
//	printf("%d", mst());
//	return 0;
//}