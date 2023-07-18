// Single Element In A Sorted Array - Leetcode

#include<bits/stdc++.h>
using namespace std;

int SingleEle(vector<int>& nums){
    int low=0;
    int high = nums.size()-1;

    if(high==0) return nums[0];
    else if(nums[0]!=nums[1]) return nums[0];
    else if(nums[high]!=nums[high-1]) return nums[high];

    while(low <= high){
        int mid = low + (high-low)/2;

        if((nums[mid]!=nums[mid+1]) && (nums[mid]!=nums[mid-1]))
            return nums[mid];
        else if((mid%2==0 && nums[mid+1]==nums[mid]) || (mid%2==1 && nums[mid-1]==nums[mid]))
            low = mid+1;
        else    
            high = mid-1;
    }
    return -1;
}

int main(){
    vector<int> nums;
    nums ={1,1,2,3,3,4,4,8,8};
    int ele = SingleEle(nums);
    cout<<"Single element in array is: "<<ele;
    return 0;
}