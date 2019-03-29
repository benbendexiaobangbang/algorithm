//
// Created by dyf on 18-12-23.
//

#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    int i=1;
    std::vector<ListNode*> list;
    ListNode *n2=new ListNode(0);
    ListNode *n3=n2;
    ListNode *n1=head;
    //ListNode*n2=head;
    while(i!=m){
        n3->next=n1;
        n1=n1->next;
        n3=n3->next;
        i=i+1;
    }
    while(i!=n+1){
        list.push_back(n1);
        i=i+1;
        n1=n1->next;
    }
    for(int i=m;i<=n;i++){
        ListNode* h=list.back();
        list.pop_back();
        n3->next=h;
        n3=n3->next;
    }
    n3->next=n1;
    return n2->next;
}

int main()
{
    ListNode *l1=new ListNode(1);
    ListNode *l2=new ListNode(2);
    ListNode *l3=new ListNode(3);
    ListNode *l4=new ListNode(4);
    ListNode *l5=new ListNode(5);
    //ListNode *l6=new ListNode(2);
//    ListNode *l7=new ListNode(4);
    //ListNode *l8=new ListNode(4);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;
    //l5->next=l6;
//    l6->next=l7;
    //l3->next=l4;
    // l4->next=l5;
    int x=3;
    ListNode *b=reverseBetween(l1,1,4);
    while(b!=NULL){
        std::cout<<b->val<<"->";
        b=b->next;
    }

}
