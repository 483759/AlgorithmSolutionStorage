//#include <cstdio>
//int apb[26], i = 0;	//apb: 특정 알파벳이 문자열의 어디에 위치해 있는지 저장하는 배열
//char s[27];			//원래 문자열을 저장하는 배열
//int main() {
//	while (scanf(" %c", &s[i]) != EOF) {	//한글자씩 입력을 받아서
//		apb[s[i] - 97] = i + 1;	//글자의 위치(숫자)를 알파벳 배열에 저장한다
//		i++;
//	}
//	if (i < 26) {		//길이가 26 미만이라면 
//		for (int j = 0; j < 26; j++)
//			if (!apb[j]) {	//apb가 0이라는건 s에 속한 문자가 아니라는 것
//				s[i++] = j + 97;	//사용하지 않은 알파벳 중 가장 빠른것을 추가
//				printf("%s", s);
//				return 0;
//			}
//	}
//	else {	//길이가 26이라면
//		for (int j = 25; j >= 0; j--)	//맨 뒤 문자열부터 검사하기 위한 for문
//			for (int k = s[j] - 96; k < 26; k++)	//현재 위치의 알파벳부터 사전 순서대로 증가
//				//ex. s[j]=='x' -> k=25(24번째 알파벳인 x 다음 알파벳들) -> y,z 검사
//				if (apb[s[j] - 97] < apb[k]) {	//만약 해당 알파벳이 출현한 위치가 나보다 뒤라면?
//					s[j] = k + 97;	//현재 위치의 알파벳을 해당 알파벳으로 교체
//					s[j + 1] = '\0';	//다음 문자는 null문자로
//					printf("%s", s);	//출력
//					return 0;
//				}
//	}
//	printf("-1");	//이것을 만족하지 않는 문자열(내림차순 정렬된 문자열)은 -1출력
//	return 0;
//}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string s;
vector<char> v;
int main() {
	cin >> s;
	for (char c : s)    //기존의 알파벳들을 순서대로 vector에 push
		v.push_back(c);
	for (int i = 0; i < 26; i++)
		if (s.find('a' + i) >= s.length()) {    //알파벳을 처음부터 순회하면서 s에 포함되지 않는 알파벳들을 탐색
			v.push_back('a' + i);    //vector의 맨 뒤에 추가
		}
	if (s.length() < 26) {    //문자열의 길이가 26보다 작을 경우
		for (int i = 0; i <= s.length(); i++)    //기존의 s의 길이 + 1만큼 vector에서 꺼내 출력
			cout << v[i];
		cout << '\n';
	}
	else if (s == "zyxwvutsrqponmlkjihgfedcba")    //마지막 단어
		cout << -1 << '\n';
	else {
		next_permutation(v.begin(), v.end());    //vector에서 다음 순열을 구한다
		for (int i = 0; i < s.length(); i++) {    //기존의 문자열과 달라진 지점이 나올 때 까지 출력
			cout << v[i];
			if (v[i] != s[i])break; //출력 후 종료
		}
		cout << '\n';
	}
}