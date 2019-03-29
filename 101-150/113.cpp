//
// Created by dyf on 19-1-12.
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

void path(TreeNode *root,int &sum,std::vector<std::vector<int>> &aa,std::vector<int> b){
    if(root->left==NULL&&root->right==NULL&&sum==root->val) {
        b.push_back(root->val);
        aa.push_back(b);
        //sum=sum+b.back();
        return;
    }
    else
    {
        int d=sum;
        int a=root->val;
        b.push_back(root->val);
        int sum=d-a;
        if(root->left!=NULL)
            path(root->left,sum,aa,b);
        if(root->right!=NULL)
            path(root->right,sum,aa,b);
        return;
    }
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
    std::vector<std::vector<int>> aa;
    std::vector<int> b;
    if(root==NULL)
        return aa;
    path(root,sum,aa,b);
    return aa;
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
    TreeNode *r1=new TreeNode(5);
    TreeNode *r2=new TreeNode(4);
    TreeNode*r3=new TreeNode(8);
    TreeNode *r4=new TreeNode(11);
    TreeNode *r5=new TreeNode(13);
    TreeNode*r6=new TreeNode(4);
    TreeNode*r7=new TreeNode(7);
    TreeNode *r8=new TreeNode(2);
    TreeNode *r9=new TreeNode(5);
    TreeNode*r10=new TreeNode(1);
    r1->left=r2;
    r1->right=r3;
    r2->left=r4;
    r3->left=r5;
    r3->right=r6;
    r4->left=r7;
    r4->right=r8;
    r6->left=r9;
    r6->right=r10;
    int sum=22;
    std::vector<std::vector<int>> aa=pathSum(r1,sum);
    for(int i=0;i<aa.size();i++){
        for(int j=0;j<aa[i].size();j++){
            std::cout<<aa[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}