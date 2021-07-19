#include <iostream>
#include <string>
using namespace std;
int n, num, e,k,m;
string ans;
int main() {
	scanf("%d",&n);
	while(n--){
		string p; int g = 0;
		cin >> p;
		cin >> k >> m;
		while (m >= k) {
			g++; m = m - k + 2;
		}
		if (g > num) {
			ans = p; num = g;
		}e += g;
	}
	cout << e << '\n' << ans;
	return 0;
}