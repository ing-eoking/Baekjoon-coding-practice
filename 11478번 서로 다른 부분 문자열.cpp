#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
#include <cstring>

using namespace std;

int main() {
	char str[1001];
	scanf("%s", str);
	unordered_set<string> s;
	for (int i = 0; i < strlen(str); i++)
		for (int l = 1; i + l <= strlen(str); l++) 
			s.insert(string(str + i, str + i + l));
	printf("%d\n", s.size());
}
