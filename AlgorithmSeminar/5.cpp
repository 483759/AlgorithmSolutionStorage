#include <iostream>
#include <vector>
#define ull unsigned long long
using namespace std;
int t, l, r,n;
struct point { ull x, y; };
vector<point> v;
int main() {
	cin >> t;
	for (int a = 0; a < t; a++) {
		cin >> l >> r;
		cin >> n;
		for (int i = 0,x,y; i < n; i++) {
			cin >> x >> y;
			v.push_back({ x,y });
		}
	}
	return 0;
}