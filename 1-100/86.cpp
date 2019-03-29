//
// Created by dyf on 18-12-15.
//

#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* l1=new ListNode(0);
    ListNode*l3=l1;
    ListNode* l2=new ListNode(0);
    ListNode*l4=l2;
    while(head!=NULL){
        if(head->val<x){
            l1->next=head;
            l1=l1->next;
        }else
        {
            l2->next=head;
            l2=l2->next;
        }
        head=head->next;
    }
    l2->next=NULL;
    l1->next=l4->next;
    return l3->next;
}

int main()
{
    ListNode *l1=new ListNode(1);
    ListNode *l2=new ListNode(4);
    ListNode *l3=new ListNode(3);
    ListNode *l4=new ListNode(2);
    ListNode *l5=new ListNode(5);
    ListNode *l6=new ListNode(2);
//    ListNode *l7=new ListNode(4);
    //ListNode *l8=new ListNode(4);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;
    l5->next=l6;
//    l6->next=l7;
    //l3->next=l4;
    // l4->next=l5;
    int x=3;
    ListNode *b=partition(l1,3);
    while(b!=NULL){
        std::cout<<b->val<<"->";
        b=b->next;
    }

}