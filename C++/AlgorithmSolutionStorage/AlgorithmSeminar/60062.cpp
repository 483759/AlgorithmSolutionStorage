#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void permuation(int p, int dep, vector<int> perm, vector<int>& dist, vector<bool>& check, vector<vector<int>>& friends) {
	if (dep == p) {
		friends.push_back(perm);
		return;
	}

	for (int i = 0; i < dist.size(); i++) {
		if (check[i])continue;

		perm.push_back(dist[i]); check[i] = true;
		permuation(p, dep + 1, perm, dist, check, friends);
		perm.pop_back(); check[i] = false;
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0, len = dist.size();

	for (int p = 1; p <= len; p++) {
		vector<bool> check(len, false);
		for (int i = 0; i < p; i++)check[len - 1 - i] = true;

		vector<vector<int>> friends;
		vector<int> perm; vector<bool> visit(dist.size(), false);
		permuation(p, 0, perm, dist, visit, friends);
		for (auto f : friends) {

			for (int i = 0; i < weak.size(); i++) {
				int cur = 0, w = 0, d = f[0];

				while (cur < p && w < weak.size()) {
					int di = (n + weak[(w + i + 1) % weak.size()] - weak[(w + i) % weak.size()]) % n;
					if (d >= di) {
						w++; d -= di;
					}
					else {
						cur++; w++;
						if (cur < p) d = f[cur];
					}
				}

				if (w == weak.size())
					return p;
			}
		}
	}

	return -1;
}

int main() {
	//printf("%d", solution(12, { 1,5,6,10 }, { 1,2,3,4 }));

	printf("%d", solution(200, { 0, 10, 50, 80, 120, 160 }, { 1, 10, 5, 40, 30 }));
	return 0;
}