#include <iostream>
#include <vector>
using namespace std;
vector<int> a, b;
int n, t, Answer;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> n;
		for (int i = 0; i < n; i++) { cin >> t; a.push_back(t); }
		for (int i = 0; i < n; i++) { cin >> t; b.push_back(t); }

		Answer = 1;

		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++) {
				int cnt = 0;
				for (int k = 0; k < i; k++)if (a[k] == b[k])cnt++;
				for (int k = i; k <= j; k++)if (a[k] == b[i + j - k])cnt++;
				for (int k = j + 1; k < n; k++)if (a[k] == b[k])cnt++;
				Answer = cnt > Answer ? cnt : Answer;
			}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
		a.clear(); b.clear();
	}
	return 0;
}
//5 2 3 4 7 6 1
//5 1 6 7 4 6 2
//
//5 2 6 4 7 6 1
//
//5 7 4 1 2 6 3
//
//
//
//5 2 1 7 6 3