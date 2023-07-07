/* Sort Colors - Leetcode - Striver Sheet
   approach 1: using Dutch National Flag Algo.
   approach 2: Any sorting technique
   approach 3: counting method-count all 0s,1s,2s 
               nd insert that many 0s,1s,2s alternatively

    approach 1 USED
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> sortColors(vector<int>& nums,int l) {
        int low = 0;
        int mid = 0;
        int high = l - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if (nums[mid] == 1)
                mid++;

            else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
                
            }
        }
        return nums;
    }


int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    int l = nums.size();
    
    
    nums = sortColors(nums,l);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
