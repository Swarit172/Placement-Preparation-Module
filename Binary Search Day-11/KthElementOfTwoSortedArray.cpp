#include<bits/stdc++.h>
using namespace std;

// TC=O(log(m+n)), SC=(1)
int KthElement(vector<int>& arr1,vector<int>& arr2,int k){
    int n = arr1.size();
    int m = arr2.size();

    if(n>m) return KthElement(arr2,arr1,k);

    int low = max(0,k-m), high = min(k,n);

    while(low<=high){
        int i1 = (low+high)>>1;
        int i2 = k-i1;

        int min1 = (i1 == n) ? INT_MAX : arr1[i1];
        int max1 = (i1 == 0) ? INT_MIN : arr1[i1-1];

        int min2 = (i2 == m) ? INT_MAX : arr2[i2];
        int max2 = (i2 == 0) ? INT_MIN : arr2[i2-1];

        if(max1 <= min2 && max2 <= min1){
            return max(max1,max2);
        }
        else if(max1 > min2){
            high = i1-1;
        }
        else{
            low = i1+1;
        }
    }
    return 1;
}

int main(){
    vector<int> arr1,arr2;
    arr1 = {2,3,6,7,9};
    arr2 = {1,4,8,10};
    int k=5;
    cout<<"Kth element is: "<<KthElement(arr1,arr2,k);

    return 0;
}