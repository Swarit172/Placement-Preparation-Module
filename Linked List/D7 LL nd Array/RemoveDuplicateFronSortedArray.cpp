#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        set<int> s;
        for(int i=0;i<l;i++){
            s.insert(nums[i]);
        }

        int n = s.size();
        int x=0;
        for(int z : s){    
            nums[x] = z;
            x++;
        }
        return n;
    }

int main(){
    vector<int> nums;
    nums = {0,0,1,1,1,2,2,3,3,4};

    int ans = removeDuplicates(nums);
    cout<<ans;
    
    
}