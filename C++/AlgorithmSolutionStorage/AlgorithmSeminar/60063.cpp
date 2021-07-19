#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct { int x, y; }point;
typedef struct { point p; int r, t; }block;
bool visit[2][101][101];	//bfs탐색을 위한 방문 배열
int dx[] = { 0,1,0,-1 }, dy[] = { -1,0,1,0 }, n;
int map[101][101];
queue<block> q;

bool safe(point p) {
	return p.x >= 0 && p.x < n && p.y >= 0 && p.y < n && !map[p.y][p.x];
}

bool move_possible(block b, int dir){
	point one, two;
	one = b.p;

	if (b.r == 0)
		two = { b.p.x + 1,b.p.y };
	else two = { b.p.x,b.p.y + 1 };

	one.x += dx[dir]; one.y += dy[dir];
	two.x += dx[dir]; two.y += dy[dir];

	if (!safe(one)||!safe(two))
		return 0;
	else return 1;
}

block rotate_move(block b, int num) {
	if (b.r) {
		if (num % 2) {
			if (!safe({ b.p.x-1,b.p.y }) || !safe({ b.p.x-1,b.p.y+1 }))return b;
			b.r = 0;	b.p.x--;
			if (num == 3)b.p.y++;
			return b;
		}
		else {
			if (!safe({ b.p.x+1,b.p.y}) || !safe({ b.p.x + 1,b.p.y + 1 }))return b;
			b.r = 0;
			if (num == 4)b.p.y++;
			return b;
		}
	}
	else {
		if (num % 2) {
			if (!safe({ b.p.x,b.p.y - 1 }) || !safe({ b.p.x + 1,b.p.y - 1 }))return b;
			b.r = 1;	b.p.y--;
			if (num == 3)b.p.x++;
			return b;
		}
		else {
			if (!safe({ b.p.x,b.p.y + 1 }) || !safe({ b.p.x + 1,b.p.y + 1 }))return b;
			b.r = 1;
			if (num == 4)b.p.x++;
			return b;
		}
	}
}
int solution(vector<vector<int>> board) {
	int answer = 0;
	n = board.size();
	int size = (n - 1) * (n - 1);

	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board.size(); j++)
			map[i][j] = board[i][j];

	q.push({ {0,0},0,0 });
	visit[0][0][0] = 1;
	while (!q.empty()) {
		block cur = q.front();
		block next=cur;
		q.pop();

		if ((cur.p.x * cur.p.y == size)
			||(cur.r&&(cur.p.x*(cur.p.y+1)== size))
			|| (!cur.r && (cur.p.y * (cur.p.x + 1) == size))) {
			return cur.t;
		}

		for(int i=0;i<4;i++)
			if (move_possible(cur, i)) {
				next = cur;
				next.p.x += dx[i], next.p.y += dy[i];
				if (visit[next.r][next.p.y][next.p.x])continue;

				next.t++;
				q.push(next);
				visit[next.r][next.p.y][next.p.x] = 1;
			}

		for (int i = 1; i <= 4; i++) {
			next = rotate_move(cur, i);
			if (cur.r == next.r
				&& cur.p.x == next.p.x
				&& cur.p.y == next.p.y)continue;
			if (visit[next.r][next.p.y][next.p.x])continue;

			next.t++;
			q.push(next);
			visit[next.r][next.p.y][next.p.x] = 1;
		}
	}

	return answer;
}

int main() {
	int arr[] = { 0,0,0,1,1,0,0,0,1,0,0,1,0,1,1,1,1,0,0,1,0,0,0,0,0 };
	vector<vector<int>> v;

	for (int i = 0; i < 5; i++) {
		vector<int> vv;
		for (int j = 0; j < 5; j++)
			vv.push_back(arr[i * 5 + j]);
		v.push_back(vv);
	}
	cout<<solution(v);
	return 0;
}