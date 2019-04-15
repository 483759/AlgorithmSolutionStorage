#include <cstdio>
int apb[26], i = 0;
char s[27];
int main() {
	while (scanf(" %c", &s[i]) != EOF) {	//한글자씩 입력을 받아서
		apb[s[i] - 97] = i + 1;	//글자의 위치(숫자)를 알파벳 배열에 저장한다
		i++;
	}
	if (i < 26) {
		for (int j = 0; j < 26; j++)
			if (!apb[j]) {
				//길이가 26 미만이라면 사용하지 않은 알파벳 중 가장 빠른것을 추가
				s[i++] = j + 97;
				printf("%s", s);
				return 0;
			}
	}
	else {	//길이가 26이라면
		for (int j = 25; j >= 0; j--)
			for (int k = s[j] - 96; k < 26; k++)
				if (apb[s[j] - 97] < apb[k]) {
					s[j] = k + 97;
					s[j + 1] = '\0';
					printf("%s", s);
					return 0;
				}
	}
	printf("-1");
	return 0;
}