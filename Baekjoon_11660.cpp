#include <iostream>
#include <algorithm>
using namespace std;

int sum_arr[1025][1025];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, num;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;
            sum_arr[0][i] = 0;
            sum_arr[i][0] = 0;
            sum_arr[i + 1][j + 1] = sum_arr[i][j + 1] + sum_arr[i + 1][j] - sum_arr[i][j] + num;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << sum_arr[c][d] - sum_arr[a - 1][d] - sum_arr[c][b - 1] + sum_arr[a - 1][b - 1] << '\n';
    }
    return 0;
}