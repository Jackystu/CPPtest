#include <iostream>
#include <stack>
using namespace std;

const int N = 1010;
int n, m;
char g[N][N];
int h[N][N];
int l[N], r[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'w') h[i][j] = h[i - 1][j] + 1;
        }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        stack<int> stk;
        stk.push(0);
        for (int j = 1; j <= m; j++) {
            while (stk.size() > 1 && h[i][stk.top()] >= h[i][j]) stk.pop();
            l[j] = stk.top();
            stk.push(j);
        }
        stk = stack<int>();
        stk.push(m + 1);
        for (int j = m; j; j--) {
            while (stk.size() > 1 && h[i][stk.top()] >= h[i][j]) stk.pop();
            r[j] = stk.top();
            stk.push(j);
        }
        for (int j = 1; j <= m; j++)
            res = max(res, h[i][j] * (r[j] - l[j] - 1));
    }
    cout << res << endl;
    return 0;
}
