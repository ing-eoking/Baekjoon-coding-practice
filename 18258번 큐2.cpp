#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int main() {
	int N;
	char cmd[20];
	scanf("%d", &N);
	queue<int> q;
	while (N--) {
		scanf("%s", cmd);
		if (!strcmp(cmd,"push")) {
			scanf("%s", cmd);
			q.push(stoi(cmd));
		}
		else if (!strcmp(cmd,"size")) printf("%d\n", q.size());
		else if (!strcmp(cmd,"empty")) printf("%d\n", q.empty());
		else if (q.empty()) printf("-1\n");
		else if (!strcmp(cmd,"pop")) {
			printf("%d\n", q.front());
			q.pop();
		}
		else if (!strcmp(cmd,"front")) printf("%d\n", q.front());
		else if (!strcmp(cmd ,"back")) printf("%d\n", q.back());
		
	}

}
