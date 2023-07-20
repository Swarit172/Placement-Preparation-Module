// Nth Root Of Integer
// Return the 'nth' root of 'm' i.e 'm**(1/n)'

#include<bits/stdc++.h>
using namespace std;

double mull(double x, int n){
    int mul=1;
    for(int i=0;i<n;i++)
        mul = x*mul;
    return mul;
}

int NthRoot(int n,int m){
    int low = 0;
    int high = m;
    while(low<=high){
        int mid = (low+high)/2;
        
        double mul = mull(mid,n);

        if(mul == m) return mid;
        else if(mul > m) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main(){
    int n,m;

    cout<<"Nth root of m is: "<<NthRoot(3,27);

    return 0;
}

