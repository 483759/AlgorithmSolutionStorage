#include <iostream>

#include <string>
#include <vector>

using namespace std;

void numOfCase(int sum, int bound, int n, vector<int>& v, vector<int>& apeach, vector<vector<int>>& cases) {
    if (sum == n) {
        cases.push_back(v);
        return;
    }

    for (int i = bound; i >= 0; i--) {
        if (v[i] > apeach[i])continue;
        v[i]++;
        numOfCase(sum + 1, i, n, v, apeach, cases);
        v[i]--;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer = { -1 };
    vector<int> empty_vector(11, 0);
    vector<vector<int>> cases;
    int best_score_gap = 0;

    numOfCase(0, 10, n, empty_vector, info, cases);

    int len = cases.size();
    for (int i = 0; i < len; i++) {
        int lion_score = 0, apeach_score=0;
        for (int j = 0; j < 11; j++) {
            if (cases[i][j] == 0 && info[j] == 0)continue;

            if (cases[i][j] > info[j])
                lion_score += 10 - j;
            else
                apeach_score += 10 - j;
        }
        if ((lion_score > apeach_score) && ((lion_score - apeach_score) > best_score_gap)) {
            best_score_gap = lion_score - apeach_score;
            answer = cases[i];
        }
    }

    return answer;
}

int main() {
    //vector<int> s = solution(9, { 0,0,1,2,0,1,1,1,1,1,1 });
    //vector<int> s = solution(1, { 1,0,0,0,0,0,0,0,0,0,0 });
    vector<int> s= solution(5, { 2,1,1,1,0,0,0,0,0,0,0 });
    for (int i : s)
        cout << i<<" ";
    return 0;
}