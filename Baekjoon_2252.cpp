#include<iostream>
#include<vector>
#include<queue>

#define endl "\n"
#define MAX 100010
using namespace std;

int N, M;
int InDegree[MAX];
vector<int> Adj[MAX];

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        InDegree[b]++;
        Adj[a].push_back(b);
    }
}

void Solution()
{
    queue<int> Q;
    for (int i = 1; i <= N; i++)
    {
        if (InDegree[i] == 0) Q.push(i);
    }

    while (Q.empty() == 0)
    {
        int Cur = Q.front();
        Q.pop();

        cout << Cur << " ";
        for (int i = 0; i < Adj[Cur].size(); i++)
        {
            int Next = Adj[Cur][i];
            InDegree[Next]--;

            if (InDegree[Next] == 0) Q.push(Next);
        }
    }
    cout << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}
