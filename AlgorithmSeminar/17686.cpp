#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef struct {
	string HEAD;
	string NUMBER;
	string TAIL;
}file;

bool cmp(file A, file B) {
	string lowA = A.HEAD, lowB = B.HEAD;
	transform(lowA.begin(), lowA.end(), lowA.begin(), ::tolower);
	transform(lowB.begin(), lowB.end(), lowB.begin(), ::tolower);
	if (lowA.compare(lowB) != 0)return lowA.compare(lowB);

	int numA = stoi(A.NUMBER);
	int numB = stoi(B.NUMBER);
	return numA < numB;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<file> v;

	for (auto f:files) {
		v.push_back({ "","","" });
		int idx = 0, n = 0;
		for (int i = 0; i < f.length();i++) {
			switch (idx) {
			case 0:
				if (isdigit(f[i])) {
					i--; idx = 1; break;
				}
				v.back().HEAD.push_back(f[i]);
				break;
			case 1:
				if (!isdigit(f[i])||n>=5) {
					i--; idx = 2; break;
				}
				if(f[i]!=0&&n!=0)n++;
				v.back().NUMBER.push_back(f[i]);
				break;
			case 2:
				v.back().TAIL.push_back(f[i]);
				break;
			}
		}
	}

	stable_sort(v.begin(), v.end(), cmp);
	
	for (auto str : v) {
		answer.push_back(str.HEAD + str.NUMBER + str.TAIL);
	}
	return answer;
}

int main() {
	vector<string> s;
	//s=solution({ "A123456", "B2345", "A1234" });
	//s= solution({ "A1234cccc", "a1234bb", "A123" });
	//s = solution({"MUZI01.zip", "muzi1.png"});
	//s = solution({ "muzi1.png","MUZI01.zip" });
	s = solution({ "a014", "a012", "a13", "a0000000000000011", "a10", "A9", "a9" });
	for (auto x : s)
		cout << x << '\n';
	return 0;
}