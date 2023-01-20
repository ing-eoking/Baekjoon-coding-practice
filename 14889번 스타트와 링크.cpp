#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N, min = 987654321, link, start;
	int sx, sy, lx, ly;
	scanf("%d", &N);
	vector<vector<int>> v(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)scanf("%d", &v[i][j]);
	vector<bool> ord(N, false);
	for (int i = N/2; i < N; i++) ord[i] = true;
	do {
		link = 0, start = 0;
		vector<int> l, s;
		for (int i = 0; i < N; i++) {
			if (ord[i]) {
				for (int j = 0; j < l.size(); j++)
					link += v[i][l[j]] + v[l[j]][i];
				l.push_back(i);
			}
			else {
				for (int j = 0; j < s.size(); j++) start += v[i][s[j]] + v[s[j]][i];
				s.push_back(i);
			}
		}
		if (min > abs(link - start)) min = abs(link - start);

	} while (next_permutation(ord.begin(), ord.end()));
	printf("%d", min);
}
