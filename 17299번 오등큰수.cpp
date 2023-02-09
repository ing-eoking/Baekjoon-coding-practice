#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	int N, num;
	unordered_map<int, int> hash;
	scanf("%d", &N);
	vector<int> nums(N);
	vector<int> NGE(N, -1);
	vector<int> idx;
	for(int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
		hash[nums[i]]++;
	}
	for (int i = 0; i < N; i++) {
		while (!idx.empty() && hash[nums[idx.back()]] < hash[nums[i]]) {
			NGE[idx.back()] = nums[i];
			idx.pop_back();
		}
		idx.push_back(i);
	}
	for (int i = 0; i < N; i++) printf("%d ", NGE[i]);
}
