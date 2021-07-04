#include <iostream>
#include <cstring>
#include <string>
#define INF 987654321
using namespace std;
typedef struct {
	int x, y,d;
}point;
bool visit[1005][1005];
int T, dx[] = { 0,1,0,-1 }, dy[] = {-1,0,1,0};
int main() {
	cin >> T;
	for (size_t tc = 1;  tc <= T;  tc++){
		string s;
		cin >> s;
		memset(visit, 0, sizeof(visit));
		point cur = { 502,502,0 }, min = cur, max = cur;
		for each (char c in s){
			switch (c) {
			case 'F':
				cur.x += dx[cur.d];
				cur.y += dy[cur.d];
				break;
			case 'B':
				cur.x -= dx[cur.d];
				cur.y -= dy[cur.d];				
				break;
			case 'L':
				cur.d = (cur.d + 3) % 4;
				break;
			case 'R':
				cur.d = (cur.d + 1) % 4;
				break;
			}
			visit[cur.y][cur.x] = 1;
			if (cur.x < min.x)min.x = cur.x;
			if (cur.y < min.y)min.y = cur.y;
			if (cur.x > max.x)max.x = cur.x;
			if (cur.y > max.y)max.y = cur.y;
		}
		printf("%d\n", (max.x - min.x) * (max.y - min.y));
	}
	return 0;
}