#include <bits/stdc++.h>

using namespace std;

vector<int> topo(vector<vector<int>> &edges, int &V)
{
    unordered_map<int, vector<int>> adj;
    for (vector<int> &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    vector<int> indegree(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        // node is now in your ans so you have to decrease its indegree
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return ans;
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
{
    vector<vector<int>> ans(k, vector<int>(k, 0));

    vector<int> topo_row = topo(rowConditions, k);
    vector<int> topo_col = topo(colConditions, k);

    if (topo_row.empty() || topo_col.empty())
        return {};

    unordered_map<int, int> row_index;
    unordered_map<int, int> col_index;

    for (int i = 0; i < k; i++)
    {
        row_index[topo_row[i]] = i;
        col_index[topo_col[i]] = i;
    }

    for (auto it : row_index)
    {
        int u = it.first;
        int i = row_index[u], j = col_index[u];
        ans[i][j] = u;
    }
    return ans;
}

int main()
{

    vector<vector<int>> rowCondition = {{1, 2}, {3, 2}};
    vector<vector<int>> colCondition = {{2, 1}, {3, 2}};

    int k = 3;

    vector<vector<int>> ans = buildMatrix(k, rowCondition, colCondition);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    // vector<int>roww = topo(rowCondition,k);
    // for (int i = 0; i < k; i++)
    // {
    //     cout << roww[i] << " ";
    // }

    return 0;
}