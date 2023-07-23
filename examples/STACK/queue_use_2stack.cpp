#include <bits/stdc++.h>
using namespace std;

class myQueue
{
public:
    myQueue() {}
    ~myQueue() {}
    void myFront() {}
    void myBack() {}
    void myPush(int val)
    {
        innerStack.push(val);
    }
    int myPop()
    {
        if (outerStack.empty())
        {
            if (innerStack.empty())
                return -1;
            while (!innerStack.empty())
            {
                outerStack.push(innerStack.top());
                innerStack.pop();
            }
        }
        int val = outerStack.top();
        outerStack.pop();
        return val;
    }
private:
    stack<int> innerStack, outerStack;
};

int main()
{
    myQueue *mq = new myQueue();
    mq->myPush(1);
    mq->myPush(2);
    cout << mq->myPop() << endl;
    return 0;
}