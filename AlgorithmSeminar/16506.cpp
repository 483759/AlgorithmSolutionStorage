#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;
map<string, string> m;
string str;
stack<int> s[3];
int rd, ra, rb, n;
bool c;
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	m.insert({ "ADD", "00000" });
	m.insert({ "ADDC", "00001" });
	m.insert({ "SUB", "00010" });
	m.insert({ "SUBC", "00011" });
	m.insert({ "MOV", "00100" });
	m.insert({ "MOVC", "00101" });
	m.insert({ "AND", "00110" });
	m.insert({ "ANDC", "00111" });
	m.insert({ "OR", "01000" });
	m.insert({ "ORC", "01001" });
	m.insert({ "NOT", "01010" });
	m.insert({ "MULT", "01100" });
	m.insert({ "MULTC", "01101" });
	m.insert({ "LSFTL", "01110" });
	m.insert({ "LSFTLC", "01111" });
	m.insert({ "LSFTR", "10000" });
	m.insert({ "LSFTRC", "10001" });
	m.insert({ "ASFTR", "10010" });
	m.insert({ "ASFTRC", "10011" });
	m.insert({ "RL", "10100" });
	m.insert({ "RLC", "10101" });
	m.insert({ "RR", "10110" });
	m.insert({ "RRC", "10111" });
	for (int j = 0; j < n; j++) {
		string st;
		cin >> str >> rd >> ra >> rb;
		st = m.find(str)->second;
		cout << st + "0";
		if (st[4] == '1')c = true;
		else c = false;
		for (int i = 0; i < 3; i++) {
			s[0].push(rd & 1);
			s[1].push(ra & 1);
			rd >>= 1; ra >>= 1;
		}
		for (int i = 0; i < (c ? 4 : 3); i++) {
			s[2].push(rb & 1); rb >>= 1;
		}
		for (int i = 0; i < 3; i++) {
			cout << s[0].top(); s[0].pop();
		}
		for (int i = 0; i < 3; i++) {
			cout << s[1].top(); s[1].pop();
		}
		for (int i = 0; i < (c ? 4 : 3); i++) {
			cout << s[2].top(); s[2].pop();
		}
		if (!c)cout << "0";
		cout << '\n';
	}
	return 0;
}