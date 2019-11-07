#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
int r, s, e, t, n;
double ans, d, Sin, deg,cur;
const double pi = 3.14159265359;
struct ob { int l, r, h; };
queue<ob> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	cout << fixed;
	cout.precision(10);
	for (int a = 1; a <= t; a++) {
		cin >> r >> s >> e;
		cin >> n;
		ans = 0; cur = s;
		for (int i = 0, l, r, h; i < n; i++) {
			cin >> l >> r >> h;
			q.push({ l,r,h });
		}
		while (!q.empty()) {
			ob o = q.front(); q.pop();
			if (r <= o.h) {
				ans += (o.r - cur - r);
				ans += (o.h - r) * 2;
				ans += (double)r * pi;
				cur = o.r + r;
			}
			else {
				Sin = sqrt((2.0 * o.h*r - o.h*o.h) / (double)(r*r));
				deg = asin(Sin);
				ans += o.r-cur-sqrt(pow(r,2)-pow(r-o.h,2));
				ans += (double)r*deg * 2;
				cur = (double)o.r + r * Sin;
			}
		}
		ans += e - cur;
		cout << "Case #" << a << '\n'<<ans << '\n';
	}
	return 0;
}