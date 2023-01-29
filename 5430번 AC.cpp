#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int N, n;
	scanf("%d", &N);
	char cmd[100001];
	char arr[400000];
	while (N--) {
		scanf("%s", cmd);
		scanf("%d", &n);
		scanf("%s", arr);
		istringstream iss(arr);
		string buf;
		deque<int> dq;
		bool r = false, err = false;
		while (getline(iss, buf, ',') && (n--)) {
			if (buf[buf.length() - 1] == ']') buf.erase(buf.begin() + buf.length() - 1);
			if (buf[0] == '[') buf[0] = '0';
			dq.push_back(stoi(buf));
		}
		for (int i = 0; !err && cmd[i] != '\0'; i++)
			if (cmd[i] == 'R') r = !r;
			else if (dq.empty()) err = true;
			else if (cmd[i] == 'D')
				if (r) dq.pop_back();
				else dq.pop_front();
		if (err) printf("error\n");
		else {
			printf("[");
			for (int i = 0; i < dq.size(); i++) {
				if (i != 0) printf(",");
				if (r) printf("%d", dq.at(dq.size() - i - 1));
				else printf("%d", dq.at(i));
			}
			printf("]\n");
		}
	}

}
