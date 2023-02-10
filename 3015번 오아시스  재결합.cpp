#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;

int main()
{
	int N, back_idx, eq;
	scanf("%d", &N);
	LL _max = 0;
	vector<pair<LL, LL>> area;
	pair<LL, LL> num = {0, 0};
	for (int i = 0; i < N; i++) {
		scanf("%llu", &num.first);
		num.second = 1;
		while (!area.empty() && area.back().first <= num.first) {
			_max += area.back().second;
			if (area.back().first == num.first) num.second = area.back().second + 1;
			area.pop_back();
		}
		if (!area.empty()) _max++;
		area.push_back(num);
	}
	printf("%llu",_max);
}
