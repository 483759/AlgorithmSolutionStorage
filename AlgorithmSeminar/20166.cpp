#include <iostream>
#include <string>
#include <map>
using namespace std;

string board[11],str;
map<string, int> dict;
int n, m, k, dx[] = { 1,1,1,0,-1,-1,-1,0 }, dy[] = {-1,0,1,1,1,0,-1,-1};

int func(int x,int y,int dep) {
	if (board[y][x] != str[dep])return 0;

	if (dep == str.length()-1)return 1;
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		int nx = (x + dx[i] + m*2) % m;
		int ny = (y + dy[i] + n*2) % n;
		if (nx < 0 || nx >= m || ny < 0 || ny >= n)continue;
		if(board[ny][nx]==str[dep+1]) sum += func(nx, ny, dep + 1);
	}
	return sum;
}

int main() {
	freopen("input.txt", "r", stdin);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> board[i];

	while (k--) {
		cin >> str;

		int ans = 0;
		auto key = dict.find(str);
		if (key == dict.end()) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (board[i][j] == str[0])
						ans += func(j, i, 0);
			dict.insert(make_pair(str, ans));
		}
		else
			ans = key->second;
		cout << ans << '\n';
	}
	return 0;
}