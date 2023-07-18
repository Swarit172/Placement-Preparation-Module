#include<bits/stdc++.h>
using namespace std;

// Naive Approach , TC-O(m+n)...SC-O(m+n)
// Make new array...merge it...find median
    // int MedianOfArray(vector<int>& arr1, vector<int>& arr2){
    //     int n = arr1.size();
    //     int m = arr2.size();
    //     int mergeArr[n+m];
    //     int i=0,j=0,k=0;

    //     while(i<n && j<m){
    //         if(arr1[i] < arr2[j]){
    //             mergeArr[k++] = arr1[i];
    //             i++;
    //         }
    //         else{
    //             mergeArr[k++] = arr2[j];
    //             j++;
    //         }
    //     }

    //         while(i<n){
    //             mergeArr[k++] = arr1[i++];
    //         }
        
    //         while(j<m){
    //             mergeArr[k++] = arr2[j++];
    //         }
        
    //     //Median
    //     int x  = n+m;
    //     if(x%2==0){
    //         return ((float)mergeArr[(x/2)-1] + (float)mergeArr[x/2])/2;
    //     }
    //     else{
    //         return (mergeArr[((x+1)/2)-1]);
    //     }
    // }

// For TC - O(log(m+n))
int MedianOfArray(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    int begin1 = 0;
    int end1 = n;

    while(begin1 <= end1){
        int i1 = (begin1+end1)/2;
        int i2 = (n+m+1)/ - i1;

        int min1 = (i1==n) ? INT_MAX : arr1[i1];
        int max1 = (i1==0) ? INT_MIN : arr1[i1-1];

        int min2 = (i2==n) ? INT_MAX : arr2[i2];
        int max2 = (i2==0) ? INT_MIN : arr2[i2-1];

        if((max1 <= min2) && (max2 <= min1)){
            if((n+m)%2==0){
                return ((double) (max(max1,max2) + min(min1,min2))/2);
            }
            else{
                return ((double) max(max1,max2));
            }
        }
        else if(max1>min2){
            end1 = i1-1;
        }
        else{
            begin1 = i1+1;
        }

    }

}

int main(){
    vector<int> arr1,arr2;
    arr1 = {10,20,30};
    arr2 = {5,15,25,35,45};

    //int median = MedianOfArray(arr1,arr2);
    cout<<"Median of two sorted array is: "<<MedianOfArray(arr1,arr2);

    return 0;
}