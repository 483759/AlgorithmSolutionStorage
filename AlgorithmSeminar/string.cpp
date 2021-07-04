#include <iostream>
#include <string>
using namespace std;
string s, f;
int t = 10,n;
int main() {
	freopen("input.txt", "r", stdin);
	while (t--) {
		int ans = 0;
		cin >> n;
		cin >> f>>s;
		for (int i = 0, j; i < s.size() - f.size()+1; i++) {
			for (j = 0; j < f.size(); j++)
				if (s[i + j] != f[j])break;
			if (j == f.size())
				ans++;
		}
		printf("#%d %d\n", n, ans);
	}
	return 0;
}