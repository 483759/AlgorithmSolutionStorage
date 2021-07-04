#include <iostream>
#include <string>
using namespace std;

int t;
string s;

//종이를 접었을 때 대칭되는 부분의 값이 똑같으면 안 된다
//계속해서 반으로 접으므로 현재 mid기준 왼쪽과 오른쪽을 재귀 호출해줘야 함
bool dnc(int left, int right) {
	int mid = (left + right) / 2;
	if (left + 1 == right) {	//1칸은 무조건 됨
		return true;
	}
	else {
		for (int i = 1; mid + i != right; i++) {
			if (s[mid - i] == s[mid + i])return false;	//mid기준으로 양옆으로 퍼져서 검사하면서 대칭되는 부분의 값이 정확히 반대인지 검사
		}
		return dnc(left, mid) & dnc(mid + 1, right);
		//왼쪽 part와 오른쪽 part가 둘 다 true여만 true
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
