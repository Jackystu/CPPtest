#include <bits/stdc++.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *buildList(std::vector<int> &vec)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (auto &i : vec)
    {
        ListNode *node = new ListNode(i);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    ListNode *head = buildList(vec1);
    printList(head);
    std::vector<ListNode> vec2;

    return 0;
}