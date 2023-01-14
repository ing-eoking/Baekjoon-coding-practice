#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> v;
int N, M;

void dfs(int a, int b) {
	if (a < 0) a = N - 1;
	if (a >= N) a = 0;
	if (b < 0) b = M - 1;
	if (b >= M) b = 0;
	if (v[a][b]) return;
	v[a][b] = 1;
	dfs(a-1, b);
	dfs(a+1, b);
	dfs(a, b-1);
	dfs(a, b+1);
}

int main() {
	int area = 0;
	scanf("%d%d", &N, &M);
	v = vector<vector<int>>(N, vector<int>(M,0));
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			scanf("%d", &v[i][j]);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0) {
				area++;
				dfs(i, j);
			}
		}
	}
	printf("%d\n", area);

}
