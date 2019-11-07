#include <iostream>
#include <string>
using namespace std;
string str;
int ans;
int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		if (str[i] >= 'a'&&str[i] <= 'z') {
			switch (str[i]) {
			case 'c':
				if (str[i + 1] == '-' || str[i] == '=')i++;
				break;
			case 'd':
				if (str[i + 1] == 'z'&&str[i + 2] == '=')i+=2;
				else if (str[i + 1] == '-')i++;
				break;
			case 'l':
			case 'n':
				if (str[i + 1] == 'j')i++;
				break;
			case 's':
			case 'z':
				if (str[i + 1] == '=')i++;
			default:
				break;
			}
			ans++;
		}
	printf("%d", ans);
	return 0;
}
//#include <iostream>
//#include <string>
//using namespace std;
//string str;
//int ans;
//int main() {
//	cin >> str;
//	for (int i = 0; i < str.length(); i++)
//		if (str[i] >= 'a'&&str[i] <= 'z') {
//			switch (str[i])
//			{
//			case 'c':
//				if (str[i + 1] == '=' || str[i + 1] == '-')i++;
//				break;
//			case 'd':
//				if (str[i + 1] == 'z'&&str[i + 2] == '=')i += 2;
//				else if (str[i + 1] == '-')i++;
//				break;
//			case 'l':
//			case 'n':
//				if (str[i + 1] == 'j')i++;
//				break;
//			case 's':
//				if (str[i + 1] == '=')i++;
//				break;
//			case 'z':
//				if (str[i + 1] == '=')i++;
//			default:
//				break;
//			}
//		}
//	printf("%d", ans);
//	return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//int ans;
//string s[10] = {"c=","c-","dz=","d-","lj","nj","s=","z="},str,temp;
//int main() {
//	cin >> str;
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < str.length() - s[i].length(); j++) {
//			bool t = 1;
//			for (int k = 0; k < s[i].length(); k++) {
//				if (str[j + k] != s[i][k])t = 0;
//			}
//			if (t)ans++;
//		}
//	}
//	printf("%d", ans);
//	return 0;
//}