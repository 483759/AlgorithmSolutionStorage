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
//vector<vector<int>> rotate(vector<vector<int>> key) {	//key를 회전시켜 반환하는 함수
//	vector<vector<int>> v(key.size());
//
//	for (int i = 0; i < key.size(); i++) {
//		v[i] = vector<int>(key[i].size(), 0);
//
//		for (int j = 0; j < key[i].size(); j++)
//			v[i][j] = key[key[i].size() - 1 - j][i];	//90도 회전
//	}
//	return v;
//}
//
//bool match(vector<vector<int>> key, vector<vector<int>> lock, int i, int j) {
//	for (int y = 0; y < lock.size(); y++)
//		for (int x = 0; x < lock[y].size(); x++) {	//key를 행 기준 i, 열 기준 j만큼 이동시킨 뒤 lock과 비교
//			int a = y + i, b = x + j;	//key의 기준 좌표
//			if (a < 0 || a >= key.size() || b < 0 || b >= key.size()) {	//만약 자물쇠를 벗어난 key라면
//				if (!lock[y][x])return false;	//자물쇠의 홈이 채워지지 않았으면 false 반환
//				continue;
//			}
//			if ((lock[y][x] ^ key[a][b]) == 0)return false;	//만약 홈-홈이거나 돌기-돌기면 false반환
//		}
//	return true;	//위에서 걸리지 않았을 경우 홈-돌기 돌기-홈이 다 맞는거라 true
//}
//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//	bool answer = false;
//	int n = lock.size(), m = key.size();
//
//	for (int k = 0; k < 4; k++) {	//key를 4회전 시키면서 비교
//		for (int i = -n; i <= n; i++)
//			for (int j = -n; j <= n; j++) {	//key를 -n ~ +n 만큼 이동시키면서 비교(사실 -m ~ n까지만 비교하면 된다고 생각했는데 왜 이건지 아직 모르겠음)
//				if (match(key, lock, i, j))	//만약 하나라도 맞는 case가 있다면
//					return true;	//true 반환
//			}
//		key = rotate(key);
//	}
//	return answer;	//전부 돌려도 안되는 경우
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
//			for (int j = 0; j < lock.size() * 2; j++) {   //모든 좌표에 대해 copy&paste
//				memset(copy, 0, sizeof(copy));
//
//				for (int a = 0; a < key.size(); a++)
//					for (int b = 0; b < key.size(); b++)
//						copy[i + a][j + b] = key[a][b];   //copy배열로 복사
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