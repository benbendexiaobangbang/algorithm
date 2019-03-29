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

int find(int a,std::vector<int> b,int s,int t,int &c){
    c=0;
    for(int i=s;i<=t;i++){
        c++;
        if(a==b[i]){
            return i;
        }
    }
}

TreeNode *build(std::vector<int>& preorder, std::vector<int>& inorder,int s1,int t1,int s2,int t2){
    if(s1<=t1&&s2<=t2){
        TreeNode *root=new TreeNode(preorder[s1]);
        int c=0;
        int f=find(preorder[s1],inorder,s2,t2,c);
        root->left=build(preorder,inorder,s1+1,s1+c-1,s2,f-1);
        root->right=build(preorder,inorder,s1+c,t1,f+1,t2);
        return root;
    }else
        return NULL;

}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    TreeNode *root=build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    return root;
    //int c=find(preorder[0],inorder);
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
    std::vector<int> preorder={3,9,20,15,7};
    std::vector<int> inorder={9,3,15,20,7};

    //recoverTree(root);
    TreeNode *root=buildTree(preorder,inorder);
    readTree(root);
    return 0;
}
