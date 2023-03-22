#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> p;

int div(int x, int y, int d1, int d2) {
	vector<int> v(5);
	vector<vector<int>> d(N, vector<int>(N));
	for (int i = 0; i <= d1; i++) d[x + i][y - i] = 5;
	for (int i = 0; i <= d2; i++) d[x + d1 + i][y - d1 + i] = 5;
	for (int i = 1; i <= d2; i++) {
		for (int j = 0; d[x + i][y + i - j] == 0; j++) d[x + i][y + i - j] = 5;
	}
	for (int i = 0; i <= d1; i++)
		for(int j = 0; d[x+ d2 + i][y + d2 - i - j] == 0; j++) 
			d[x + d2 + i][y + d2 - i - j] = 5;
	
	for (int i = 0; i < x + d1; i++)
		for (int j = 0; j <= y; j++)
			if(d[i][j] == 0) d[i][j] = 1;
	for (int i = 0; i <= x + d2; i++)
		for (int j = y +1; j < N; j++)
			if (d[i][j] == 0) d[i][j] = 2;
	for (int i = x + d1; i < N; i++)
		for (int j = 0; j < y - d1 + d2; j++)
			if (d[i][j] == 0) d[i][j] = 3;
	for (int i = x + d2 + 1; i < N; i++)
		for (int j = y - d1 + d2; j < N; j++)
			if (d[i][j] == 0) d[i][j] = 4;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			v[d[i][j] - 1] += p[i][j];


	return *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());

}


int main() {
	scanf("%d", &N);
	p = vector<vector<int>>(N, vector<int>(N));
	int mini = 999999999, nums;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) scanf("%d", &p[i][j]);
	div(0, 1, 1, 3);
	for (int i = 0; i < N - 2; i++)
		for (int j = 1; j < N - 1; j++)
			for (int d1 = 1; j - d1 >= 0; d1++)
				for (int d2 = 1; j + d2 < N && i + d1 + d2 < N; d2++) {
					nums = div(i, j, d1, d2);
					if (mini > nums) mini = nums;
				}
	printf("%d", mini);
}
