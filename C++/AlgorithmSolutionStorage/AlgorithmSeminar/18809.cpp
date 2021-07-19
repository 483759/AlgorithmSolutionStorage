#include <cstdio>
#include <cstring>

#define ALPHABETS 26

// Convert char to array index
// All are base on capital
int char_to_index(char c) {
	if (c >= 'a')return c - 'a';
	return c - 'A';
}

struct Trie {

	bool is_terminal; // this represents end of string
	Trie* children[ALPHABETS];

	// Constructor
	Trie() : is_terminal(false) {
		memset(children, 0, sizeof(children));
	}

	// Delete all children
	~Trie() {
		for (int i = 0; i < ALPHABETS; ++i) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') {
			is_terminal = true;
		}
		else {
			int index = char_to_index(*key);

			if (children[index] == 0)
				children[index] = new Trie();
			children[index]->insert(key + 1);
		}
	}

	Trie* find(const char* key) {
		if (*key == 0) {
			return this;
		}

		int index = char_to_index(*key);
		if (children[index] == 0) {
			return NULL;
		}

		return children[index]->find(key + 1);
	}

	bool string_exist(const char* key) {
		if (*key == 0 && is_terminal) {
			return true;
		}

		int index = char_to_index(*key);
		if (children[index] == 0) {
			return false;
		}
		return children[index]->string_exist(key + 1);
	}

};

int main() {
	Trie* root = new Trie();
	const char* words[5] = { "be", "bee", "can", "cat", "cd" };

	for (int i = 0; i < 5; ++i) {
		printf("insert: %s\n", words[i]);
		root->insert(words[i]);
	}

	printf("\n");

	printf("%s: be\n", root->find("be") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s: can\n", root->find("can") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s: a\n", root->find("a") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s: cat\n", root->find("cat") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s: c\n", root->find("c") != 0 ? "Prefix Exist" : "Prefix Not Exist");

	printf("\n");

	printf("%s: c\n", root->string_exist("c") != 0 ? "String Exist" : "String Not Exist");
	printf("%s: be\n", root->string_exist("be") != 0 ? "String Exist" : "String Not Exist");
	printf("%s: bee\n", root->string_exist("bee") != 0 ? "String Exist" : "String Not Exist");
	printf("%s: candy\n", root->string_exist("candy") != 0 ? "String Exist" : "String Not Exist");
	printf("%s: cd\n", root->string_exist("cd") != 0 ? "String Exist" : "String Not Exist");

	delete root;

	return 0;
}
//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <vector>
//using namespace std;
//typedef struct { int x, y; }point;
//typedef struct { point p; int k, t; }mdc;
//int n, m, G, R, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, dif[] = { 0,0,0,4,3 };
//int map[51][51],visit[51][51],ans;
//vector<point> pg,v;
//void print() {
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++)printf("%d ", map[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//}
//bool safe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }
//void bfs() {
//	int g[51][51],sum=0; memcpy(g, map, sizeof(map));
//	memset(visit, 0, sizeof(visit));
//	queue<point> q;
//	for (auto x:v) {
//		visit[x.y][x.x] = 1; q.push({ x.x,x.y });
//		}
//	while (!q.empty()) {
//		point cur = q.front();	q.pop();
//		if (g[cur.y][cur.x] == 5)continue;
//
//		for (int i = 0; i < 4; i++) {
//			int nx = cur.x + dx[i], ny = cur.y + dy[i];
//			if (!safe(nx, ny) || !g[ny][nx] || g[ny][nx] == 5)continue;
//			if (dif[g[cur.y][cur.x]] ==g[ny][nx]){	//다른 배양액?
//				if (visit[ny][nx] <= visit[cur.y][cur.x])continue;
//				g[ny][nx] = 5; sum++;
//			}if (g[cur.y][cur.x] == g[ny][nx])continue;
//			else {
//				g[ny][nx] = g[cur.y][cur.x];
//				visit[ny][nx] = visit[cur.y][cur.x] + 1;
//				q.push({ nx,ny });
//			}
//		}
//	}
//	if (sum > ans)ans = sum;
//}
//void dfs(int r,int g,int dep) {
//	if (dep == pg.size() || (!r && !g)) {
//		bfs(); 
//		return;
//	}
//	if ((pg.size() - dep) > (r + g))dfs(r, g, dep + 1);
//	int x = pg[dep].x,y=pg[dep].y;
//	if (g > 0) {
//		map[y][x] = 3; v.push_back({ x,y });
//		dfs(r, g - 1, dep + 1);
//		v.pop_back();
//	}
//	if (r > 0) {
//		map[y][x] = 4; v.push_back({ x,y });
//		dfs(r - 1, g, dep + 1);
//		v.pop_back();
//	}
//	map[y][x] = 2;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d%d", &n, &m, &G, &R);
//	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
//	{
//		scanf("%d", &map[i][j]);
//		if (map[i][j] == 2)
//			pg.push_back({ j,i });
//	}
//	dfs(R, G, 0); printf("%d", ans);
//	return 0;
//}