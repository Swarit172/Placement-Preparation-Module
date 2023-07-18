// Search In A Sorted Rotated Array

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> nums,int target){
    int low = 0;
    int high = nums.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(nums[mid] == target) return mid;

        if(nums[low] < nums[mid]){
            if(nums[low] <= target && nums[mid] >= target)
                high = mid-1;
            else    
                low = mid+1;
        }
        else{
            if(nums[mid] <= target && nums[high] >= target) 
                low = mid+1;
            else
                high = mid-1;
       }
    }
    return -1;
}

int main(){
    vector<int> nums;
    nums = {4,5,6,7,0,1,2};
    int target = 0;

    int ele = Search(nums,target);
    cout<<"Element is found at index: "<<ele;

    return 0;
}