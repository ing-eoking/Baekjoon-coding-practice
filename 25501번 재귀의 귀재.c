#include <stdio.h>
#include <string.h>

int D = 0;

int recursion(const char* s, int l, int r) {
	D++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}

int main() {
	int T;
	scanf("%d", &T);
	char S[1000];
	while (T--) {
		scanf("%s", S);
		D = 0;
		printf("%d ", isPalindrome(S));
		printf("%d\n", D);
	}

}
