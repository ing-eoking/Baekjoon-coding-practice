#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
void dfs(string s, int cur) {
	if (cur == 0) { printf("%s\n", s.c_str()); return; }
	for (int i = 1; i <= N; i++) {
		string temp = s + to_string(i) + " ";
		dfs(temp, cur - 1);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	dfs("",M);
}
