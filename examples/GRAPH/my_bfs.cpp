#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 150010;

int n, k;
char a[N], b[N];
int dp[N];

int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s%s", a + 1, b + 1);

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    for (int i = k; i <= n; i++)
        for (int j = i - k + 1; j <= i; j++)
            if (a[j] == b[i - j + i - k + 1])
                dp[i] = min(dp[i], dp[j - 1] + i - j);

    printf("%d\n", dp[n]);

    return 0;
}