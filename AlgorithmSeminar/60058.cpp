#include <cstdio>
#include <pthread.h>

//#include <string>
//#include <stack>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//bool balance(string p) {
//	int s = 0;
//	for (int i = 0; i < p.length(); i++)
//		if (p[i] == '(')s++;
//		else s--;
//	return s ? 0 : 1;
//}
//
//bool correct(string p) {
//	stack<int> s;
//	for (int i = 0; i < p.length(); i++) {
//		if (p[i] == '(')s.push(1);
//		else {
//			if (s.empty())return false;
//			s.pop();
//		}
//	}
//	if (!s.empty())return false;
//	else return true;
//}
//
//string solution(string p) {
//	if (p.empty())return p;
//	string answer = "";
//
//	int arr[2] = { 0 };
//	for (int i = 0; i <= p.length(); i++) {
//		string u = p.substr(0, i),v=p.substr(i,p.length()-i);
//		if (u.empty())continue;
//		if (!balance(u) || !balance(v))continue;
//
//		if (correct(p.substr(0, i))) {
//			string r=solution(v);
//			answer = u + r;
//			break;
//		}
//		else {
//			string e = "(";
//			e += solution(v);
//			e += ")";
//			for (int j = 1; j < u.length() - 1; j++)
//				if (u[j] == '(')e += ')';
//				else e += '(';
//			return e;
//		}
//	}
//
//	return answer;
//}
//int main() {
//	string s = "()))((()";
//	cout << solution(s) << '\n';
//	return 0;
//}