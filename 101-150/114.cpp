//
// Created by dyf on 19-1-20.
//

#include<iostream>
#include<string>
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * last(TreeNode*root){
    while(root->right!=NULL){
        root=root->right;
    }
        return root;

}

TreeNode* fla(TreeNode *root){
    if(root==NULL)
        return NULL;
    if(root->left==NULL&&root->right==NULL)
        return root;
    else if(root->left!=NULL&&root->right!=NULL){
        last(fla(root->left))->right=fla(root->right);
        root->right=NULL;
        root->right=root->left;
        root->left=NULL;
    }
    else if(root->left!=NULL&&root->right==NULL){
        root->right=fla(root->left);
        root->left=NULL;
    }
    else if(root->left==NULL&&root->right!=NULL){
        root->right=fla(root->right);
    }
    return root;
}


void flatten(TreeNode* root) {
      fla(root);
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
    TreeNode *r1=new TreeNode(1);
    TreeNode *r2=new TreeNode(2);
//    TreeNode*r3=new TreeNode(5);
//    TreeNode *r4=new TreeNode(3);
//    TreeNode *r5=new TreeNode(4);
//    TreeNode*r6=new TreeNode(6);
//    TreeNode*r7=new TreeNode(7);
//    TreeNode *r8=new TreeNode(8);
//    TreeNode *r9=new TreeNode(5);
//    TreeNode*r10=new TreeNode(1);
    r1->right=r2;
//    r1->right=r3;
//    r2->left=r4;
//    r2->right=r5;
//    r3->right=r6;
//    r6->left=r7;
//    r6->right=r8;
//    r3->right=r6;
//    r4->left=r7;
//    r4->right=r8;
//    r6->left=r9;
//    r6->right=r10;
    flatten(r1);
    readTree(r1);
    return 0;
}