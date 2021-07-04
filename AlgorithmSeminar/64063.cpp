#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> m;

long long func(long long x) {
	if (m.find(x) == m.end()) {
		m.insert(make_pair(x, x + 1));
		return x;
	}
	return m.find(x)->second = func(m.find(x)->second);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (auto x : room_number) {
		answer.push_back(func(x));
	}
	return answer;
}

int main() {
	auto ans = solution(10, {1,3,4,1,3,1});
	for (auto x : ans)
		printf("%lld ", x);
	return 0;
}