#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <limits.h>
using namespace std;

typedef struct {
	int v, m, c;
}travel;

typedef struct {
	bool operator()(travel a, travel b) {
		return a.c > b.c;
	}
}cmp;

bool isAble(int bs, int idx) {
	return (bs >> idx) & 1;
}

int toggleAble(int state, int idx) {
	return state ^ (1 << idx);
}

int enable(int bs, int idx) {
	return bs | (1 << idx);
}

int disable(int bs, int idx) {
	return bs ^ (1 << idx);
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
	int answer = INT_MAX;
	vector<vector<travel>> g(n + 1);
	map<int, int> trap;

	for (auto r : roads) {
		g[r[0]].push_back({ r[1], 0, r[2] });
		g[r[1]].push_back({ r[0], 1, r[2] });
	}
	int idx = traps.size() - 1;
	for (int i = 1; i <= n; i++)trap[i] = -1;
	for (int t : traps) {
		trap[t] = idx--;
	}

	priority_queue<travel, vector<travel>, cmp> pq;
	vector<vector<int>> dist(1024);
	for (int i = 0; i < 1024; i++)dist[i] = vector<int>(n + 1, INT_MAX);

	pq.push({ start, 0, 0 });
	dist[0][start] = 0;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (cur.c > dist[cur.m][cur.v])continue;

		for (auto x : g[cur.v]) {
			int des = x.v, mode = x.m, cost = x.c;
			//목적지의 vertex 번호, 비용, 해당 간선의 mode

			if (trap[cur.v] != -1) {	//현재 node가 함정
				if (trap[des] != -1) {	//다음 node가 함정
					if (isAble(cur.m, trap[cur.v])) {	// 현재 node가 활성
						if (isAble(cur.m, trap[des])) {	// 다음 node가 활성
							int next = disable(cur.m, trap[des]);
							if (!mode && (dist[next][des] > dist[cur.m][cur.v] + cost)) {
								dist[next][des] = dist[cur.m][cur.v] + cost;
								pq.push({ des,next,dist[next][des] });
							}
						}
						else {	//다음 node가 비활성
							int next = enable(cur.m, trap[des]);
							if (mode && (dist[next][des] > dist[cur.m][cur.v] + cost)) {
								dist[next][des] = dist[cur.m][cur.v] + cost;
								pq.push({ des,next,dist[next][des] });
							}
						}
					}
					else {	//현재 node가 비활성
						if (isAble(cur.m, trap[des])) {	// 다음 node가 활성
							int next = disable(cur.m, trap[des]);
							if (mode && (dist[next][des] > dist[cur.m][cur.v] + cost)) {
								dist[next][des] = dist[cur.m][cur.v] + cost;
								pq.push({ des,next,dist[next][des] });
							}
						}
						else {	//다음 node가 비활성
							int next = enable(cur.m, trap[des]);
							if (!mode && (dist[next][des] > dist[cur.m][cur.v] + cost)) {
								dist[next][des] = dist[cur.m][cur.v] + cost;
								pq.push({ des,next,dist[next][des] });
							}
						}
					}
				}
				else {	//다음 node가 함정이 아님
					if (isAble(cur.m, trap[cur.v])) {	//현재 node가 활성
						if (mode && (dist[cur.m][des] > dist[cur.m][cur.v] + cost)) {
							dist[cur.m][des] = dist[cur.m][cur.v] + cost;
							pq.push({ des,cur.m,dist[cur.m][des] });
						}
					}
					else {
						if (!mode && dist[cur.m][des] > dist[cur.m][cur.v] + cost) {
							dist[cur.m][des] = dist[cur.m][cur.v] + cost;
							pq.push({ des,cur.m,dist[cur.m][des] });
						}
					}
				}
			}
			else {	//현재 node가 함정이 아님
				if (trap[des] != -1) {
					if (isAble(cur.m, trap[des])) {
						//다음 node가 함정이면서 활성화 되었을 경우
						int next = enable(cur.m, trap[des]);
						if (mode && (dist[next][des] > dist[cur.m][cur.v] + cost)) {
							dist[next][des] = dist[cur.m][cur.v] + cost;
							pq.push({ des,next,dist[next][des] });
						}
					}
					else {
						int next = disable(cur.m, trap[des]);
						if (!mode && (dist[next][des] > dist[cur.m][cur.v] + cost)) {
							dist[next][des] = dist[cur.m][cur.v] + cost;
							pq.push({ des,next,dist[next][des] });
						}
					}
				}
				else {
					if (dist[cur.m][des] > dist[cur.m][cur.v] + cost) {
						dist[cur.m][des] = dist[cur.m][cur.v] + cost;
						pq.push({ des,cur.m,dist[cur.m][des] });
					}
				}

			}
		}
	}

	for (int i = 0; i < 1024; i++)
		answer = min(answer, dist[i][end]);
	return answer;
}

int main() {
	//printf("%d", solution(3, 1, 3, { {1, 2, 2},{3,2,3} }, { 2 }));
	printf("%d", solution(4, 1, 4, { {1, 2, 1}, { 3, 2, 1 }, { 2, 4, 1 } }, { 2, 3 }));
	return 0;
}