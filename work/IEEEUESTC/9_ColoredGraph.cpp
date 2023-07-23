#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num_nodes, num_edges, num_colors;
    cin >> num_nodes >> num_edges >> num_colors;
    vector<int> node_color(num_nodes);
    for (int i = 0; i < num_nodes; i++)
    {
        cin >> node_color[i];
    }
    vector<vector<int>> graph(num_nodes + 1);
    for (int i = 0; i < num_edges; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<long long>> dp(num_nodes + 1, vector<long long>(num_colors + 1));
    for (int i = 1; i <= num_nodes; i++)
    {
        dp[i][node_color[i - 1]] = 1;
    }

    for (int k = 1; k <= num_nodes - 1; k++)
    {
        for (int u = 1; u <= num_nodes; u++)
        {
            for (int v : graph[u])
            {
                if (node_color[u - 1] != node_color[v - 1])
                {
                    dp[v][node_color[u - 1]] += dp[u][node_color[v - 1]];
                }
            }
        }
    }

    long long res = 0;
    for (int i = 1; i <= num_nodes; i++)
    {
        for (int j = 1; j <= num_colors; j++)
        {
            res += dp[i][j];
        }
    }

    cout << res << endl;
    return 0;
}
