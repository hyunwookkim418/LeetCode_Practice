#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector <int> vec;
int N, tmp;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());
    for (int i = 0; i < N; i++)
    {
        cout << vec[i] << '\n';
    }
    return 0;
}