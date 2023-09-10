#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 30000000001

int n, m;
vector<long long> ward;
vector<long long> d;

int main()
{
    cin >> n >> m;
    vector<vector<pair<int, long long>>> p(n);
    ward.resize(n, 0);
    d.resize(n, INF);

    for (int i = 0; i < n; i++)
    {
        cin >> ward[i];
    }
    ward[n - 1] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        p[a].push_back(make_pair(b, c));
        p[b].push_back(make_pair(a, c));
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    PQ.push(make_pair(0, 0));

    while (!PQ.empty())
    {
        pair<long long, int> pa = PQ.top();
        PQ.pop();

        if (pa.first > d[pa.second])
        {
            continue;
        }

        for (auto a : p[pa.second])
        {
            if (ward[a.first] == 1)
            {
                continue;
            }

            pair<long long, int> next = { a.second + pa.first, a.first };
            if (next.first < d[a.first])
            {
                d[a.first] = next.first;
                PQ.push(next);
            }
        }
    }

    if (d[n - 1] == INF)
    {
        cout << -1;
    }
    else
    {
        cout << d[n - 1];
    }

    return 0;
}
