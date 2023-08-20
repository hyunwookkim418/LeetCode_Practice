#include <iostream>
using namespace std;

int getParent(int parent[], int x) 
{
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) 
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[], int a, int b) 
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b) return 1;
    return 0;
}

int main(void) 
{
    int parent[4];
    for (int i = 1; i <= 3; i++) {parent[i] = i;}

    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);

    cout << "Is 1 and 2 connected? :" << findParent(parent, 1, 2);
    return 0;
}
