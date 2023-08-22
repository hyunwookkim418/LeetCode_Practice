#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX];
vector<int> a[MAX];

void TopologicalSorting() {
    int result[MAX];
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    int idx = 1;  // Index for result array

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        result[idx++] = x;  // Place x in the result array
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];

            if (--inDegree[y] == 0) {
                q.push(y);
            }
        }
    }

    if (idx - 1 != n) {
        cout << "Cycle occurred!";
        return;
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}

int main() {
    n = 6;
    a[1].push_back(2);
    inDegree[2]++;
    a[2].push_back(3);
    inDegree[3]++;
    a[3].push_back(4);
    inDegree[4]++;
    a[4].push_back(5);
    inDegree[5]++;
    a[6].push_back(2);
    inDegree[2]++;
    TopologicalSorting();

    return 0;
}
