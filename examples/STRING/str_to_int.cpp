#include <bits/stdc++.h>
using namespace std;
class Automaton
{
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}};
    unordered_map<string, vector<string>> table1 = {
        {"start", {"start", "signed", "end", "in_number", "end", "end"}},
        {"signed", {"end", "end", "end", "in_number", "end", "end"}},
        {"powed", {"end", "end", "end", "in_number", "end", "end"}},
        {"in_number", {"end", "end", "in_number", "in_number", "in_number", "end"}},
        {"point", {"end", "end", "end", "in_number", "end", "end"}},
        {"end", {"end", "end", "end", "end", "end", "end"}},
    };
    int get_col(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

    int get_col_l(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (c == 'e' or c == 'E')
            return 2;
        if (isdigit(c))
            return 3;
        if (c == '.')
            return 4;
        return 5;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }

    void get_l(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution
{
public:
    int strToInt(string str)
    {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }

    string reverseLeftWords(string s, int n)
    {
        string rightStr = &s.at(n);
        string leftStr = s.substr(0, n);
        //        reverse(leftStr.begin(), leftStr.end());
        return leftStr + rightStr;
    }
};

int main()
{
    Solution solution;
    //     string str = "   -42";
    string str = "strabcdefg";
    cout << solution.reverseLeftWords(str, 2) << endl;
}