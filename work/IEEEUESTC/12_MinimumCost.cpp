/**
# Minimum Cost

## Description

There are multiple routes from City A to City B, and you want to reach City B from City A with the
minimum cost. Which cities will you definitely pass through?

## Input

The first line includes two integers n and m, where n represents the number of cities and m
represents the number of flights. City numbers range from 1 to n. The city number of City A is 1,
and the city number of City B is n.

The following m lines describe flight information. Each line has three integers a, b, and c.
representing a one-way flight from city a to b with a price of c.

Assume that there is a path from City A to City B.

## Constrains

- $1 \leq n \leq 10^5$
- $1 \leq m\leq2\times10^5 $
- $1 \le a, b\le n$
- $1 \leq c \leq 10^9$

## Output

Output an integer k, representing the number of cities that must be passed through in the path,
followed by the city numbers in ascending order.

*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 5;
typedef pair<unsigned long long, int> PII;
vector<PII> edges[MAXN];
unsigned long long dist[MAXN];
vector<int> pre[MAXN];
bool vis[MAXN];
int n, m;
void dijkstra(int s)
{
    priority_queue<PII, vector<PII>, greater<PII>> q;
    for (int i = 1; i <= n; i++)
        dist[i] = 2e18;
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        PII t = q.top();
        q.pop();
        int v = t.second;
        if (vis[v])
            continue;
        vis[v] = true;
        for (auto e : edges[v])
        {
            int u = e.first;
            unsigned long long w = e.second;
            if (dist[u] > dist[v] + w)
            {
                dist[u] = dist[v] + w;
                pre[u].clear();
                pre[u].push_back(v);
                q.push({dist[u], u});
            }
            else if (dist[u] == dist[v] + w)
            {
                pre[u].push_back(v);
            }
        }
    }
}
vector<int> path;
void dfs(int u)
{
    if (u == 1)
    {
        path.push_back(1);
        return;
    }
    int min_pre = n + 1;
    for (int v : pre[u])
        min_pre = min(min_pre, v);
    dfs(min_pre);
    path.push_back(u);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }
    dijkstra(1);
    dfs(n);
    sort(path.begin(), path.end());
    cout << path.size() << endl;
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << ' ';
}