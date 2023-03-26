#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int main() {
	int N, stud, f;
	map<int, set<int>> fav;
	scanf("%d", &N);
	vector<vector<int>> pos(N, vector<int>(N));
	for (int i = 0; i < N * N; i++) {
		scanf("%d", &stud);
		for (int k = 0; k < 4; k++) {
			scanf("%d", &f);
			fav[stud].insert(f);
		}
		map<pair<int,int>, vector<pair<int, int>>> pri;
		for(int r = 0; r < N; r++)
			for(int c = 0; c < N; c++)
				if (pos[r][c] == 0) {
					int ff = 0, emp = 0;
					if (r > 0) {
						if(fav[stud].find(pos[r - 1][c]) != fav[stud].end()) ff++;
						if (pos[r - 1][c] == 0) emp++;
					}
					if (r < N - 1) { 
						if(fav[stud].find(pos[r + 1][c]) != fav[stud].end()) ff++;
						if (pos[r + 1][c] == 0) emp++;
					}
					if (c > 0) {
						if(fav[stud].find(pos[r][c - 1]) != fav[stud].end()) ff++;
						if (pos[r][c - 1] == 0) emp++;
					}
					if (c < N - 1) {
						if(fav[stud].find(pos[r][c + 1]) != fav[stud].end()) ff++;
						if (pos[r][c + 1] == 0) emp++;
					}
					pri[{ff, emp}].push_back({ r, c });
				}
		auto it = --pri.end();
		pos[it->second[0].first][it->second[0].second] = stud;
	}
	int sum = 0;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int lov = 0;
			if (i > 0 && fav[pos[i][j]].find(pos[i - 1][j]) != fav[pos[i][j]].end()) lov++;
			if (i < N - 1 && fav[pos[i][j]].find(pos[i + 1][j]) != fav[pos[i][j]].end()) lov++;
			if (j > 0 && fav[pos[i][j]].find(pos[i][j - 1]) != fav[pos[i][j]].end()) lov++;
			if (j < N - 1 && fav[pos[i][j]].find(pos[i][j + 1]) != fav[pos[i][j]].end()) lov++;
			sum += pow(10,lov- 1);
		}
	printf("%d", sum);
}
