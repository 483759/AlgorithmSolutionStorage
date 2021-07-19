//#include <cstdio>
//int apb[26], i = 0;	//apb: Ư�� ���ĺ��� ���ڿ��� ��� ��ġ�� �ִ��� �����ϴ� �迭
//char s[27];			//���� ���ڿ��� �����ϴ� �迭
//int main() {
//	while (scanf(" %c", &s[i]) != EOF) {	//�ѱ��ھ� �Է��� �޾Ƽ�
//		apb[s[i] - 97] = i + 1;	//������ ��ġ(����)�� ���ĺ� �迭�� �����Ѵ�
//		i++;
//	}
//	if (i < 26) {		//���̰� 26 �̸��̶�� 
//		for (int j = 0; j < 26; j++)
//			if (!apb[j]) {	//apb�� 0�̶�°� s�� ���� ���ڰ� �ƴ϶�� ��
//				s[i++] = j + 97;	//������� ���� ���ĺ� �� ���� �������� �߰�
//				printf("%s", s);
//				return 0;
//			}
//	}
//	else {	//���̰� 26�̶��
//		for (int j = 25; j >= 0; j--)	//�� �� ���ڿ����� �˻��ϱ� ���� for��
//			for (int k = s[j] - 96; k < 26; k++)	//���� ��ġ�� ���ĺ����� ���� ������� ����
//				//ex. s[j]=='x' -> k=25(24��° ���ĺ��� x ���� ���ĺ���) -> y,z �˻�
//				if (apb[s[j] - 97] < apb[k]) {	//���� �ش� ���ĺ��� ������ ��ġ�� ������ �ڶ��?
//					s[j] = k + 97;	//���� ��ġ�� ���ĺ��� �ش� ���ĺ����� ��ü
//					s[j + 1] = '\0';	//���� ���ڴ� null���ڷ�
//					printf("%s", s);	//���
//					return 0;
//				}
//	}
//	printf("-1");	//�̰��� �������� �ʴ� ���ڿ�(�������� ���ĵ� ���ڿ�)�� -1���
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
	for (char c : s)    //������ ���ĺ����� ������� vector�� push
		v.push_back(c);
	for (int i = 0; i < 26; i++)
		if (s.find('a' + i) >= s.length()) {    //���ĺ��� ó������ ��ȸ�ϸ鼭 s�� ���Ե��� �ʴ� ���ĺ����� Ž��
			v.push_back('a' + i);    //vector�� �� �ڿ� �߰�
		}
	if (s.length() < 26) {    //���ڿ��� ���̰� 26���� ���� ���
		for (int i = 0; i <= s.length(); i++)    //������ s�� ���� + 1��ŭ vector���� ���� ���
			cout << v[i];
		cout << '\n';
	}
	else if (s == "zyxwvutsrqponmlkjihgfedcba")    //������ �ܾ�
		cout << -1 << '\n';
	else {
		next_permutation(v.begin(), v.end());    //vector���� ���� ������ ���Ѵ�
		for (int i = 0; i < s.length(); i++) {    //������ ���ڿ��� �޶��� ������ ���� �� ���� ���
			cout << v[i];
			if (v[i] != s[i])break; //��� �� ����
		}
		cout << '\n';
	}
}