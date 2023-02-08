#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	char buf[1000001];
	scanf("%s", buf);
	string str(buf);
	scanf("%s", buf);
	string bomb(buf), answer = "", temp = "";
	for (char i : str) {
		answer += i;
		if (answer.length() >= bomb.length()) {
			bool tf = true;
			for (int j = 0; tf && j < bomb.length(); j++) 
				if (answer[answer.length() - 1 - j] != bomb[bomb.length() - 1 - j]) tf = false;
			if (tf) for (int j = 0; j < bomb.length(); j++) answer.pop_back();
		}
	}
	if (answer.length()) printf("%s", answer.c_str());
	else printf("FRULA");
}
