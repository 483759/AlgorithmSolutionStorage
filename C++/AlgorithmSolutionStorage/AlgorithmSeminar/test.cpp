#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int apb[26] = { 0 }, ans=0,n;
	char c;
	cin >> n>> s;

	for (int i = 0; i < n; i++) {
		apb[s[i]]++;
	}
	return 0;
}