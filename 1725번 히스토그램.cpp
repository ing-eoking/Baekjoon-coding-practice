#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;

int main()
{
	int N, back_idx;
	scanf("%d", &N);
	LL num, _max = 0, _min;
	vector<LL> nums(N+2, 0);
	vector<int> area(1, 0);
	for (int i = 1; i <= N+1; i++) {
		if(i <= N) scanf("%llu", &nums[i]);
		while (!area.empty() && nums[area.back()] > nums[i]) {
			back_idx = area.back();
			area.pop_back();
			_max = max(_max, (LL)(i - area.back() - 1) * nums[back_idx]);
		}
		area.push_back(i);
	}
	printf("%llu", _max);
}
