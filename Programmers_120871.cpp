//Programmers_120871
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solution(int n) {
    vector<int> myvec;

    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0) {
            continue;
        }

        string s1 = to_string(i);

        size_t found = s1.find_first_of('3');
        if (found != string::npos) {
            continue;
        }
        myvec.push_back(i);
    }
    cout << myvec[n - 1];
}

int main() {

    solution(15);
    return 0;
}