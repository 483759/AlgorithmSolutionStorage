#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a, b, a2,b2;
vector<int> r1, r2;
bool islr() {
	for (int i = 0; i < 4; i++) {
		bool b = 0;
		for (int j = 0; j < 4; j++)if (r1[i] == r2[j])b=1;
		if (!b)return false;
	}
	return true;
}
int tonum(vector<int> v) {
	int num = 0;
	for (int i = 1; i <= 1000; i*=10) {
		num += v.back()*i;
		v.pop_back();
	}
	return num;
}
int main() {
	scanf("%d%d", &a, &b);
	a2 = a; b2 = b;
	for (int i = 1000; i > 0; i /= 10) {
		r1.push_back(a2 / i);
		r2.push_back(b2 / i);
		a2 %= i; b2 %= i;
	}
	while (tonum(r1) != tonum(r2)) {
		if (islr()) {

		}
	}
	return 0;
}