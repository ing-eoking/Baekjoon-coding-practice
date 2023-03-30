#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
void print(vector<vector<int>>& v) {
	cout << endl;
	for (auto i : v) {
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
}

void up(vector<vector<int>>& v) {
	vector<vector<int>> tt;
	tt.push_back({ v[0][0] });
	tt.push_back(vector<int>(v[0].begin() + 1, v[0].end()));
	while (true) {
		int i = 0, n = tt.back().size();
		vector<vector<int>> at;
		
		for (; i < n; i++) {
			vector<int> temp;

			for (int j = tt.size() - 1; j >= 0; j--)
			{
				if (i >= tt[j].size()) break;
				temp.push_back(tt[j][i]);
			}
			if (temp.size() < 2) break;
			at.push_back(temp);
		}
		at.push_back(vector<int>(tt[tt.size() - 1].begin() + i, tt[tt.size() - 1].end()));
		if (at.back().size() < at[0].size()) break;
		tt = at;
	}
	v = tt;
}
void diff(vector<vector<int>>& v) {
	vector<vector<int>> temp = v;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if(i > 0 && v[i - 1].size() > j)
				if (v[i - 1][j] < v[i][j]) {
					int dif = (v[i][j] - v[i - 1][j]) / 5;
					temp[i][j] -= dif;
					temp[i - 1][j] += dif;
				}
			if (i < v.size() - 1 && v[i + 1][j] < v[i][j]) {
				int dif = (v[i][j] - v[i + 1][j]) / 5;
				temp[i][j] -= dif;
				temp[i + 1][j] += dif;
			}
			if (j > 0 && v[i][j - 1] < v[i][j]) {
				int dif = (v[i][j] - v[i][j - 1]) / 5;
				temp[i][j] -= dif;
				temp[i][j - 1] += dif;
			}
			if (j < v[i].size() - 1 && v[i][j + 1] < v[i][j]) {
				int dif = (v[i][j] - v[i][j + 1]) / 5;
				temp[i][j] -= dif;
				temp[i][j + 1] += dif;
			}
		}
	}
	v = temp;
}
void flat(vector<vector<int>>& v) {
	vector<vector<int>> temp(1);
	for (int i = 0; i < v.back().size(); i++) {
		for (int j = v.size() - 1; j >= 0; j--) {
			if (i >= v[j].size()) break;
			temp[0].push_back(v[j][i]);
		}
	}
	v = temp;
}
void up2(vector<vector<int>>& v) {
	vector<vector<int>> v1, v2;
	int n = v.size(),w = v[0].size();
	for (int i = 0; i < n; i++) {
		vector<int> temp(v[n - 1 - i].begin(), v[n - 1 - i].begin() + w / 2);
		reverse(temp.begin(), temp.end());
		v1.push_back(temp);
		v2.push_back(vector<int>(v[i].begin() + w / 2, v[i].end()));
	}
	v1.insert(v1.end(), v2.begin(), v2.end());
	v = v1;
}


int main() {
	int N, K, mini, maxi, nn;
	scanf("%d%d", &N, &K);
	vector<vector<int>> v(1, vector<int>(N));
	for (int i = 0; i < N; i++)
		scanf("%d", &v[0][i]);
	for (nn = 1; ; nn++) {
		mini = 999999;
		vector<int> minid;
		for (int i = 0; i < N; i++) {

			if (v[0][i] < mini) {
				mini = v[0][i];
				minid.clear();
			}
			if (v[0][i] == mini) {
				minid.push_back(i);
			}
		}
		for (int i : minid) {
			v[0][i]++;
		}
		up(v);
		diff(v);
		flat(v);
		up2(v);
		up2(v);
		diff(v);
		flat(v);
		mini = 9999999; maxi = -1;
		for (int i = 0; i < N; i++)
		{
			if (mini > v[0][i]) mini = v[0][i];
			if (maxi < v[0][i]) maxi = v[0][i];
		}
		if (maxi - mini <= K) break;
	}
	printf("%d", nn);
}
