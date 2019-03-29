//
// Created by dyf on 18-12-23.
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


std::vector<TreeNode*> generate(int s,int t){
    std::vector<TreeNode*> aa;
    std::vector<TreeNode*> bb;
    std::vector<TreeNode*> dd;
    if(s>t) {
        aa.push_back(NULL);
        return aa;
    }
    for(int i=s;i<=t;i++){
        bb=generate(s,i-1);
        dd=generate(i+1,t);
        for (int j = 0; j < bb.size(); j++) {
            for (int k = 0; k < dd.size(); k++) {
                TreeNode*cc=new TreeNode(i);
                cc->left = bb[j];
                cc->right = dd[k];
                aa.push_back(cc);
            }
        }
    }
    return aa;
}

std::vector<TreeNode*> generateTrees(int n) {
    std::vector<TreeNode*> aa;
    if(n==0)
        aa.push_back(NULL);
    aa=generate(1,n);
    return aa;
}

void printTree(TreeNode *head){
    if(head!=NULL){
        std::cout<<","<<head->val;
        if(head->left==NULL)
            std::cout<<",null";
        else
            printTree(head->left);

        if(head->right==NULL)
            std::cout<<",null";
        else
            printTree(head->right);


    }
}
int main()
{
    int d=3;
    std::vector<TreeNode*> c=generateTrees(d);
    for(int i=0;i<c.size();i++){
        TreeNode* head=c[i];
        printTree(head);
        std::cout<<std::endl;
    }
    return 0;
}