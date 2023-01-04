#include <stdio.h>
#include <stdint.h>
#include <queue>

using namespace std;

int main() {
	int N = 0;
	scanf("%d", &N);
	priority_queue<int> low;
	priority_queue<int,vector<int>, std::greater<int>> high;
	for(int i = 0; i < N; i++) {
		int num = 0;
		scanf("%d", &num);
		if (low.size() > high.size()) high.push(num);
		else low.push(num);
		if (!high.empty() && low.top() > high.top()) {
			int temp = high.top();
			high.pop();
			high.push(low.top());
			low.pop();
			low.push(temp);
		}
		printf("%d\n", low.size() < high.size() ? high.top() : low.top());
	}
	return 0;
}
