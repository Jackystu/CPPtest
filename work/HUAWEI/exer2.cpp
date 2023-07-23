#include <bits/stdc++.h>
using namespace std;

long myCalculate(long x, long N, char k)
{
    switch (k)
    {
        case '+':
            return x + N;
        case '-':
            return x - N;
        case '*':
            return x * N;
        default:
            return -1;
    }
}

bool isSame(long num)
{
    string str = to_string(num);
    char c = str[0];
    for (int i = 1; i < str.length(); ++i)
    {
        if (str[i] != c)
            return false;
    }
    return true;
}

string findKeyString(string M, int N, char K)
{
    int len = M.length();
    long maxRes = -1;
    string pwd = "-1";
    for (int i = 0; i < len; ++i)
    {
        if (M[i] == '0')
            continue;
        for (int j = i + 3; j <= len && j <= i + 12; j++)
        {
            string xStr = M.substr(i, j - i);
            long x = stol(xStr);
            if (K == '*' && N > 999)
                break;
            long res = myCalculate(x, N, K);
            if (isSame(res) && res > maxRes)
            {
                maxRes = res;
                pwd = xStr;
            }
        }
    }
    return pwd;
}

int main()
{
    string M;
    long N;
    char K;
    cin >> M >> N >> K;
    cout << findKeyString(M, N, K);
    return 0;
}