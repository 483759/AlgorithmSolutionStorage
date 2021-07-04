#include <cstdio>
#define read getchar
int n, dx[] = { 0,0,1,0 }, dy[] = { 0,0,0,1 }, ans, b;
bool board[2][10][4];
typedef struct _block {
	int k, m, r, c;

	_block(int t, int x, int y, int _m) {
		k = t; r = y; c = x; m = _m;
	}

	void move() {
		while (r < 9) {
			if (k == 1 && board[m][r + 1][c])break;
			else if (k == 3) {
				if (r >= 8)break;
				if (board[m][r + 2][c])break;
			}
			else if (k == 2 && (board[m][r + 1][c] || board[m][r + 1][c + 1]))break;
			r = r + 1;
		}
		board[m][r][c] = board[m][r + dy[k]][c + dx[k]] = 1;
	}
}block;
void gravity(int m, int row) {
	for (int r = row; r >= 3; r--) {
		for (int c = 0; c < 4; c++)
			board[m][r][c] = board[m][r - 1][c];
	}
}
void blockPop(int m) {
	for (int i = 9; i > 5; i--) {
		bool b = 1;
		for (int j = 0; j < 4; j++)
			if (!board[m][i][j])b = 0;
		if (b) {
			gravity(m, i);
			ans++; i++;
		}
	}
	for (int i = 5; i > 3; i--) {
		bool b = 0;
		for (int j = 0; j < 4; j++)
			if (board[m][5][j])b = 1;
		if (b) {
			gravity(m, 9);
		}
	}
}
inline int RI() {
	char now = read();
	int sum = 0, flag = 1;
	while (now <= 32) now = read();
	if (now == '-') flag = -1, now = read();
	while (now >= 48) {
		sum = sum * 10 + (now & 15);
		now = read();
	}
	return flag * sum;
}
void print() {
	for (int k = 0; k < 2; k++) {
		for (int i = 6; i < 10; i++) {
			for (int j = 0; j < 4; j++)
				printf("%d ", board[k][i][j]);
			printf("\n");
		}
		printf("\n");
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	n = RI();
	while (n--) {
		int t, x, y;
		t = RI(); y = RI(); x = RI();
		printf("%d %d %d\n", t, x, y);
		for (int i = 0; i < 2; i++) {
			block cur = block(t, x, y, i);
			cur.move();
			blockPop(i);
			int ny = x, nx = 3 - y;
			x = nx; y = ny;
			if (t == 2)t = 3;
			else if (t == 3) { t = 2; x--; }
		}
		print();
	}
	for (int k = 0; k < 2; k++)
		for (int i = 6; i < 10; i++)
			for (int j = 0; j < 4; j++)if (board[k][i][j])b++;
	printf("%d\n%d", ans, b);
	return 0;
}

//#include <cstdio>
//int n, dx[] = { 0,0,1,0 }, dy[] = { 0,0,0,1 };
//int board[2][10][4],ans,b;
//typedef struct _block{
//	int k,m,r,c;
//
//	_block(int t,int x,int y,int _m) {
//		k = t; r = y; c = x; m = _m;
//	}
//
//	void move() {
//		while (r<9) {
//			if (k==1 && board[m][r + 1][c])break;
//			else if (k == 3) {
//				if (r >= 8)break;
//				if(board[m][r + 2][c])break;
//			}
//			else if (k == 2 && (board[m][r + 1][c] || board[m][r + 1][c + 1]))break;
//			r = r + 1;
//		}
//		board[m][r][c] = board[m][r + dy[k]][c + dx[k]] = 1;
//	}
//}block;
//void gravity(int m,int row) {
//	for (int r = row; r >= 3; r--) {
//		for (int c = 0; c < 4; c++)
//			board[m][r][c] = board[m][r-1][c];
//	}
//}
//void blockPop(int m) {
//	for (int i = 9; i > 5; i--) {
//		bool b = 1;
//		for (int j = 0; j < 4; j++)
//			if (!board[m][i][j])b = 0;
//		if (b) {
//			for (int j = 0; j < 4; j++)
//				board[m][i][j] = 0;
//			gravity(m, i); 
//			ans++; i++;
//		}
//	}
//	for (int i = 5; i > 3; i--) {
//		bool b = 0;
//		for (int j = 0; j < 4; j++)
//			if (board[m][5][j])b = 1;
//		if (b) {
//			gravity(m, 9);
//		}
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//	while (n--) {
//		int t, x, y;
//		scanf("%d%d%d", &t, &y, &x);
//		for (int i = 0; i < 2; i++) {
//			block cur=block(t,x,y,i);
//			cur.move();
//			blockPop(i);
//			int ny = x,nx=3-y;
//			x = nx; y = ny;
//			if (t == 2)t = 3; 
//			else if (t == 3) { t = 2; x--; }
//		}
//	}
//	for (int k = 0; k < 2; k++)
//		for (int i = 6; i < 10; i++)
//			for (int j = 0; j < 4; j++)if (board[k][i][j])b++;
//	printf("%d\n%d", ans, b);
//	return 0;
//}