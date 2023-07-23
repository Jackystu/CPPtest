#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 18;

int rev[MAXN], A[MAXN], B[MAXN], C[MAXN], D[MAXN];

char s1[MAXN], s2[MAXN];
int n, m, N;

inline void fft(int *a, int op)
{
    for (int i = 0; i < N; i++)
    {
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    }
    for (int mid = 1; mid < N; mid <<= 1)
    {
        int Gn = op > 0 ? A[mid] : B[mid];
        for (int j = 0; j < N; j += mid << 1)
        {
            int Gn1 = a[j + mid] * Gn % 998244353;
            for (int k = j; k < j + mid; k++)
            {
                int x = a[k], y = a[k + mid] * Gn1 % 998244353;
                a[k] = (x + y) % 998244353, a[k + mid] = (x - y + 998244353) % 998244353;
            }
        }
    }
    if (op < 0)
    {
        int inv = 998244353 - (998244353 - 1) / N;
        for (int i = 0; i < N; i++)
        {
            a[i] = a[i] * inv % 998244353;
        }
    }
}

inline void solve()
{
    scanf("%s %s", s1, s2);
    n = strlen(s1), m = strlen(s2);
    N = 1;
    while (N < n + m + 1)
        N <<= 1;
    for (int i = 0; i < N; i++)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (N >> 1));
        A[i] = (i < n) ? (s1[n - i - 1] == '?' ? 26 : s1[n - i - 1] - 'a') : 0;
        B[i] = (i < m) ? (s2[m - i - 1] == '?' ? 26 : s2[m - i - 1] - 'a') : 0;
    }
    fft(A, 1), fft(B, 1);
    for (int i = 0; i < N; i++)
    {
        C[i] = (long long)A[i] * B[i] % 998244353;
        D[i] = (long long)A[i] * A[i] % 998244353;
    }
    fft(C, -1), fft(D, -1);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (i < n - m + 1)
        {
            if (C[i + m] == D[i])
                ans++;
        }
        else
        {
            if (D[i] == m)
                ans++;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int T = 1;
    int m, n;
    scanf("%d%d", &m, &n);
//    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}