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
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode*l1=head;
    int c=0;
    while(l1!=NULL)
    {
        c+=1;
        l1=l1->next;
    }
    if(c==n)return head->next;
    if(c<n)return NULL;
    ListNode*l2=head;
    for(int i=1;i<c-n;i++){
        l2=l2->next;
    }
    ListNode *l3=l2->next;
    l2->next=l3->next;
    return head;
}

int main() {
    ListNode *l1=new ListNode(1);
    ListNode *l2=new ListNode(2);
    ListNode *l3=new ListNode(3);
    ListNode *l4=new ListNode(4);
    ListNode *l5=new ListNode(5);
//    l1->next=l2;
//    l2->next=l3;
//    l3->next=l4;
//    l4->next=l5;
    ListNode *l6=removeNthFromEnd(l1,1);
    while(l6!=NULL)
    {
        std::cout<<l6->val<<std::endl;
        l6=l6->next;
    }
    return 0;
}