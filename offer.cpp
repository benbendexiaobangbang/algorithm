//
// Created by dyf on 19-3-21.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

void Path(TreeNode*root,int expectNumber,vector<vector<int>> &result,vector<int> v){
    if(root->left==NULL&&root->right==NULL)
    {
        if(expectNumber==root->val){
            v.push_back(root->val);
            result.push_back(v);
            return;
        }
        else
            return;
    }
    if(root->left!=NULL){
        vector<int> v1=v;
        v1.push_back(root->val);
        Path(root->left,expectNumber-root->val,result,v1);
    }
    if(root->right!=NULL){
        vector<int> v2=v;
        v.push_back(root->val);
        Path(root->right,expectNumber-root->val,result,v);
    }
}

vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
    std::vector<std::vector<int>> result;
    if(root==NULL)
        return result;
    std::vector<int> v;
    Path(root,expectNumber,result,v);
    sort(result.begin(),result.end());
    return result;
}

int main()
{
    TreeNode*root=new TreeNode(10);
    TreeNode*l1=new TreeNode(5);
    TreeNode*l2=new TreeNode(12);
    TreeNode*l3=new TreeNode(4);
    TreeNode*l4=new TreeNode(7);
    root->left=l1;
    root->right=l2;
    l1->left=l3;
    l1->right=l4;
    std::vector<std::vector<int>> result=FindPath(root,22);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}