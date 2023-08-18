#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int k;
    vector<int>board;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        board.push_back(k);
    }

    sort(board.begin(), board.end());

    int answer = 0;

    int start = 0;
    int end = N - 1;

    while (start < end)
    {

        if (board[start] + board[end] > M)
        {
            end--;
        }
        else if (board[start] + board[end] < M)
        {
            start++;
        }
        //else if (board[start] + board[end] == M)
        else {
            answer++;
            start++;
        }
    }
    cout << answer << "\n";
}