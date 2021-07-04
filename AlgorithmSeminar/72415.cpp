#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#define SIZE 4
#define pip pair<int,point>
using namespace std;


typedef struct { int x, y; }point;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };


bool safe(int x, int y) {
	return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}
int solution(vector<vector<int>> board, int r, int c) {
	int answer = 0;
	queue<pip> q;
	point p = { c,r };

	q.push(make_pair(0, p));
	while (!q.empty()) {

	}

	return answer;
}

int main() {
	return 0;
}