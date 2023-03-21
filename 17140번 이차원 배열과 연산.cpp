#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int r, c, k, time = 0;
	scanf("%d%d%d", &r, &c, &k);
	r--; c--;
	vector<vector<int>> mat(3, vector<int>(3));
	vector<vector<int>> temp;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) scanf("%d", &mat[i][j]);
	for (time = 0; time <= 100; time++) {
		if (r < mat.size() && c < mat[0].size() && mat[r][c] == k) break;
		if (mat.size() >= mat[0].size()) {
			int _max = 0;
			for (int i = 0; i < mat.size(); i++) {
				map<int, int> m;
				for (int j = 0; j < mat[i].size(); j++) {
					if(mat[i][j] != 0)m[mat[i][j]]++;
				}
				if (_max < m.size() * 2) _max = (m.size() * 2) %101;
				vector<pair<int, int>> v(m.begin(), m.end());
				sort(v.begin(), v.end(), cmp);
				mat[i] = vector<int>(_max);
				for (int t = 0; t*2 < _max && t < m.size(); t++) {
					mat[i][t*2] = v[t].first;
					mat[i][t * 2 + 1] = v[t].second;
				}
			}
			for (int i = 0; i < mat.size(); i++)
				while (mat[i].size() < _max) mat[i].push_back(0);
		}
		else {
			int _max = 0;
			temp.clear();
			for (int i = 0; i < mat[0].size(); i++) {
				
				map<int, int> m;
				for (int j = 0; j < mat.size(); j++) {
					if(mat[j][i] != 0) m[mat[j][i]]++;
				}
				if (_max < m.size() * 2) _max = (m.size() * 2)%101;
				if (temp.empty()) temp = vector<vector<int>>(_max, vector<int>(mat[0].size()));
				vector<pair<int, int>> v(m.begin(), m.end());
				sort(v.begin(), v.end(), cmp);
				while (temp.size() < _max) temp.push_back(vector<int>(mat[0].size()));
				for (int t = 0; t*2 < _max && t < v.size(); t++) {
					temp[t * 2][i] = v[t].first;
					temp[t * 2 + 1][i] = v[t].second;
				}
			}
			mat = temp;
		}
	}
	if (time <= 100) printf("%d", time);
	else printf("-1");
}
