#include <bits/stdc++.h>
using namespace std;

int maxSubarray(int* arr,int l){
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<l;i++){
        sum+=arr[i];
        maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

int main(){
    int arr[]={-2,1,-3,4,-1,2,1,-5,4};
    int l = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum sum of subarray: "<<maxSubarray(arr,l);
    return 0;
}