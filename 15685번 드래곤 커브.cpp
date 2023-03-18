#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<bool>> m(201, vector<bool>(201));

void dfs(vector<pair<int, int>> &hist, int cg, const int& g) {
	if (cg >= g) return;
	pair<int, int> st = hist.back(), bet;
	vector<pair<int, int>> temp = hist;
	for (int i = hist.size() - 1; i > 0; i--) {
		bet = { hist[i].first - hist[i - 1].first, hist[i].second - hist[i - 1].second };
		bet = { -bet.second, bet.first };
		m[st.first + bet.first / 2][st.second + bet.second / 2] = true;
		m[st.first + bet.first][st.second + bet.second] = true;
		st.first += bet.first;
		st.second += bet.second;
		temp.push_back(st);
	}
	hist = temp;
	dfs(hist, cg + 1, g);
}

int main() {
	int N;
	scanf("%d", &N);
	int x, y, d, g;
	while (N--) {
		scanf("%d%d%d%d", &x, &y, &d, &g);
		vector<pair<int, int>> hist(1, { 2 * y, 2 * x });
		m[2 * y][2 * x] = true;
		switch (d) {
		case 0:
			m[2 * y][2 * x + 1] = m[2 * y][2 * x + 2] = true;
			hist.push_back({ 2 * y, 2 * x + 2 });
			break;
		case 1:
			m[2 * y - 1][2 * x] = m[2 * y - 2][2 * x] = true;
			hist.push_back({ 2 * y - 2, 2 * x});
			break;
		case 2:
			m[2 * y][2 * x - 1] = m[2 * y][2 * x - 2] = true;
			hist.push_back({ 2 * y, 2 * x - 2 });
			break;
		case 3:
			m[2 * y + 1][2 * x] = m[2 * y + 2][2 * x] = true;
			hist.push_back({ 2 * y + 2, 2 * x });
			break;
		}
		dfs(hist, 1, g+1);
	}
	int answer = 0;
	for (int i = 0; i <= 198; i += 2) {
		for (int j = 0; j <= 198; j += 2) {
			if (m[i][j] && m[i + 2][j] && m[i][j + 2] && m[i + 2][j + 2]) answer++;
		}
	}
	printf("%d", answer);

}
