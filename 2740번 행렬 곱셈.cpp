#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> VVI;
typedef vector<int> VI;

VVI mult(const VVI& a, const VVI& b);
VVI divide(const VVI& a, const VVI& b);
VVI vplus(const VVI& a,const VVI& b);
VVI vminus(const VVI& a, const VVI& b);

int main() {
	VVI A(128, VI(128)), B(128, VI(128)), C;
	int N, M, K;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &A[i][j]);
	scanf("%d%d", &M, &K);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++) scanf("%d", &B[i][j]);
	C = mult(A, B);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++) printf("%d ", C[i][j]);
		printf("\n");
	}
	//divide({0,0}, {0,0}, {0,0}, 128);

}
VVI mult(const VVI& a, const VVI& b) {
	if (a.size() > 2) return divide(a, b);
	if (a.size() == 1)return { {a[0][0]*b[0][0]} };
	if (a.size() == 2) return { {a[0][0] * b[0][0] + a[0][1] * b[1][0],a[0][0] * b[0][1] + a[0][1] * b[1][1]},
		{a[1][0] * b[0][0] + a[1][1] * b[1][0],a[1][0] * b[0][1] + a[1][1] * b[1][1]} };
}
VVI vplus(const VVI& a, const VVI& b) {
	VVI c(a.size(), VI(a.size()));
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a.size(); j++)
			c[i][j] = a[i][j] + b[i][j];
	return c;
}
VVI vminus(const VVI& a, const VVI& b)
{
	VVI c(a.size(), VI(a.size()));
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a.size(); j++)
			c[i][j] = a[i][j] - b[i][j];
	return c;
}
VVI divide(const VVI& a, const VVI& b) {
	int N = a.size();
	vector<vector<VVI>> div_a(2,vector<VVI>(2, VVI(N / 2, VI(N / 2)))), div_b(2,vector<VVI>(2, VVI(N / 2, VI(N / 2))));
	VVI c(N, VI(N));
	for (int i = 0; i < N/2; i++)
		for (int j = 0; j < N/2; j++) {
			div_a[0][0][i][j] = a[i][j];
			div_a[0][1][i][j] = a[i][N / 2 + j];
			div_a[1][0][i][j] = a[N / 2 + i][j];
			div_a[1][1][i][j] = a[N / 2 + i][N / 2 + j];
			div_b[0][0][i][j] = b[i][j];
			div_b[0][1][i][j] = b[i][N / 2 + j];
			div_b[1][0][i][j] = b[N / 2 + i][j];
			div_b[1][1][i][j] = b[N / 2 + i][N / 2 + j];
		}
	vector<VVI> M;
	M.push_back(mult(vplus(div_a[0][0], div_a[1][1]), vplus(div_b[0][0], div_b[1][1])));
	M.push_back(mult(vplus(div_a[1][0], div_a[1][1]), div_b[0][0]));
	M.push_back(mult(div_a[0][0], vminus(div_b[0][1], div_b[1][1])));
	M.push_back(mult(div_a[1][1], vminus(div_b[1][0], div_b[0][0])));
	M.push_back(mult(vplus(div_a[0][0], div_a[0][1]), div_b[1][1]));
	M.push_back(mult(vminus(div_a[1][0], div_a[0][0]), vplus(div_b[0][0], div_b[0][1])));
	M.push_back(mult(vminus(div_a[0][1], div_a[1][1]), vplus(div_b[1][0], div_b[1][1])));
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < N / 2; j++) {
			c[i][j] = M[0][i][j] + M[3][i][j] - M[4][i][j] + M[6][i][j];
			c[i][N / 2 + j] = M[2][i][j] + M[4][i][j];
			c[N / 2 + i][j] = M[1][i][j] + M[3][i][j];
			c[N / 2 + i][N / 2 + j] = M[0][i][j] - M[1][i][j] + M[2][i][j] + M[5][i][j];
		}
	return c;
}
