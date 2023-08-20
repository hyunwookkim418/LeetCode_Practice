class Solution {
public:
    int findPar(int u, vector <int>& parent)
    {
        if (u == parent[u])
            return u;
        return parent[u] = findPar(parent[u], parent);
    }

    void unionn(int u, int v, vector <int>& parent, vector <int>& rank)
    {
        u = findPar(u, parent);
        v = findPar(v, parent);

        if (rank[u] < rank[v]) parent[u] = v;
        else if (rank[u] > rank[v]) parent[v] = u;
        else parent[v] = u, rank[u]++;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector <int> rank(n, 0), parent(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto x : edges)
            unionn(x[0], x[1], parent, rank);

        int p1 = findPar(source, parent);
        int p2 = findPar(destination, parent);

        return (p1 == p2);
    }
};