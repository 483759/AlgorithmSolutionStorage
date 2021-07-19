#include <iostream>
#include <vector>
#include <string>
using namespace std;

string str, bomb, ans;
vector<int> idx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str >> bomb;
	idx.push_back(-1);
	//ans.push_back(' ');

	for (char x : str) {
		if (x == bomb[0])idx.push_back(0);
		else if (x == bomb[idx.back()+1])
			idx.push_back(idx.back() + 1);
		else idx.push_back(-1);

		ans.push_back(x);
		if(idx.back()==bomb.length()-1)
			for (int i = 0; i < bomb.length(); i++) {
				idx.pop_back();
				ans.pop_back();
			}
	}
	if (ans.length() == 0)cout << "FRULA";
	else cout << ans;
}

//#include <string>
//#include <vector>
//#include <cstring>
//#include <iostream>
//
//using namespace std;
//
//vector<vector<int>> rotate(vector<vector<int>> key) {	//key�� ȸ������ ��ȯ�ϴ� �Լ�
//	vector<vector<int>> v(key.size());
//
//	for (int i = 0; i < key.size(); i++) {
//		v[i] = vector<int>(key[i].size(), 0);
//
//		for (int j = 0; j < key[i].size(); j++)
//			v[i][j] = key[key[i].size() - 1 - j][i];	//90�� ȸ��
//	}
//	return v;
//}
//
//bool match(vector<vector<int>> key, vector<vector<int>> lock, int i, int j) {
//	for (int y = 0; y < lock.size(); y++)
//		for (int x = 0; x < lock[y].size(); x++) {	//key�� �� ���� i, �� ���� j��ŭ �̵���Ų �� lock�� ��
//			int a = y + i, b = x + j;	//key�� ���� ��ǥ
//			if (a < 0 || a >= key.size() || b < 0 || b >= key.size()) {	//���� �ڹ��踦 ��� key���
//				if (!lock[y][x])return false;	//�ڹ����� Ȩ�� ä������ �ʾ����� false ��ȯ
//				continue;
//			}
//			if ((lock[y][x] ^ key[a][b]) == 0)return false;	//���� Ȩ-Ȩ�̰ų� ����-����� false��ȯ
//		}
//	return true;	//������ �ɸ��� �ʾ��� ��� Ȩ-���� ����-Ȩ�� �� �´°Ŷ� true
//}
//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//	bool answer = false;
//	int n = lock.size(), m = key.size();
//
//	for (int k = 0; k < 4; k++) {	//key�� 4ȸ�� ��Ű�鼭 ��
//		for (int i = -n; i <= n; i++)
//			for (int j = -n; j <= n; j++) {	//key�� -n ~ +n ��ŭ �̵���Ű�鼭 ��(��� -m ~ n������ ���ϸ� �ȴٰ� �����ߴµ� �� �̰��� ���� �𸣰���)
//				if (match(key, lock, i, j))	//���� �ϳ��� �´� case�� �ִٸ�
//					return true;	//true ��ȯ
//			}
//		key = rotate(key);
//	}
//	return answer;	//���� ������ �ȵǴ� ���
//}
//int main() {
//	cout << solution({ {0, 0, 0},{1, 0, 0},{1, 1, 1} }, { {1,1,1},{1,1,0},{1,0,1} }) << endl;
//	return 0;
//}


//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//	bool answer = true;
//	int temp[25][25] = { 0 }, locks[65][65] = { 0 }, copy[65][65];
//	const int start = lock.size();
//
//	for (int i = 0; i < lock.size(); i++)
//		for (int j = 0; j < lock.size(); j++)
//			locks[lock.size() + i][lock.size() + j] = lock[i][j];
//
//	for (int k = 0; k < 4; k++) {
//		for (int i = 0; i < key.size(); i++)
//			for (int j = 0; j < key.size(); j++)
//				temp[i][j] = key[key.size() - 1-j][i];
//		for (int i = 0; i < key.size(); i++)
//			for (int j = 0; j < key.size(); j++)
//				key[i][j] = temp[i][j];
//
//		for (int i = 0; i < lock.size() * 2; i++)
//			for (int j = 0; j < lock.size() * 2; j++) {   //��� ��ǥ�� ���� copy&paste
//				memset(copy, 0, sizeof(copy));
//
//				for (int a = 0; a < key.size(); a++)
//					for (int b = 0; b < key.size(); b++)
//						copy[i + a][j + b] = key[a][b];   //copy�迭�� ����
//
//				bool check = true;
//				for (int a = start; a < start*2; a++)
//					for (int b = start; b < start * 2; b++)
//						if (!(locks[a][b] ^ copy[a][b])) {
//							check = false;
//							break;
//						}
//				if (check)return true;
//			}
//	}
//	return false;
//}
//