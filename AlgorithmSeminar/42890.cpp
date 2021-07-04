#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int func(vector<int> col, vector<vector<string>> relation) {
	int ans = relation[0].size();
	vector<vector<string>> tuple;

	for (auto x : relation) {
		vector<string> key;

		for (auto c : col) key.push_back(x[c-1]);

		for (auto k : tuple) {
			bool b = false;
			for (int i = 0; i < k.size(); i++)
				if (key[i] != k[i])b = true;

			if (!b)return relation[0].size()+1;
		}
		tuple.push_back(key);
	}
	return col.size();
}

int solution(vector<vector<string>> relation) {
	int answer = 0;

	vector<vector<int>> cdd;
	vector<int> num;
	vector<int> v(relation[0].size(), 0);
	for (int i = 1; i <= relation[0].size(); i++)num.push_back(i);
	
	for (int i = 1; i <= relation[0].size(); i++) {
		v[relation[0].size() - i] = 1;
		
		do {
			vector<int> vec;
			for (int j = 0; j < v.size(); j++)
				if (v[j] == 1)
					vec.push_back(num[j]);

			bool cnt=false;
			for (auto x : cdd) {
				int check = x.size();
				
				for (int i = 0; i < x.size(); i++) {
					for (int j = 0; j < vec.size(); j++)
						if (x[i] == vec[j])
							check--;
				}

				if (!check)cnt=true;
			}
			if (cnt)continue;

			int ret = func(vec, relation);
			if (ret != relation[0].size()+1) {
				answer++;
				cdd.push_back(vec);
			}

		} while (next_permutation(v.begin(), v.end()));
	}
	return answer;
}

int main() {
	vector<vector<string>> v={{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}};
	
	cout << solution(v);
	return 0;
}