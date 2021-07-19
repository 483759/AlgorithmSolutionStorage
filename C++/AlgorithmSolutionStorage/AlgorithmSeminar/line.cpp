#include <iostream>

#include <string>
#include <vector>

using namespace std;

int cardSum(vector<int> cards,int c, int target) {
	int sum = 0;
	for (auto x : cards)
		sum += x;

	if (c >= 11) {
		return 10;
	}
	else if (c == 1) {
		if (target == 21) {
			if (sum + 11 > 21)return 1;
			else return 1;
		}
		else if (target == 17 || target == 12) {
			if (sum + 11 >= target)return 11;
			else return 1;
		}
	}
	else return c;
}

int solution(vector<int> cards) {
	int answer = -1;
	int state = 1, psum=0,dsum=0,black=0;
	vector<int> player, dealer;
	vector<int>::iterator it = cards.begin();

	while (1) {

		if (it == cards.end())break;
		switch (state)
		{
		case 1:
		case 3:
			psum += cardSum(player, *it, 21);
			player.push_back(cardSum(player, *it, 21));
			it++; state++;
			break;
		case 2:
		case 4:
			dsum = cardSum(dealer, *it, 21);
			dealer.push_back(*it);
			dsum += *it;
			it++; state++;
			break;
		case 5:
			if (psum >= 21) {
				if(psum==21)
				black = 1;
				state = 7;
				break;
			}
			else {
				if(dealer[1]==1||dealer[1]>=7&&psum < 17) {
						psum=cardSum(player, *it, 17);
						player.push_back(*it);
						it++;
						break;
					}
				else if (dealer[1] >= 4 && dealer[1] <= 6) {
					state = 6;
					break;
				}
				else if (psum <= 12) {
					psum = cardSum(player, *it, 12);
					player.push_back(*it);
					it++;
					break;
				}
					
			}
			break;
		case 6:
			if (dsum < 17) {
				dsum = cardSum(dealer, *it, 21);
				dealer.push_back(*it);
				break;
			}
			else {
				state = 7;
				break;
			}
		case 7:
			if (psum > 21)
				answer -= 2;
			else if (dsum > 21)
				answer += 2;
			else if (psum == 21 && black)
				answer += 3;
			
			if (psum > dsum)answer += 2;
			else answer -= 2;


			psum = 0; dsum = 0; player.clear(); dealer.clear();
			black = 0; state = 1;
			break;
		default:
			break;
		}
	}
	return answer;
}

int main() {
	vector<int> c = { 12,7,11,6,2,12 };
	cout << solution(c);
	return 0;
}

//
//#include <string>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//bool map[305][305];
//
//typedef struct { int x, y; }point;
//
//int solution(vector<vector<int>> maze) {
//	int answer = 0;
//	memset(map, 1, sizeof(map));
//	for (int i = 0; i < maze.size(); i++)
//		for (int j = 0; j < maze.size(); j++)
//			map[i + 1][j + 1] = maze[i][j];
//
//	int dir = 0;
//	point cur = { 1,1 }, wall = { 1,0 };
//
//	while (!(cur.x == cur.y && cur.x == maze.size())) {
//		int nx = cur.x + dx[dir], ny = cur.y + dy[dir];
//		point nw = { wall.x + dx[dir],wall.y + dy[dir] };
//
//		if (map[ny][nx]) {
//			dir =(dir+1)%4;
//			wall = { nx,ny };
//			continue;
//		}
//		else if (!map[ny][nx])
//			if (map[nw.y][nw.x]) {
//				cur = { nx,ny };
//				wall = nw;
//				answer++;
//			}
//			else {
//				cur = { nw.x,nw.y };
//				dir = (dir + 3) % 4;
//				answer += 2;
//			}
//
//	}
//	return answer;
//}
//int main() {
//	vector<vector<int>> v = { {0, 1, 0, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}, {1, 0, 1, 0} };
//	cout << solution(v);
//}


	//#include <string>
	//#include <vector>
	//#include <math.h>
	//
	//using namespace std;
	//
	//int m = 9876543210, mnum = 9876543210;
	//
	//int digit(int n) {
	//	int count = 0;
	//	while (1) {
	//		n /= 10;
	//		count++;
	//		if (!n)
	//			return count;
	//	}
	//}
	//
	//void def(int dep, int num) {
	//	if ((num % 10) == num) {
	//		if (dep < m) {
	//			m = dep;
	//			mnum = num;
	//		}
	//		return;
	//	}if (dep >= m)return;
	//	int t = 10;
	//	while ((num / t)) {
	//		int a = num / t, b = num % t;
	//		if (!b || digit(a)+digit(b)==digit(num))
	//			def(dep + 1, a + b);
	//		t *= 10;
	//	}
	//}
	//
	//vector<int> solution(int n) {
	//	vector<int> answer;
	//	def(0, n);
	//	answer.push_back(m);
	//	answer.push_back(mnum);
	//	return answer;
	//}

	//int main() {
	//	solution(73425);
	//	return 0;
	//}

	/*
	#include <string>
	#include <vector>

	using namespace std;

	int solution(vector<vector<int>> boxes) {
		int answer = 0;
		vector<bool> check(boxes.size(), false);

		for (int i = 0; i < boxes.size(); i++) {
			if (check[i])continue;
			if (boxes[i][0] == boxes[i][1])check[i] = 1;
			for (int j = i + 1; j < boxes.size(); j++) {
				//다른 box 확인

				for(int a=0;a<2;a++)
					for (int b = 0; b < 2; b++)
						if (boxes[i][a] == boxes[j][b]){
							//짝찾음
							int temp = boxes[j][b];
							boxes[j][b] = boxes[i][!a];
							boxes[i][!a] = temp;

							check[i] = true;
						}
				if (check[i])break;
			}
			if (!check[i])
				answer++;
		}

		return answer;
	}

	int main() {
		vector<vector<int>> box = { {1,2},{3,2},{3,1} };
		//{ {1, 2}, {2, 1}, {3, 3}, {4, 5}, {5, 6}, {7, 8} };
		cout << solution(box);
		return 0;
	}




	----------------------




	#include <string>
	#include <vector>
	#include <deque>

	using namespace std;

	vector<int> solution(vector<int> ball, vector<int> order) {
		vector<int> answer, wait;
		vector<int>::iterator it;
		deque<int> dq;

		for (auto b : ball)
			dq.push_back(b);

		for (int j = 0; j <= order.size();j++) {

			//bool check = true;
			//for (it = wait.begin(); it != wait.end(); it++) {
			//	if (check) { check = 0; it = wait.begin(); }
			//	if (dq.empty())break;
			//
			//	if (*it == dq.front()) {
			//		dq.pop_front();
			//		answer.push_back(*it);
			//		check = 1;
			//	}
			//	else if (*it == dq.back()) {
			//		dq.pop_back();
			//		answer.push_back(*it);
			//		check = 1;
			//	}
			//}

			it = wait.begin();
			while (it != wait.end()) {
				if (dq.empty())break;
				if (*it == dq.front()) {
					dq.pop_front();
					answer.push_back(*it);
					it = wait.begin();
				}
				else if (*it == dq.back()) {
					dq.pop_back();
					answer.push_back(*it);
					it = wait.begin();
				}else it++;
			}



			if (j == order.size())break;

			int cur = order[j];

			if (dq.front() == cur) {
				dq.pop_front();
				answer.push_back(cur);
			}
			else if (dq.back() == cur) {
				dq.pop_back();
				answer.push_back(cur);
			}
			else {
				wait.push_back(cur);
			}
		}

		return answer;
	}
	*/