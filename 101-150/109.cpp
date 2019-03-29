//
// Created by dyf on 19-1-12.
//

#include<iostream>
#include<string>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode*newTree(std::vector<int> a,int s,int t){
    TreeNode*root=NULL;
    if(t-s==2){
        root=new TreeNode(a[s+1]);
        root->left=new TreeNode(a[s]);
        root->right=new TreeNode(a[s+2]);
    }else if(t-s==1){
            root=new TreeNode(a[s]);
            root->right=new TreeNode(a[s+1]);
            root->left=NULL;
    }else if(s==t)
    {
        root=new TreeNode(a[s]);
    }
    if(t-s>2){
        root=new TreeNode(a[(s+t)/2]);
        root->left=newTree(a,s,(s+t)/2-1);
        root->right=newTree(a,(s+t)/2+1,t);

    }
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    std::vector<int> a;
    while(head!=NULL){
        a.push_back(head->val);
        head=head->next;
    }
    int c=a.size();
    TreeNode*root=newTree(a,0,c-1);
    return root;
}

void readTree(TreeNode *root){
    if(root){
        std::cout<<root->val<<std::endl;
        readTree(root->left);
        readTree(root->right);
    }
}

int main()
{
    ListNode*l1=new ListNode(-10);
    ListNode*l2=new ListNode(-3);
    ListNode*l3=new ListNode(0);
    ListNode*l4=new ListNode(5);
    ListNode*l5=new ListNode(9);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;
    TreeNode *root=sortedListToBST(l1);
    readTree(root);
    return 0;
}