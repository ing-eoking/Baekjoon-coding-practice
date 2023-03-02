#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<char>> m;
vector<bool> visit;

void front(char st) {
	printf("%c", st);
	if (m[st][0] != '.') front(m[st][0]);
	if (m[st][1] != '.') front(m[st][1]);
}
void center(char st) {
	if (m[st][0] != '.') center(m[st][0]);
	printf("%c", st);
	if (m[st][1] != '.') center(m[st][1]);
}
void back(char st) {
	if (m[st][0] != '.') back(m[st][0]);
	if (m[st][1] != '.') back(m[st][1]);
	printf("%c", st);
}
int main() {
	int N;
	char a, b, c;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %c %c %c", &a, &b, &c);
		m[a].push_back(b);
		m[a].push_back(c);
	}
	front('A');
	printf("\n");
	center('A');
	printf("\n");
	back('A');
}
