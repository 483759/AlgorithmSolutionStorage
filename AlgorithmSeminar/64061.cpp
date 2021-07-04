#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;

	for each (int var in moves)
	{
		var--;

		for (int i = board.size()-1; i >= 0; i--)
		{

		}
	}
	return answer;
}

int main() {
	return 0;
}

//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int solution(vector<vector<int>> board, vector<int> moves) {
//	int answer = 0;
//	stack<int> s;
//
//	for(auto cur:moves){
//		int i = 0; cur--;
//		while (i < board.size() && !board[i][cur])
//			i++;
//		if (i == board.size())continue;
//
//		if (!s.empty() && s.top() == board[i][cur]) {
//			s.pop();
//			answer+=2;
//		}
//		else
//			s.push(board[i][cur]);
//		board[i][cur] = 0;
//	}
//	return answer;
//}
//
//int main() {
//	vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
//	vector<int> moves = { 1,5,3,5,1,2,1,4 };
//	solution(board, moves);
//}