#include <cstdio>
int main() {
	int i;
	char c;
	scanf("%d", &i);
	scanf(" ");
	scanf("%c", &c);
	printf("%d\n%c", i, c);
	return 0;
}



int move(좌표){
	visit 체크
	스택에 좌표 push
	for 8개의 방향에 대해 이동경로 계산{
		방문하지 않았다면{
			스택에 좌표 push
			이동가능 칸의 수 +1
			visit 체크
		}
	}
	return 초기 좌표에서 이동가능 칸의 수
}

void func(행 숫자) {
	행이 n 이상이면 return
	for 모든 열에 대해 경우의수 계산{
		이미 방문된 좌표라면 continue
		move(현재 좌표)
		끝 행까지 체크했고 
		모든 칸이 채워졌다면 경우의수 +1
		func(행 숫자 + 1)
		현재 행에서 체크한 visit배열 해제, stack pop
	}
}