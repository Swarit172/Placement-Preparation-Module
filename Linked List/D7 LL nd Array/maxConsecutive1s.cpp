#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums, int n) {
    int count=0;
    int maxx = 0;
        //int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i] == 1){
            count++;
        }
        else{ //this condition is pased only when 0 comes in array...if all are 1s then this will not check
            maxx = max(maxx,count);
            count=0;
        }
    }
    maxx = max(maxx,count); // this is when arr=[1,1,1,1,1,1] it will check here
    return maxx;
}

int main(){
    vector<int> nums;
    nums = {0,0,0,1,0,1,1};
    int n = nums.size();
    int ans = findMaxConsecutiveOnes(nums,n);
    cout<<ans;
}
