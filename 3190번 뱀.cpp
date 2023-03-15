#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void eraseTail(vector<vector<int>>& board, pair<int, int>& tail) {
	if (tail.first > 0 && board[tail.first - 1][tail.second] > 0) {
		board[tail.first - 1][tail.second] = board[tail.first][tail.second] = 0;
		tail.first -= 2;
		return;
	}
	if (tail.second > 0 && board[tail.first][tail.second - 1] > 0) {
		board[tail.first][tail.second - 1] = board[tail.first][tail.second] = 0;
		tail.second -= 2;
		return;
	}
	if (tail.first < board.size() - 1 && board[tail.first + 1][tail.second] > 0) {
		board[tail.first + 1][tail.second] = board[tail.first][tail.second] = 0;
		tail.first += 2;
		return;
	}
	if (tail.second < board.size() - 1 && board[tail.first][tail.second + 1] > 0) {
		board[tail.first][tail.second + 1] = board[tail.first][tail.second] = 0;
		tail.second += 2;
		return;
	}
}

int main() {
	int N, K, L, X, a, b, time, cur = 0;
	char C;
	scanf("%d%d", &N, &K);
	vector<vector<int>> board(2*N, vector<int>(2*N));
	for (int i = 0; i < K; i++) {
		scanf("%d%d", &a, &b);
		board[2*(a-1)][2*(b-1)] = -1;
	}
	pair<int, int> head = { 0,0 };
	pair<int, int> tail = { 0,0 };
	board[0][0] = 1;
	queue<pair<int, int>> q;
	bool GG = true, apple = false;
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf(" %d %c", &X, &C);
		q.push({ X, C=='L'?-1:1 });
	}
	for (time = 0; GG; time++) {
		if (!q.empty() && time == q.front().first) {
			cur = (cur + q.front().second + 4) % 4;
			q.pop();
		}
		switch (cur) {
		case 0: 
			head.second+= 2;
			if (head.second >= 2*N ||board[head.first][head.second] > 0) GG = false;
			else {
					apple = !board[head.first][head.second];
					board[head.first][head.second] = board[head.first][head.second - 1] = 1;
					if (apple) eraseTail(board, tail);
			}
			break;
		case 2:
			head.second -= 2;
			if (head.second < 0 || board[head.first][head.second] > 0) GG = false;
			else {
				apple = !board[head.first][head.second];
				board[head.first][head.second] = board[head.first][head.second + 1] = 1;
				if (apple) 	eraseTail(board, tail);
			}
			break;
		case 1:
			head.first += 2;
			if (head.first >= 2 * N || board[head.first][head.second] > 0) GG = false;
			else {
				apple = !board[head.first][head.second];
				board[head.first][head.second] = board[head.first-1][head.second] = 1;
				if (apple) eraseTail(board, tail);
			}
			break;
		case 3:
			head.first -= 2;
			if (head.first < 0 || board[head.first][head.second] > 0) GG = false;
			else {
					apple = !board[head.first][head.second];
					board[head.first][head.second] = board[head.first+1][head.second] = 1;
					if (apple) eraseTail(board, tail);
			}
			break;
		}
	}
	printf("%d", time);
}
