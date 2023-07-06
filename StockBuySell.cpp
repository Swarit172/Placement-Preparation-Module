/* Best Time to Buy and Sell Stock - Leetcode - Striver sheet
    we move forward by checking each profit(line14) and storing min value for back(line 15)
*/

#include<bits/stdc++.h>
using namespace std;

int BuySell(int prices[], int l){
    int minn = prices[0];
    int profit = 0;

    for(int i=1;i<l;i++){
        int cost = prices[i] - minn;
        profit = max(profit,cost);
        minn = min(minn,prices[i]); 
    }
    return profit;
}

int main(){
    int prices[] = {7,1,5,3,6,4};
    int l = sizeof(prices)/sizeof(prices[0]);
    cout<<BuySell(prices,l);
    return 0;
}
