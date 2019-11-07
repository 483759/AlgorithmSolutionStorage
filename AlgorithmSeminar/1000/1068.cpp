#include <cstdio>
int n, ans,k,val[51],h;
bool v[51];
void func(int t) {
	v[t] = 1;
	bool b = 0;
	for (int i = 0; i < n; i++)
		if (val[i] == t&&!v[i]) {
			func(i); b = 1;
		}
	if (!b)ans++;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
		if (val[i] == -1) h = i;
	}
	scanf("%d", &k);
	val[k] = -1;
	func(h);
	printf("%d", k==h?0:ans);
	return 0;
}
//#include <cstdio>
//struct tree { int c; tree* n[50]; };
//tree val[50];
//tree* h;
//int n,ans,t,j,k;
//void func(tree* t) {
//	int i;
//	for (i = 0; t->n[i] != NULL; i++)
//		func(t->n[i]);
//	if (!i)ans++;
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &t);
//		if (t == -1) { h = &val[i]; continue; }
//		val[i].c = i;
//		for (j=0; val[t].n[j] != NULL && j < 50; j++);
//		val[t].n[j] = &val[i];
//	}
//	scanf("%d", &k);
//	for(int i=0;val[k].n[i]!=NULL;i++)val[k].n[i]=NULL;
//	func(h);
//	printf("%d", ans - 1);
//	return 0;
//}
//#include <cstdio>
//int n, val[55], k, ans;
//bool chk[55];
//void func(int c) {
//	if (c > n)return;
//	for (int i = 0; i < n; i++)
//		if (val[i] == c) {
//			func(i);
//			val[i] = 51;
//		}
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)scanf("%d", &val[i]);
//	scanf("%d", &k);
//	func(k);
//	val[k] = 51;
//	for (int i = 1; i < n; i++)
//		if (!chk[val[i]]) {
//			ans++; chk[val[i]] = 1;
//		}
//	printf("%d", n-ans);
//	return 0;
//}