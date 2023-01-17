#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) a > b ? b : a

char chess[2][8][9] = 
{ {"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"},
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB" };

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	char board[50][50];
	for (int i = 0; i < N; i++) scanf("%s", &board[i]);
	int min = 65;
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int case1 = 0, case2 = 0;
			for(int y = 0; y < 8; y++)
				for (int x = 0; x < 8; x++) {
					if (board[i + y][j + x] != chess[0][y][x]) case1++;
					if (board[i + y][j + x] != chess[1][y][x]) case2++;
				}
			min = MIN(min, case1);
			min = MIN(min, case2);
		}
	}
	printf("%d", min);
}
