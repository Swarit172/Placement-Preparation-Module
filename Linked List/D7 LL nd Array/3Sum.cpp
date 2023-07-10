#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            int a=nums[i];
            int t=-a;
            int start=i+1,end=n-1;
            while(start<end){
                if(nums[start]+nums[end]==t){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    while(start<end && nums[start]==nums[start+1])start++;
                    while(start<end && nums[end]==nums[end-1])end--;
                    start++;
                    end--;
                }
                else if(nums[start]+nums[end]>t){
                    end--;
                }
                else{
                    start++;
                }
            }
            while(i+1<n && nums[i+1]==nums[i])i++;
        }
        return ans;
    }

int main(){
    vector<int> nums;
    nums = {-1,0,1,2,-1,-4};
    
    vector<vector<int>> a = threeSum(nums);
    cout<<"[ ";
    for(int i=0;i<a.size();i++){
        cout<<"[ ";
        for(int j=0;j<a[0].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"] ";
        //cout<<endl;
    }
    cout<<"]";
}