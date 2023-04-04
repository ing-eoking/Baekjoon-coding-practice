#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define LIMIT 50000000

char buf[4097];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int sm, sc, si;
		scanf("%d%d%d", &sm, &sc, &si);
		int point = 0, str = 0;
		vector<int> arr(sm);
		scanf("%s", buf);
		string cmd(buf);
		scanf("%s", buf);
		string input(buf);
		vector<int> lpos;
		map<int, int> hash;
		for (int i = 0; i < sc; i++) {
			if (cmd[i] == '[') lpos.push_back(i);
			else if (cmd[i] == ']') {
				hash[i] = lpos.back();
				hash[lpos.back()] = i;
				lpos.pop_back();
			}
		}
		int n = 0, loop = 1e9;
        bool tf = false;
		for (int i = 0; i < sc; i++) {
			if (cmd[i] == '-') arr[point] = (arr[point] + 255) % 256;
			else if (cmd[i] == '+') arr[point] = (arr[point] + 1) % 256;
			else if (cmd[i] == '<') point = (point - 1 + sm) % sm;
			else if (cmd[i] == '>') point = (point + 1) % sm;
			else if (cmd[i] == '[' && arr[point] == 0) i = hash[i];
			else if (cmd[i] == ']' && arr[point] != 0) i = hash[i];
			else if (cmd[i] == ',') {
				if (str < si) arr[point] = input[str++];
				else arr[point] = 255;
			}
            if(n > LIMIT) loop = min(loop, i);
            if(n++ > 2*LIMIT) break;
		}
		if (n > 2*LIMIT) printf("Loops %d %d\n", loop, hash[loop]);
		else printf("Terminates\n");
	}
}
