#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<int, long long> m;
    for(int i : weights)
        answer += m[i * 2] + (i % 3 == 0)*m[i * 2 / 3] + (i % 2 == 0)*m[i / 2] 
            + (i % 2 == 0) * m[i * 3 / 2] + (i % 3 == 0)*m[i * 4 / 3] + 
            (i % 4 == 0) * m[i * 3 / 4] + m[i]++;
    return answer;
}
