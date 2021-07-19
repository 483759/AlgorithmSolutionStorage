#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, double> A, pair<int, double> B) {
	if (A.second == B.second)
		return A.first < B.first;
	return A.second > B.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<int, double>> v;
	int count[502] = { 0 };

	for (auto x : stages)
		count[x]++;

	int sum = stages.size();
	for (int i = 1; i <= N; i++) {
		v.push_back(make_pair(i, (double)count[i] / sum));
		sum -= count[i];
	}

	sort(v.begin(), v.end(), cmp);

	for (auto x : v)
		answer.push_back(x.first);

	return answer;
}
int main() {
	int n = 5;
	vector<int> v;
	vector<int> answer;
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(6);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);
	answer = solution(n,v);
	for (auto x : answer)
		cout << x << endl;
	return 0;
}