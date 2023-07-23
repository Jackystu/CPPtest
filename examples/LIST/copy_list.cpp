#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> cachedNode;
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;
        if (!cachedNode.count(head))
        {
            Node *tempNode = new Node(head->val);
            cachedNode[head] = tempNode;
            tempNode->next = copyRandomList(head->next);
            tempNode->random = copyRandomList(head->random);
        }

        return cachedNode[head];
    }
};

int main()
{
    Solution solution;
    //    Node *copyList = solution.copyRandomList();
    return 0;
}