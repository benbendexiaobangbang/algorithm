//
// Created by dyf on 18-10-29.
//

#include<iostream>
#include<vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    int i = 0;
    ListNode*l1 = head;
    std::vector<ListNode*>c;
    while (l1!= NULL) {
        c.push_back(l1);
        i++;
        if (i == k)
            break;
        l1 = l1->next;
    }
    if (l1 == NULL)
        return head;
    ListNode*l2 = new ListNode(0);
    if (l1->next != NULL) {
        l2= l1->next;
    }
    if (i < k)
        return head;
    for(int i=0;i<k;i++){
        c[i]->next=NULL;
    }
    l1->next = c[k - 2];
    for (int i = k-2; i>=1; i--) {
        c[i]->next = c[i - 1];
    }
    if (l2 == NULL)
        return l1;
    else
        c[0]->next = reverseKGroup(l2, k);
    return l1;
}

int main()
{
    ListNode*l1 = new ListNode(1);
    ListNode*l2 = new ListNode(2);
    ListNode*l3 = new ListNode(3);
    ListNode*l4 = new ListNode(4);
    ListNode*l5 = new ListNode(5);
    ListNode*l6 = new ListNode(6);
    ListNode *l7 = new ListNode(7);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    ListNode*l8 = reverseKGroup(l1, 4);
    while (l8 != NULL) {
        std::cout << l8->val << " ";
        l8 = l8->next;
    }
    std::cout << std::endl;
    return 0;
}
