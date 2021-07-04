
//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//int n,ans;
//string str;
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> str;
//
//		stack<char> s;
//		if (str.length() % 2)continue;
//
//		bool a = false, b = false, t = true;
//		for (char c : str) {
//			if (!s.empty() && s.top() == c) 
//				s.pop();
//			else 
//				s.push(c);
//		}
//
//		if (s.empty())ans++;
//	}
//	cout << ans;
//	return 0;
//}
//#include <cstdio>
//#include <stack>
//using namespace std;
//stack<int> s,ans,m;
//int n,arr[1000001];
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//		s.push(arr[i]);
//	}
//
//	m.push(-1);
//	for (int i = n - 1; i >= 0; i--) {
//		while (!s.empty() && (s.size() > i+1)) {
//			if (s.top() > arr[i])
//				m.push(s.top());
//			s.pop();
//		}
//		while (!m.empty()&&m.top() <= arr[i])m.pop();
//		if (!m.empty()&&m.top() > arr[i])
//			ans.push(m.top());
//		else ans.push(-1);
//	}
//	while (!ans.empty()) {
//		printf("%d ", ans.top()); ans.pop();
//	} 
//	return 0;
//}