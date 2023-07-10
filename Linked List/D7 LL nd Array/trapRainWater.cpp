#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
        int l = height.size();
        int preheight[l];
        int sufheight[l];
        int watertrap = 0;

        //storing max value from left 
        preheight[0] = height[0];
        for(int i=1;i<l;i++){
            preheight[i] = max(preheight[i-1], height[i]);
        }

        //stroing max height from right
        sufheight[l-1] = height[l-1];
        for(int i=l-2;i>=0;i--){
            sufheight[i] = max(sufheight[i+1], height[i]);
        }
        //calculating water trapped b/w pre nd sufheight
        for(int i=0;i<l;i++){
            watertrap += min(preheight[i], sufheight[i]) - height[i];
        }

        return watertrap;
}

int main(){
    vector<int> height;
    height = {0,1,0,2,1,0,1,3,2,1,2,1};
    //int n = height.size();
    int ans = trap(height);
    cout<<"Water trapped between heights is: "<<ans;
}




