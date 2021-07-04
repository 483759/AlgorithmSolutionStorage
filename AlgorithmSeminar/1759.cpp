#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> v;
set<string> pass;

int l, c;
char vow[] = { 'a','e','i','o','u' };

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char chr;
		cin >> chr;
		v.push_back(chr);
	}
	sort(v.begin(), v.end());

	vector<bool> ps(c, 0);
	for (int i = ps.size() - 1; i >= c - l; i--)
		ps[i] = 1;

	do {
		string s;
		int C = 0, V = 0;

		for (int i = 0; i < c; i++) {
			if (!ps[i])continue;
			switch (v[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				V++;
				break;
			default:
				C++;
			}
			s.push_back(v[i]);
		}

		if (V >= 1 && C >= 2) {
			pass.insert(s);
		}

	} while (next_permutation(ps.begin(), ps.end()));
	
	for (auto s : pass) {
		cout << s<<'\n';
	}
}

//#include <iostream>
//#include <vector>
//#include <set>
//#include <string>
//using namespace std;
//int l, c;
//bool arr[26],s[26];
//vector<char> vew, con;
//set<string> ss;
//void selectCon(int dep,int t,int k) {
//	if (dep == t) {
//		string st = "";
//		for (int i = 0; i < 26; i++)
//			if (s[i])st+=i+'a';
//		ss.insert(st);
//		return;
//	}
//	for (int i = k; i < con.size();i++) {
//		s[con[i] - 'a'] = 1;
//		selectCon(dep + 1, t,i+1);
//		s[con[i] - 'a'] = 0;
//	}
//}
//void selectVew(int dep,int t,int k) {
//	if (dep==t) {
//		selectCon(0,l-t,0);
//		return;
//	}
//	for (int i = k; i < vew.size(); i++) {
//		s[vew[i] - 'a'] = 1;
//		selectVew(dep + 1, t, i+1);
//		s[vew[i] - 'a'] = 0;
//	}
//}
//int main() {
//	//freopen("input.txt", "r", stdin);
//	arr[0] = arr['e' - 'a'] = arr['i' - 'a'] = arr['o' - 'a'] = arr['u' - 'a'] = 1;
//	cin >> l >> c;
//	for (int i = 0; i < c; i++) {
//		char k;
//		cin >> k;
//		if (arr[k - 'a'])vew.push_back(k);
//		else con.push_back(k);
//	}
//	for (int i = 1; i <= l - 2; i++)
//		selectVew(0, i,0);
//	for (auto k : ss) {
//		cout << k << '\n';
//	}
//	return 0;
//}
//#include <cstdio>
//int L, C, j;
//bool apb[26],a[26], vew[26] = { 1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1 };
//char str[18];
//void func(int d, int c, int v, int s) {
//	if (d == L) {
//		if (c < 2 || v < 1)return;
//		for(int i=0;i<26;i++)if(a[i])printf("%c",i+'a');
//		printf("\n");
//		return;
//	}
//	for (int i = s; i < C; i++) {
//		a[str[i]-'a'] = 1;
//		if (vew[str[i] - 'a'])func(d + 1, c, v + 1, i + 1);
//		else func(d + 1, c + 1, v, i + 1);
//		a[str[i] - 'a'] = 0;
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	char K;
//	scanf("%d%d", &L, &C);
//	for (int i = 0; i < C; i++) {
//		scanf(" %c", &K);
//		apb[K - 'a'] = true;
//	}
//	for (int i = 0; i < 26; i++) {
//		if (apb[i])
//			str[j++] = i + 'a';
//	}
//	str[j] = '\n';
//	func(0, 0, 0,0);
//	return 0;
//}
//#include <cstdio>
//#include <string.h>
//int L, C, j;
//bool apb[27];
//char c[16];
//
//bool isVew(char K) {
//	bool a;
//	switch (K) {
//	case 'a':
//	case 'e':
//	case 'i':
//	case 'o':
//	case 'u':
//		a = true;
//		break;
//	default:
//		a= false;
//		break;
//	}
//	return a;
//}
//void func(char *str, int idx, int con, int vew) {
//	char s[16] = { NULL }, K;
//	if (con + vew == L) {
//		if (con >= 2 && vew >= 1)
//			printf("%s\n", str);
//		return;
//	}
//	K = c[idx];
//	if (!con && !vew)
//		s[0] = c[idx];
//	else {
//		strcpy(s, str);
//		s[con + vew] = c[idx];
//	}
//	if (isVew(c[idx]))vew++;
//	else con++;
//	for (int i = idx; i < C; i++)
//		func(s, idx + 1, con, vew);
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	char K;
//	scanf("%d%d", &L, &C);
//	for (int i = 0; i < C; i++) {
//		scanf(" %c", &K);
//		apb[K - 'a'] = true;
//	}
//	for (int i = 0; i < 27; i++) {
//		if (apb[i])
//			c[j++] = i + 'a';
//	}
//	c[j] = '\n';
//	func(NULL, 0, 0, 0);
//	return 0;
//}