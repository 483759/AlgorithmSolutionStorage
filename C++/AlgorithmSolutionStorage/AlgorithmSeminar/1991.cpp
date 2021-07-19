#include <cstdio>
#include <list>
struct tree { char n; tree *l, *r; };
int N;
tree t[27];
char a, b, c;
void preorder(tree *p) {
	if (p == NULL)return;
	printf("%c", p->n);
	preorder(p->l);
	preorder(p->r);
}
void inorder(tree *p) {
	if (p == NULL)return;
	inorder(p->l);
	printf("%c", p->n);
	inorder(p->r);
}
void postorder(tree *p) {
	if (p == NULL)return;
	postorder(p->l);
	postorder(p->r);
	printf("%c", p->n);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %c %c %c", &a, &b, &c);
		t[a-'A'].n = a;
		//(*t[i]).n = a;
		if(b!='.') t[a-'A'].l = &t[b - 'A'];
		if(c!='.') t[a-'A'].r = &t[c - 'A'];
	}
	preorder(&t[0]);
	printf("\n");
	inorder(&t[0]);
	printf("\n");
	postorder(&t[0]);
	return 0;
}