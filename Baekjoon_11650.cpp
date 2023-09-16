#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < N; i++)
    {
        cout << vec[i].first << ' ' << vec[i].second << '\n';  // Access the pair elements using vec[i].first and vec[i].second
    }

    return 0;
}
