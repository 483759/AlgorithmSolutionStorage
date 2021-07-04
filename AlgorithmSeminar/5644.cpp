#include <cstdio>
#include <stdlib.h>
typedef struct {
	int x, y;
}point;
void quick_sort(point* A, int min, int max)
{
	int size = max - min + 1;
	int c_a1, c_a2, c_a3, i;
	point pivot;
	if (size <= 1) return;
	else
	{
		pivot = A[min];
		point* A1 = (point*)malloc(sizeof(point) * size);
		point* A2 = (point*)malloc(sizeof(point) * size);
		point* A3 = (point*)malloc(sizeof(point) * size);	//dynamic allocation of structure array
		c_a1 = 0;
		c_a2 = 0;
		c_a3 = 0;
		for (int i = min; i <= max; i++)
		{
			if ((A[i].x < pivot.x) 
				||(A[i].x==pivot.x&&A[i].y<pivot.y))	//Elements that precede the pivot in sequence
			{
				A1[c_a1] = A[i];
				c_a1++;
			}
			else if (A[i].x == pivot.x && A[i].y == pivot.y)	//same as pivot
			{
				A2[c_a2] = A[i];
				c_a2++;
			}
			else
			{
				A3[c_a3] = A[i];
				c_a3++;
			}
		}
		quick_sort(A1, 0, c_a1 - 1);
		quick_sort(A3, 0, c_a3 - 1);
		for (i = 0; i < c_a1; i++) A[min + i] = A1[i];
		for (i = c_a1; i < c_a1 + c_a2; i++) A[min + i] = A2[i - c_a1];
		for (i = c_a1 + c_a2; i < size; i++) A[min + i] = A3[i - (c_a1 + c_a2)];
	}
}
int main() {
	int size = 5;
	point A[7] = { {3,4},{1,1},{1,-1},{2,2},{3,3} };
	int i = 0;
	quick_sort(A, 0, 4);	
	//sort array in ascending ordef of the x, and if the x are same, in ascending ordef of y
	for (int i = 0; i < size; i++)
		printf("%d %d\n", A[i].x, A[i].y);
	return 0;
}
//#include <cstdio>
//
//int main() {
//	int l, p, v, cnt = 0, i = 1;
//
//	while (1) {
//		scanf("%d %d %d", &l, &p, &v);
//		if (!l && !p && !v)
//			return 0;
//
//		cnt = (int)(v / p) * l;
//		cnt += (v % p) < l ? (v % p) : l;
//
//		printf("Case %d: %d\n", i++, cnt);
//	}
//	return 0;
//}
//#include <cstdio>
//#include <stdlib.h>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int tc, m, a, user[2][105], dx[] = { 0,0,1,0,-1 }, dy[] = { 0,-1,0,1,0 };
//typedef struct {
//	int x, y;
//}point;
//typedef struct {
//	point p;
//	int c, f;
//}ap;
//point A = { 0,0 }, B = { 9,9 };
//vector<pair<int,int>> map[10][10];
//bool cmp(pair<int,int> a, pair<int, int> b) {
//	return a.second > b.second;
//}
//
//int bc() {
//	int ca=0, cb=0;
//	vector<pair<int, int>> &va = map[A.y][A.x],&vb= map[B.y][B.x];
//	
//	if (!va.empty() && !vb.empty())
//		if (va[0].first == vb[0].first) {
//			if (va.size() == 1 && vb.size() == 1)
//				return va[0].second;	//둘다 같은 범위 내에 잇고, AP가 1개 뿐이라면
//			else if (va.size() != 1 && vb.size() != 1)
//				return va[0].second + max(va[1].second, vb[1].second);
//			else if (va.size() != 1)
//				return va[0].second + va[1].second;
//			else
//				return va[0].second + vb[1].second;
//		}
//
//	if (!va.empty())ca = va[0].second;
//	if (!vb.empty())cb = vb[0].second;
//
//	return ca + cb;
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &tc);
//	for (int T = 1; T <= tc; T++) {
//		int ans = 0, t = 0;
//		vector<ap> v; A = { 0,0 }, B = { 9,9 };
//		scanf("%d%d", &m, &a);
//		for (int i = 0; i < 2; i++)
//			for (int j = 1, k; j <= m; j++)
//				scanf("%d", &user[i][j]);
//
//		for (int i = 0, x, y, c, p; i < a; i++) {
//			scanf("%d%d%d%d", &x, &y, &c, &p);
//			v.push_back({ {x - 1,y - 1},c,p });
//		}
//
//		for (int i = 0; i < 10; i++)
//			for (int j = 0; j < 10; j++) {//모든 좌표
//				int index = 1;
//				for (auto k : v) {
//					int dis = abs(i - k.p.y) + abs(j - k.p.x);
//					if (dis <= k.c)	//사정거리 내에 잇다면
//						map[i][j].push_back({ index,k.f });
//					index++;
//				}
//
//				if (map[i][j].size() > 1) {
//					sort(map[i][j].begin(), map[i][j].end(), cmp);
//				}	//capacity 내림차순 정렬
//
//			}
//
//		ans += bc();
//		while (m--) {
//			t++;
//			A.x += dx[user[0][t]]; A.y += dy[user[0][t]];
//			B.x += dx[user[1][t]]; B.y += dy[user[1][t]];
//			int k= bc();
//			ans += k;
//			//printf("%d ", k);			
//		}//printf("\n");
//
//		for (int i = 0; i < 10; i++)for (int j = 0; j < 10; j++)map[i][j].clear();
//		printf("#%d %d\n", T, ans);
//	}
//	return 0;
//}