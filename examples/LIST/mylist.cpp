#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur != nullptr)
    {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

ListNode *reverseListRecursive(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *curNode = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return curNode;
}

ListNode *createList(vector<int> &nums)
{
    ListNode *head = new ListNode(-1);
    ListNode *p = head;
    for (int i = 0; i < nums.size(); i++)
    {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head->next;
}

void printList(ListNode *head)
{
    ListNode *p = head;
    while (p)
    {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = createList(nums);
    printList(head);
    head = reverseListRecursive(head);
    printList(head);
    return 0;
}
