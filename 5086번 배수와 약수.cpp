#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	int f, s;
	while (true) {
		scanf("%d%d", &f, &s);
		if (s == 0 && f == 0) return 0;
		if (s % f == 0) printf("factor\n");
		else if (f % s == 0) printf("multiple\n");
		else printf("neither\n");
	}
}
