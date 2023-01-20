#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v(9, 1);
void dfs(int cur) {
	if (cur == M+1) {
		for (int i = 1; i <= M; i++)
			printf("%d ", v[i]);
		printf("\n");
		return; }
	for (int i = v[cur - 1]; i <= N; i++) {
		v[cur] = i;
		dfs(cur + 1);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	dfs(1);
}
