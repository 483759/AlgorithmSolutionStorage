#include <iostream>
#include <string>
using namespace std;

int t;
string s;

//���̸� ������ �� ��Ī�Ǵ� �κ��� ���� �Ȱ����� �� �ȴ�
//����ؼ� ������ �����Ƿ� ���� mid���� ���ʰ� �������� ��� ȣ������� ��
bool dnc(int left, int right) {
	int mid = (left + right) / 2;
	if (left + 1 == right) {	//1ĭ�� ������ ��
		return true;
	}
	else {
		for (int i = 1; mid + i != right; i++) {
			if (s[mid - i] == s[mid + i])return false;	//mid�������� �翷���� ������ �˻��ϸ鼭 ��Ī�Ǵ� �κ��� ���� ��Ȯ�� �ݴ����� �˻�
		}
		return dnc(left, mid) & dnc(mid + 1, right);
		//���� part�� ������ part�� �� �� true���� true
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> s;
		cout << (dnc(0, s.length()) ? "YES" : "NO") << '\n';
	}
	return 0;
}
