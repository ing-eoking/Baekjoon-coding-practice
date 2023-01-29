#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	deque<int> dq;
	bool tf = true;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	while (dq.size() != 1) {
		if (tf) dq.pop_front();
		else {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		tf = !tf;
	}
	printf("%d", dq.front());

}
