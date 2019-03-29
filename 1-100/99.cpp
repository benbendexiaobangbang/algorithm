//
// Created by dyf on 19-1-12.
//

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//void inorder(TreeNode *root, vector<TreeNode*> &list, vector<int> &vals) {
//    if (!root) return;
//    inorder(root->left, list, vals);
//    list.push_back(root);
//    vals.push_back(root->val);
//    inorder(root->right, list, vals);
//}

//void recoverTree(TreeNode *root) {
//    vector<TreeNode*> list;
//    vector<int> vals;
//    inorder(root, list, vals);
//    sort(vals.begin(), vals.end());
//    for (int i = 0; i < list.size(); ++i) {
//        list[i]->val = vals[i];
//    }
//}

//void inorder(TreeNode*root,std::vector<TreeNode*>&list,std::vector<int> &vals){
//    if(root==NULL)
//        return;
//    inorder(root->left,list,vals);
//    list.push_back(root);
//    vals.push_back(root->val);
//    inorder(root->right,list,vals);
//}
//
//void recoverTree(TreeNode*root){
//  std::vector<TreeNode*>list;
//  std::vector<int>vals;
//  inorder(root,list,vals);
//  std::vector<int> node;
//  for(int i=0;i<vals.size()-1;){
//      if(vals[i]>vals[i+1])
//      {
//          node.push_back(i);
//          i=i+2;
//          if(node.size()==2)
//              break;
//      }else
//          i=i+1;
//  }
//  if(node.size()==1)
//  {
//      int c=node.back();
//      node.clear();
//      list[c]->val=vals[c+1];
//      list[c+1]->val=vals[c];
//  }
//  else if(node.size()==2){
//      int c1=node[0];
//      int c2=node[1];
//      node.clear();
//      list[c1]->val=vals[c2+1];
//      list[c2+1]->val=vals[c1];
//  }
//  sort(vals.begin(),vals.end());
//  for(int i=0;i<list.size();i++)
//      list[i]->val=vals[i];
//}

void recoverTree(TreeNode *root) {
    TreeNode *first = NULL;//第一个逆序的节点
    TreeNode*second = NULL;//第二个逆序的节点
    TreeNode*parent = NULL;//中序遍历的前一个节点
    TreeNode *cur, *pre;
    cur = root;
    while(cur){
        if(cur->left==NULL){
            if(parent&&parent->val>cur->val){
                if(first==NULL)
                    first=parent;
                second=cur;
            }
            parent=cur;
            cur=cur->right;
        }
        else
        {
            pre=cur->left;
            while(pre->right&&pre->right!=cur)pre=pre->right;
            if(pre->right==NULL){
                pre->right=cur;
                cur=cur->right;
            }
            else
            {
                pre->right=NULL;
                if(parent->val>cur->val)
                {
                    if(first==NULL)
                        first=parent;
                    second=cur;
                }
                parent=cur;
                cur=cur->right;
            }
        }
    }
//    while (cur) {
//        if (cur->left==NULL) {
//            if (parent && parent->val > cur->val) {
//                if (first==NULL) first = parent;
//                second = cur;
//            }
//            parent = cur;
//            cur = cur->right;
//        } else {
//            pre = cur->left;
//            while (pre->right && pre->right != cur) pre = pre->right;
//            if (!pre->right) {
//                pre->right = cur;
//                cur = cur->left;
//            } else {
//                pre->right = NULL;
//                if (parent->val > cur->val) {
//                    if (first==NULL) first = parent;
//                    second = cur;
//                }
//                parent = cur;
//                cur = cur->right;
//            }
//        }
    if (first && second) swap(first->val, second->val);
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
    TreeNode *l1=new TreeNode(1);
    TreeNode*l2=new TreeNode(2);
    TreeNode*l3=new TreeNode(3);
    TreeNode*l4=new TreeNode(4);
//    l3->left=l1;
//    l3->right=l4;
//    l4->left=l2;
        l2->left=l1;
        l1->right=l3;
    readTree(l2);
    recoverTree(l2);
    readTree(l2);
    return 0;
}

