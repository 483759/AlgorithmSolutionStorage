#include <iostream>
#include <string>
#define max(a,b) a>b?a:b
using namespace std;
string s1, s2, ans;
int val[1001][1001],c1,c2,pre;
int main() {
	cin >> s1;
	cin >> s2;
	c1 = s1.size(); pre=c2 = s2.size();
	for (int i = 1; i <= c2; i++) {
		for (int j = 1; j <= c1; j++) {
			if (s1[j-1] == s2[i-1]) {
				val[i][j] = val[i - 1][j - 1] + 1;
			}
			else {
				val[i][j] = max(val[i - 1][j], val[i][j - 1]);
			}
		}
	}
	for(int i=c1;i>0;i--)
		for (int j = pre; j > 0; j--) {
			if ((val[i][j] > val[i][j - 1]) && (val[i][j] > val[i - 1][j])) {
				ans.push_back(s1[j-1]); pre = j - 1; }
			if (val[i - 1][j] > val[i][j - 1]) { pre = j; break; }
		}
	cout << val[c1][c2]<<'\n';
	for (int i = ans.size()-1; i >= 0; i--)cout << ans[i];
	return 0;
}