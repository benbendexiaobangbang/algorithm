//
// Created by dyf on 18-11-25.
//

#include<iostream>
#include<vector>

struct ListNode {
     int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    int j=0;
    ListNode*l2=head;
    while(l2!=NULL){
        j++;
        l2=l2->next;
    }
    for(int i=0;i<k%j;i++){
    ListNode*l1=head;
    ListNode*last=head;
    while(head->next!=NULL){
        last=head;
        head=head->next;
    }
    head->next=l1;
    last->next=NULL;
    }
    return head;
}

int main()
{
    ListNode *l1=new ListNode(0);
    ListNode *l2=new ListNode(1);
    ListNode *l3=new ListNode(2);
    ListNode *l4=new ListNode(4);
    ListNode *l5=new ListNode(5);
    l1->next=l2;
    l2->next=l3;
    //l3->next=l4;
   // l4->next=l5;

    ListNode *b=rotateRight(l1,4);
    while(b!=NULL){
        std::cout<<b->val<<"->";
        b=b->next;
    }

}