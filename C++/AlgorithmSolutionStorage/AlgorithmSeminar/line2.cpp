#include <iostream>

#include <string>
#include <vector>
#define APB 26

using namespace std;

string solution(vector<string> research, int n, int k) {
    string answer = "None";
    int best = 0;

    int search[APB][31] = { 0 };
    int issue[APB] = { 0 };
    int apb = 'z' - 'a';

    int len = research.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < research[i].length(); j++) {
            search[research[i][j] - 'a'][i]++;
        }
    }

    for (int i = 0; i < APB; i++) { //모든 알파벳에 대해
        for (int j = 0; j < len-n+1; j++) {   //연속된 n일 동안
            int cnt = 0;
            bool flag = true;
            for (int l = 0; l < n; l++) {
                if (search[i][j + l] < k) {
                    flag = false;
                    break;
                }
                cnt += search[i][j + l];
            }
            if (flag && cnt >= (2 * n * k)) {
                issue[i]++;
                if (issue[i] > best) {
                    answer = i + 'a';
                    best = issue[i];
                }
            }
        }
    }

    return answer;
}

int main() {
    //cout << solution({ "abaaaa","aaa","abaaaaaa","fzfffffffa" }, 2, 2);
    cout << solution({ "yxxy","xxyyy" }, 2, 1);
    return 0;
}