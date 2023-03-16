#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, L=1;

bool able(vector<int>& v) {
	int pre = v[0], eq = 1;
	for(int i = 1; i < v.size(); i++) {
		if (v[i] - pre == 1) {
			if (eq >= L) {
				pre = v[i];
				eq = 1;
			}
			else return false;
		}
		else if (v[i] - pre == -1) {
			int j;
			for (j = 0; j < L; j++) if (i+j > v.size() - 1 || v[i + j] != v[i]) return false;
			pre = v[i];
			eq = 0;
			i += (L-1);
		}
		else if (v[i] - pre == 0) {
			eq++;
		}
		else return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &N, &L);
	int num;
	vector<vector<int>> v1(N, vector<int>(N)), v2(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			v1[i][j] = v2[j][i] = num;
		}
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += able(v1[i]) + able(v2[i]);
	printf("%d", sum);

}
