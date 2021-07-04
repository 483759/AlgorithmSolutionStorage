#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long calculate(vector<long long> num, vector<char> op, vector<char> rank) {
	for (auto x : rank) {
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == x) {
				vector<long long>::iterator it = num.begin() + i;
				long long one = *it, two = *(it + 1);
				num.erase(it, it + 2);

				long long result = 0;
				if (x == '*')
					result = one * two;
				else if (x == '-')
					result = one - two;
				else result = one + two;

				it = num.begin() + i;
				num.insert(it, result);
				vector<char>::iterator ct = op.begin() + i;
				op.erase(ct);
				i--;
			}
		}
	}
	return abs(num[0]);
}

long long solution(string expression) {
	long long answer = 0;
	char str[101];
	vector<char> op;
	vector<long long> num;

	strcpy(str, expression.c_str());
	char* ptr = strtok(str, "+-*");


	while (ptr != NULL) {
		num.push_back(atoi(ptr));
		ptr = strtok(NULL, "+-*");
	}
	for (auto x : expression) {
		if (!(x >= '0' && x <= '9'))
			op.push_back(x);
	}

	vector<char> rank{ '*','+','-' };

	do {
		int k = calculate(num, op, rank);
		if (k > answer)answer = k;
	} while (next_permutation(rank.begin(), rank.end()));

	return answer;
}

int main() {
	cout<<solution("100-200*300-500+20");
	return 0;
}