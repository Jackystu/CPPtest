#include <bits/stdc++.h>
using namespace std;
int k, l[1005], ans;
int main()
{
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
        scanf("%d", &l[i]);
    for (int i = 1; i <= k; i++)
        ans += l[i] - 1;
    printf("%d\n", ans & 1 ? 1 : -1);
    return 0;
}
