#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int removeElem(vector<int>& nums, int targets){
        int size = nums.size();
        for(int i = 0; i<size; i++){
            if(nums[i] == targets){
                // for(int j = i ; j<size; j++){
                //     nums[j] = nums[j+1];
                // }
                nums[i]=nums[i+1];
                // nums[i].erase();
                size = size-1;
            }
        }
        return size;
    }
};


int main(){
    vector<int> nums = {3, 2, 2, 3};
    Solution s;
    int x = s.removeElem(nums, 3);
    for(int i =0; i<x; i++){
        cout<<nums[i]<<endl;
    }
}