//
// Created by dyf on 18-12-9.
//

#include<iostream>
#include<vector>

void sortColors(std::vector<int>& nums) {
    int a=0;
    int b=0;
    int c=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0)
            a++;
        if(nums[i]==1)
            b++;
        if(nums[i]==2)
            c++;
    }

    for(int i=0;i<a;i++){
        nums[i]=0;
    }
    for(int i=a;i<a+b;i++)
        nums[i]=1;
    for(int i=a+b;i<a+b+c;i++){
        nums[i]=2;
    }
}

void sortColors(std::vector<int>& nums) {
   int l=0;
   int r=nums.size()-1;
   int temp=-1;
   int i=0;
   while(i<nums.size()){
           if (nums[i] == 0) {
               if(l<i) {
                   temp = nums[i];
                   nums[i] = nums[l];
                   nums[l] = temp;
                   l++;
               }
               else
                   i++;
           } else if (nums[i] == 2) {
               if(r>i) {
                   temp = nums[i];
                   nums[i] = nums[r];
                   nums[r] = temp;
                   r--;
               }else
                   i++;
           }
           else
               i++;
   }
}


int main(){
    std::vector<int> a={2,0,2,1,1,0};
    sortColors(a);
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
};