#include <iostream>
#include <vector>

using namespace std;

#define MAX(a,b) a> b ? a : b

int _max(vector<int>& v) {
	int cur, sum = 0, max_sum = -9999999;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
		if (max_sum < sum) max_sum = sum;
		if (sum < 0) sum = 0;
	}
	return max_sum;
}

int main() {
	int n, a;
	scanf("%d", &n);
	vector<int> arr;
	scanf("%d", &a);
	int b = a, cur = 1;
	for (int i = 1; i < n; i++) {
		scanf("%d", &a);
		if (b != a) {
			arr.push_back(cur);
			cur = 0;
			b = a;
		}
		cur++;
	}
	arr.push_back(cur);
	vector<int> arr1 = arr, arr2 = arr;
	for (int i = 0; i < arr1.size(); i += 2)arr1[i] *= -1;
	for (int i = 1; i < arr1.size(); i += 2)arr2[i] *= -1;
	printf("%d\n", (MAX(_max(arr1), _max(arr2))));

}
