#include <iostream>
#include <string>
using namespace std;
int n;
typedef struct {
	int num[10001];
	int f=-1,b=-1;
	int size() {
		return b - f;
	}
	int empty() {
		return f == b;
	}
	int front() {
		if (empty())return -1;
		return num[f];
	}
	int back() {
		if (empty())return -1;
		return num[b];
	}
	void push_front(int k) {
		if (f == 0) {
			b++;
			for (int i = b; i > f; i--)
				num[i] = num[i - 1];
			num[f] = k;
			return;
		}
		else {
			f--;
			num[f] = k;
		}
	}
}deque;
string s;
int main() {
	scanf("%d", &n);
	while (n--) {
		cin >> s;

		if (s == "front") {

		}
	}
	return 0;
}