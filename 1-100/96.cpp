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

int numTrees(int n) {
    std::vector<int> a(n+1);
    a[0]=0;
    a[1]=1;
    a[2]=2;
    if(n<=2)
        return a[n];
    for(int i=3;i<n+1;i++){
        if(i%2==1) {
            for (int j = 1; j <= (i + 1) / 2; j++) {
                if (j == 1)
                    a[i] += a[i - 1] * 2;
                else if(j==(i+1)/2)
                    a[i] += a[i - j] * a[j - 1];
                else
                    a[i] += a[i - j] * a[j - 1]*2;
            }
        }
        else
        {
            for (int j = 1; j <= i/ 2; j++) {
                if (j == 1)
                    a[i] += a[i - 1] * 2;
                else
                    a[i] += a[i - j] * a[j - 1]*2;
            }
        }
    }
    return a[n];
}

int main()
{
    long long d=18;
    std::cout<<numTrees(d)<<std::endl;
    return 0;
}