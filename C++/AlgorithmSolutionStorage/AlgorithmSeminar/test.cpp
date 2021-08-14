#include <string>
#include <vector>

using namespace std;

int s;

long long dp(int cur) {
    if (cur == s) {
        return 1;
    }

    return dp(cur + 1) + dp(cur + 2) + dp(cur + 3);
}

long long solution(int numOfStairs) {
    long long answer = 0;
    s = numOfStairs;
    return answer;
}

//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//vector<int> solution(vector<int> fruitWeights, int k) {
//    vector<int> answer;
//    priority_queue<int, vector<int>, greater<>> pq;
//
//    int left = 0, right = 0,m=0;
//    for (int i = 0; i < m - 1; i++) {
//        pq.push(fruitWeights[i]);
//    }
//    answer.push_back(pq.top());
//
//    int size = fruitWeights.size();
//    while (right < size) {
//        //pq.pop()
//    }
//
//    return answer;
//}