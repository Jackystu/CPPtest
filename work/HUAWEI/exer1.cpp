#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

string stackOperation(string input)
{
    istringstream iss(input);
    string num;
    stack<int> stack, stack_bak, stack_temp;
    //    stack<int> stack_bak;
    while (iss >> num)
    {
        int n1 = stoi(num);
        stack.push(n1);
        while (true)
        {
            if (stack.size() < 2)
                break;
            int sum = 0;
            int i = 0;
            //            int size = stack.size();
            for (i = 0; i < stack.size(); i++)
            {
                sum += stack.top();
                stack_bak.push(stack.top());
                stack.pop();
                if (sum - n1 == n1)
                    break;
            }
            for (int j = 0; j < stack_bak.size(); j++)
                stack.push(stack_bak.top());

            if (sum == n1 && i >= 2)
            {
                for (int j = 0; j <= i; j++)
                    stack.pop();
                stack.push(2 * n1);
                n1 = 2 * n1;
            }
            else if (stack.size() >= 2)
            {

                //                stack<int> stack_temp;
                for (int i = 0; i < 2; i++)
                {
                    stack_temp.push(stack.top());
                    stack.pop();
                }
                int ret = stack_temp.top();
                for (int i = 0; i < 2; i++)
                {
                    stack.push(stack_temp.top());
                    stack_temp.pop();
                }
                if (n1 == ret)
                {
                    int n2 = stack.top();
                    stack.pop();
                    n1 = stack.top();
                    stack.pop();
                    stack.push(2 * n1);
                    n1 = 2 * n1;
                }
                else
                    break;
            }
        }
    }
    string result;
    while (!stack.empty())
    {
        result += to_string(stack.top()) + " ";
        stack.pop();
    }
    return result.substr(0, result.length() - 1);
}

int main()
{
    string input;
    getline(cin, input);
    cout << stackOperation(input) << endl;
    return 0;
}