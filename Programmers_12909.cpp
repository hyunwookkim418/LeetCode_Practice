#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt = 0;

    if (s[0] == ')') { return false; }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' && cnt >= 0) { cnt++; }
        else if (s[i] == ')' && cnt >= 0) { cnt--; }
    }

    if (cnt != 0) { return false; }

    return answer;
}
