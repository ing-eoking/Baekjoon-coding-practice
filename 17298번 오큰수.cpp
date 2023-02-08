#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, num;
	scanf("%d", &N);
	vector<pair<int, int>> nums;
	vector<int> NGE(N, -1);
	for(int i = 0; i < N; i++) {
		scanf("%d", &num);
		while (!nums.empty() && nums.back().first < num) {
			NGE[nums.back().second] = num;
			nums.pop_back();
		}
		nums.push_back({ num, i });
	}
	for (int i = 0; i < N; i++) printf("%d ", NGE[i]);
}
