#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

void up(vector<vector<int>> &arr) {
	vector<vector<int>> temp, tt;
	temp.push_back({ arr[0][0] });
	temp.push_back(vector<int>(arr[0].begin() + 1, arr[0].end()));
	while (true) {
		int idx = temp.size() - 1, i;
		for (i = 0; i < temp[idx].size(); i++) {
			if (i >= temp[0].size()) break;
			vector<int> v;
			for (int j = idx; j >= 0; j--)
			{
				v.push_back(temp[j][i]);
			}
			tt.push_back(v);
		}
		tt.push_back(vector<int>(temp[idx].begin() + i, temp[idx].end()));
		if (tt.back().size() < tt[0].size()) break;
		temp = tt;
		tt.clear();
	}
	arr = temp;
	
}
void diff(vector<vector<int>>& arr) {
	vector<vector<int>> temp = arr;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (i > 0 && arr[i - 1].size() > j)
				temp[i][j] += (arr[i - 1][j] - arr[i][j]) / 5;
			if (j > 0)
				temp[i][j] += -(arr[i][j] - arr[i][j - 1]) / 5;
			if (i < arr.size() - 1)
				temp[i][j] += -(arr[i][j] - arr[i + 1][j]) / 5;
			if (j < arr[i].size() - 1)
				temp[i][j] += -(arr[i][j] - arr[i][j + 1]) / 5;
		}
	}
	arr = temp;
}
void flat(vector<vector<int>>& arr) {
	vector<vector<int>> temp(1);
	int idx = arr.size() - 1;
	for (int i = 0; i < arr[idx].size(); i++) {
		for (int j = idx; j >= 0 && i < arr[j].size(); j--) {
			temp[0].push_back(arr[j][i]);
		}
	}
	arr = temp;
}
void up2(vector<vector<int>>& arr) {
	int H = arr[0].size() / 2;
	int N = arr.size();
	vector < vector<int> > u(N), d(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < H; j++) {
			u[i].push_back(arr[N - 1 - i][H - 1 - j]);
			d[i].push_back(arr[i][H + j]);
		}
	}
	u.insert(u.end(), d.begin(), d.end());
	arr = u;
}

int main() {
	int N, K, num = 0;
	scanf("%d%d", &N, &K);
	vector<vector<int>> arr(1, vector<int>(N));
	for (int i = 0; i < N; i++) scanf("%d", &arr[0][i]);
	while (true) {
		int mini = 999999999, maxi = -1;
		for (int i = 0; i < arr[0].size(); i++) {
			if (mini > arr[0][i]) mini = arr[0][i];
			if (maxi < arr[0][i]) maxi = arr[0][i];
		}
		if (maxi - mini <= K) break;
		for (int i = 0; i < arr[0].size(); i++)
			if (mini == arr[0][i]) arr[0][i]++;
		up(arr);
		diff(arr);
		flat(arr);
		up2(arr);
		up2(arr);
		diff(arr);
		flat(arr);
		num++;
	}
	printf("%d\n", num);
}
