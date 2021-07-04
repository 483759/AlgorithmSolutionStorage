#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int solution(string s) {
	int answer = s.length();
	for (int i = 1; i <= s.length() / 2; i++) {  //몇 개로 자를건지
		string k, pre;
		vector<pair<int, int>> v;
		for (int j = 0; j < s.length() / i; j++) {
			k = s.substr(j * i, i);
			if (pre == k)v.back().first++;
			else {
				v.push_back({ 1,i });
			}
			pre = k;
		}
		if (s.length() % i)
			v.push_back({ 1,s.length() % i });

		int sum = 0;
		for (auto x : v) {
			if (x.first > 1)
				sum += log10(x.first)+1;
			sum += x.second;
		}
		if (sum < answer)answer = sum;
	}
	return answer;
}

int main() {
	string str;
	for (int i = 0; i < 9; i++)str.push_back('s');
	cout << solution(str);
	return 0;
}