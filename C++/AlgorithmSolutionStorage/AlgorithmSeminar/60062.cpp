#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int N;
vector<int> di, map;
int answer;

int func(vector<int> dist) {
	vector<int> v=map;
	for (int j = 1; j < v.size(); j++) {
		int cur = 0;
		for (int i = 0; i < dist.size(); i++) {
			int k = v[cur] + dist[i];

			while (cur < v.size() && v[cur] <= k)cur++;

			if (cur == v.size())
				return dist.size();
		}
		vector<int>::iterator it = v.begin();
		int fi = v[0]+N;
		v.erase(it); v.push_back(fi);
	}
	return -1;
}

int people(vector<int> p, int dep, int limit) {
	if (dep > limit) {
		vector<int> v;
		for (int i = 1; i <= limit; i++)
			for (int j = 0; j < p.size(); j++) {
				if (p[j] == i)v.push_back(di[j]);
			}
		return func(v);
	}
	int min = p.size() + 1;
	for (int i = 0; i < p.size(); i++) {
		if (p[i])continue;

		p[i] = dep;
		int k=people(p, dep + 1, limit);
		if (k>0&&k < min)min = k;
		p[i] = 0;
	}
	return min;
}

int solution(int n, vector<int> weak, vector<int> dist) {
	N = n; map = weak; di = dist;
	answer= dist.size() + 1;

	vector<int> v(weak.size()), p(dist.size());

	for (int i = 1; i <= dist.size(); i++) {
		int k = people(p, 1, i);
		if (k>=0&&k < answer)answer = k;
	}
	if (answer == dist.size() + 1)return -1;
	return answer;
}

int main() {
	int n = 12;
	//vector<int> weak{ 1,5,6,10 };
	//vector<int> dist{ 1,2,3,4 };

	vector<int> weak{ 1,3,4,9,10 };
	vector<int> dist{ 3,5,7 };

	cout << solution(n, weak, dist);
	return 0;
}

/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> map;
int answer;

int func(vector<int> dist, vector<int> visit, int dep) {
	if (dep == dist.size()
		||dep>=answer)return dep;

	int c = 1, min = dist.size() + 1;
	for (int i = 0; i < visit.size(); i++)
		if (!visit[i])c = 0;
	if (c) {
		return dep;
	}

	vector<int> temp = visit;

	for (int i = 0; i < visit.size(); i++) {
		if (visit[i])continue;
		int t;

		for (int j = 0; j <= dist[dep]; j++) {
			int cur = (map[i] + j) % N;

			for (int k = 0; k < visit.size(); k++)
				if (map[k] == cur)visit[k] = 1;
		}
		t = func(dist, visit, dep + 1);
		if (t < min)min = t;
		visit = temp;

		for (int j = 0; j <= dist[dep]; j++) {
			int cur = (map[i] - j + N) % N;

			for (int k = 0; k < visit.size(); k++)
				if (map[k] == cur)visit[k] = 1;
		}
		t = func(dist, visit, dep + 1);
		if (t < min)min = t;
		visit = temp;

	}

	return min;
}

int solution(int n, vector<int> weak, vector<int> dist) {
	N = n; map = weak;
	answer= dist.size() + 1;

	vector<int> v(weak.size());

	do {
		int k = func(dist, v, 0);
		if (k < answer)answer = k;
		if(answer==1)return 1;
	} while (next_permutation(dist.begin(), dist.end()));
	return answer;
}
*/