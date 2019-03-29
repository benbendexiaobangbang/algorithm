//
// Created by dyf on 18-10-23.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include<algorithm>
struct ListNode {
    int val;
    ListNode next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode swapPairs(ListNode head) {
    if(head==NULL)
        return NULL;
    ListNode l1=head;
    ListNode l2=new ListNode(0);
    if(l1!=NULL) {
        l2 = head->next;
        if (l2 == NULL)
            return head;
        l1->next = l2->next;
        l2->next = l1;
        if (head->next == NULL)
            return l2;
        l1->next = swapPairs(head->next);
    }
    return l2;
}

int main() {
    ListNode *l1=new ListNode(1);
    ListNode *l2=new ListNode(2);
    ListNode *l3=new ListNode(3);
    ListNode *l4=new ListNode(4);
    ListNode *l5=new ListNode(5);
    ListNode *l6=new ListNode(6);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;
    l5->next=l6;
    ListNode *l7=swapPairs(l1);
    while(l7!=NULL)
    {
        std::cout<<l7->val<<std::endl;
        l7=l7->next;
    }
    return 0;
}