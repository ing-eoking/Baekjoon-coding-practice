#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N, M;

vector<pair<int, int>> cctv;
vector<int> dir;
int mini = 99999999;

void see(vector<vector<char>>& office, int y, int x, bool ud, int bet) {
	int cur = y * ud + x * (!ud);
	for (int i = bet; y * ud + x *(!ud) + i < N * ud + M * (!ud) && cur + i >= 0
		&& (office[y + i * ud][x + i * (!ud)] != '6'); i += bet)
		if(office[y + i * ud][x + i * (!ud)] == '0') office[y + i * ud][x + i * (!ud)] = '#';
}

void dfs(vector<vector<char>>& room, int cur) {
	if (cur == dir.size()) {
		vector<vector<char>> office = room;
		for (int i = 0; i < dir.size(); i++) {
			switch (office[cctv[i].first][cctv[i].second]) {
			case '1':
				switch (dir[i]) {
				case 0: 
					see(office, cctv[i].first, cctv[i].second, false, 1);
					break;
				case 1:
					see(office, cctv[i].first, cctv[i].second, false, -1);
					break;
				case 2:
					see(office, cctv[i].first, cctv[i].second, true, 1);
					break;
				case 3:
					see(office, cctv[i].first, cctv[i].second, true, -1);
					break;
				}
				break;
			case '2':
				switch(dir[i] % 2) {
				case 0 :
					see(office, cctv[i].first, cctv[i].second, false, 1);
					see(office, cctv[i].first, cctv[i].second, false, -1);
					break;
				case 1:
					see(office, cctv[i].first, cctv[i].second, true, 1);
					see(office, cctv[i].first, cctv[i].second, true, -1);
					break;
				}
				break;
			case '3':
				switch (dir[i]) {
				case 0:
					see(office, cctv[i].first, cctv[i].second, false, 1);
					see(office, cctv[i].first, cctv[i].second, true, -1);
					break;
				case 1:
					see(office, cctv[i].first, cctv[i].second, false, -1);
					see(office, cctv[i].first, cctv[i].second, true, 1);
					break;
				case 2:
					see(office, cctv[i].first, cctv[i].second, true, 1);
					see(office, cctv[i].first, cctv[i].second, false, 1);
					break;
				case 3:
					see(office, cctv[i].first, cctv[i].second, true, -1);
					see(office, cctv[i].first, cctv[i].second, false, -1);
					break;
				}
				break;
			case '4':
				switch (dir[i]) {
				case 0:
					see(office, cctv[i].first, cctv[i].second, false, 1);
					see(office, cctv[i].first, cctv[i].second, true, -1);
					see(office, cctv[i].first, cctv[i].second, true, 1);
					break;
				case 1:
					see(office, cctv[i].first, cctv[i].second, false, -1);
					see(office, cctv[i].first, cctv[i].second, true, 1);
					see(office, cctv[i].first, cctv[i].second, true, -1);
					break;
				case 2:
					see(office, cctv[i].first, cctv[i].second, true, 1);
					see(office, cctv[i].first, cctv[i].second, false, 1);
					see(office, cctv[i].first, cctv[i].second, false, -1);
					break;
				case 3:
					see(office, cctv[i].first, cctv[i].second, true, -1);
					see(office, cctv[i].first, cctv[i].second, false, -1);
					see(office, cctv[i].first, cctv[i].second, false, 1);
					break;
				}
			break;
			case '5':
				see(office, cctv[i].first, cctv[i].second, true, -1);
				see(office, cctv[i].first, cctv[i].second, true, 1);
				see(office, cctv[i].first, cctv[i].second, false, -1);
				see(office, cctv[i].first, cctv[i].second, false, 1);
				break;
			}
		}
		int sum = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (office[i][j] == '0') sum++;
		if (mini > sum) mini = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		dir[cur] = i;
		dfs(room, cur + 1);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	vector<vector<char>> room(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &room[i][j]);
			if ('0' < room[i][j] && room[i][j] < '6') {
				cctv.push_back({ i,j });
				dir.push_back(0);
			}
		}
	}
	dfs(room, 0);
	printf("%d", mini);

}
