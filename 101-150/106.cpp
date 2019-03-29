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

TreeNode *build(std::vector<int>& postorder, std::vector<int>& inorder,int s1,int t1,int s2,int t2){
    if(s1<t1&&s2<t2){
        TreeNode *root=new TreeNode(postorder[t1]);
        int c=0;
        int f=find(postorder[t1],inorder,s2,t2,c);
        root->left=build(postorder,inorder,s1,s1+c-2,s2,f-1);
        root->right=build(postorder,inorder,s1+c-1,t1-1,f+1,t2);
        return root;
    }else if(s1==t1){
        TreeNode *root=new TreeNode(postorder[s1]);
        return root;
    }
    else
        return NULL;

}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    TreeNode *root=build(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1);
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
    std::vector<int> postorder={9,15,7,20,3};
    std::vector<int> inorder={9,3,15,20,7};

    //recoverTree(root);
    TreeNode *root=buildTree(inorder,postorder);
    readTree(root);
    return 0;
}
