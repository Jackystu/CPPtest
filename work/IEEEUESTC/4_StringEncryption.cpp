/*
 题目要求：
 1. 第一行读入一行字符串，表示要解密的字符串，字符串中只包含大小写字母和空格
 2. 第二行读入一个整数n，表示解密规则，注意n可能为负数
 3. 例如：输入字符串为“abc”，解密规则为3，每一个字符都加上当前的位置，本例则输出“dfh”
 4. 如果输入的字符串中有大写字母，则按照解密规则输出对应的大写字母
 5. 如果输入的字符串中有空格，则输出空格
 6. 如果超出26个字母，若为小写字母，则从a开始重新计数，若为大写字母，则从A开始重新计数
 * */
#if 0
#include <bits/stdc++.h>

int main()
{
    std::string s;
    std::getline(std::cin, s);
    int n;
    std::cin >> n;
    for (int i = 0; i < s.length(); i++)
    {
        if (n < 0)
            n = 26 + n;
        if (s[i] == ' ')
            std::cout << ' ';
        else
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                std::cout << char('a' + (s[i] - 'a' + n + i) % 26);
            else
                std::cout << char('A' + (s[i] - 'A' + n + i) % 26);
        }
    }
    std::cout << std::endl;
    return 0;
}
#endif

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    n = (n % 26 + 26) % 26;
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            char start = isupper(s[i]) ? 'A' : 'a';
            s[i] = start + (s[i] - start + n + i) % 26;
        }
    }
    cout << s << endl;
    return 0;
}
