#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int main() {
	int N, n = 0, num;
	deque<int> dq;
	char cmd[15];
	scanf("%d", &N);
	while (N--) {
		scanf("%s", cmd);
		if ((n = !strcmp(cmd, "push_back") - !strcmp(cmd, "push_front"))) {
			scanf("%d", &num);
			if (n < 0) dq.push_front(num);
			else dq.push_back(num);
		}
		else if (!strcmp(cmd, "empty")) printf("%d\n", dq.empty());
		else if (!strcmp(cmd, "size")) printf("%d\n", dq.size());
		else if (dq.empty()) printf("-1\n");
		else if ((n = !strcmp(cmd, "pop_back") - !strcmp(cmd, "pop_front")))
			if (n < 0) {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
			else {
				printf("%d\n", dq.back());
				dq.pop_back();
			}
		else if (!strcmp(cmd, "back")) printf("%d\n", dq.back());
		else if (!strcmp(cmd, "front")) printf("%d\n", dq.front());
	}
}
