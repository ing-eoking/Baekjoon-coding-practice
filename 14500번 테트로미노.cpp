#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<vector<bool>>> tet = {
	{{1,1,1,1}},//1
	{{1},
	{1},
	{1},
	{1}},//2
	{{1,1},
	{1,1}},//3
	{{1,0},
	{1,0},
	{1,1}},//4
	{{1,1},
	{0,1},
	{0,1}},//5
	{{0,1},
	{0,1},
	{1,1}},//6
	{{1,1},
	{1,0},
	{1,0}},//7
	{{1,1,1},
	{1,0,0}},//8
	{{1,1,1},
	{0,0,1}},//9
	{{0,0,1},
	{1,1,1}},//10
	{{1,0,0},
	{1,1,1}},//11
	{{1,0},
	{1,1},
	{0,1}}, //12
	{{0,1},
	{1,1},
	{1,0}}, //13
	{{1,1,0},
	{0,1,1}}, //14
	{{0,1,1},
	{1,1,0}}, //15
	{{1,1,1},
	{0,1,0}},//16
	{{0,1,0},
	{1,1,1}},//17
	{{1,0},
	{1,1},
	{1,0}}, //18
	{{0,1},
	{1,1},
	{0,1}}, //19
};


int main() {
	int N, M, max = 0;
	scanf("%d%d", &N, &M);
	vector<vector<int>> m(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &m[i][j]);
	for (int k = 0; k < tet.size(); k++) {
		for (int i = 0; i < N; i++) {
			if (i + tet[k].size() > N) break;
			for (int j = 0; j < M; j++) {
				if (j + tet[k][0].size() > M) break;
				int sum = 0;
				for (int a = 0; a < tet[k].size(); a++) {
					for (int b = 0; b < tet[k][a].size(); b++) {
						sum += tet[k][a][b] * m[i + a][j + b];
					}
				}
				if (max < sum) max = sum;
			}
		}
	}
	printf("%d", max);


}
