//
// Created by dyf on 18-12-10.
//

#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode*l2=new ListNode(0);
    if(head==NULL)
        return head;

    if(head!=NULL&&head->next==NULL)
        return head;
    ListNode *l3=l2;
    ListNode*last=head;
    head=head->next;

    int flag=0;
    while(head!=NULL){
        if(head->val!=last->val){
            if(flag==0) {
                l2->next = last;
                l2=l2->next;
                last = head;
                head = head->next;
            }else
            {
                if(head->next==NULL){
                    l2->next=head;
                    head=head->next;
                }else {
                    flag = 0;
                    last = head;
                    head = head->next;
                }
            }
        }
        else if(head->val==last->val){
            if(head->next==NULL){
                l2->next=NULL;
                head=head->next;
            }else {
                flag = 1;
                last = head;
                head = head->next;
            }
        }
    }
    return l3->next;
}

int main()
{
    ListNode *l1=new ListNode(1);
    ListNode *l2=new ListNode(2);
    ListNode *l3=new ListNode(3);
    ListNode *l4=new ListNode(3);
    ListNode *l5=new ListNode(4);
    ListNode *l6=new ListNode(4);
    ListNode *l7=new ListNode(4);
    //ListNode *l8=new ListNode(4);
    l1->next=l2;
//    l2->next=l3;
//    l3->next=l4;
//    l4->next=l5;
//    l5->next=l6;
//    l6->next=l7;
    //l3->next=l4;
    // l4->next=l5;

    ListNode *b=deleteDuplicates(l1);
    while(b!=NULL){
        std::cout<<b->val<<"->";
        b=b->next;
    }

}