#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 210;
const int INF = 0x3f3f3f3f;
int n;
int w[N][N];
int lx[N], ly[N], slack[N];
int match[N];
bool vx[N], vy[N];
bool dfs(int u)
{
    vx[u] = true;
    for (int v = 1; v <= n; v++)
    {
        if (!vy[v])
        {
            int t = lx[u] + ly[v] - w[u][v];
            if (t == 0)
            {
                vy[v] = true;
                if (!match[v] || dfs(match[v]))
                {
                    match[v] = u;
                    return true;
                }
            }
            else
            {
                slack[v] = min(slack[v], t);
            }
        }
    }
    return false;
}
void update()
{
    int d = INF;
    for (int i = 1; i <= n; i++)
    {
        if (!vy[i])
            d = min(d, slack[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vx[i])
            lx[i] -= d;
        if (vy[i])
            ly[i] += d;
        else
            slack[i] -= d;
    }
}
void KM()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            lx[i] = max(lx[i], w[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        memset(slack, 0x3f, sizeof slack);
        while (true)
        {
            memset(vx, false, sizeof vx);
            memset(vy, false, sizeof vy);
            if (dfs(i))
                break;
            update();
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> w[i][j];
            w[i][j] *= -1;
        }
    }
    KM();
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += w[match[i]][i];
    cout << -res << endl;
    for (int i = 1; i <= n; i++)
        cout << match[i] << ' ' << i << endl;
}
