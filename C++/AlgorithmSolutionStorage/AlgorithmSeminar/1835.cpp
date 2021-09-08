#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> dist(vector<int> v, map<char, int> m) {
	vector<vector<int>> d(8);
	int dx[] = { -1,1 };

	for (int i = 0; i < 8; i++)d[i] = vector<int>(8, 0);

	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 8; j++) {
			d[v[i]][v[j]] = d[v[j]][v[i]] = j - i - 1;
		}
	}
	return d;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	int answer = 0;
	vector<int> v(8);
	vector<int[4]> op(n);
	map<char, int> m;

	for (int i = 0; i < 8; i++)v[i] = i;
	m.insert(make_pair('A', 0));
	m.insert(make_pair('C', 1));
	m.insert(make_pair('F', 2));
	m.insert(make_pair('J', 3));
	m.insert(make_pair('M', 4));
	m.insert(make_pair('N', 5));
	m.insert(make_pair('R', 6));
	m.insert(make_pair('T', 7));

	for (int i = 0; i < n; i++) {
		op[i][0] = m[data[i][0]];
		op[i][1] = m[data[i][2]];
		if (data[i][3] == '=')
			op[i][2] = 0;
		else if (data[i][3] == '<')
			op[i][2] = 1;
		else op[i][2] = 2;
		op[i][3] = data[i][4] - '0';
	}

	do {
		vector<vector<int>> d = dist(v, m);
		bool b = true;
		
		for (auto k : op) {
			if (!b)break;
			switch (k[2]) {
			case 0:
				if (d[k[0]][k[1]] != k[3])b = false;
				break;
			case 1:
				if (d[k[0]][k[1]] >= k[3])b = false;
				break;
			case 2:
				if (d[k[0]][k[1]] <= k[3])b = false;
				break;
			}
		}
		if (b)answer++;
	} while (next_permutation(v.begin(), v.end()));


	return answer;
}

int main() {
	printf("%d",solution(2, {"N~F=0","R~T>2"}));
}