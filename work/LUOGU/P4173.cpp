/**
 * P4173 残缺的字符串
 */
#include <bits/stdc++.h>
#define MAX 300010

int main()
{
    int m = 0, n = 0;
    char m_string[MAX], n_string[MAX];
//    std::string m_string, n_string;
//    std::cin >> m >> n;
//    std::cin >> m_string >> n_string;
    scanf("%d%d%s%s", &m, &n, m_string, n_string);
    printf("%d %d %s %s\n", m, n, m_string, n_string);

    return 0;
}