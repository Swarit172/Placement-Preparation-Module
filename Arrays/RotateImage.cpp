#include<bits/stdc++.h>
using namespace std;

void rotateImage(vector<vector<int>>& mat){
    int row = mat.size();
    int col = mat[0].size();

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i!=j && j>i){
                swap(mat[i][j], mat[j][i]);
            }
        }
    }

    for(int i=0;i<row;i++){
        reverse(mat[i].begin(), mat[i].end());
    }

    //return mat;
}

int main(){
    int n=3;
    vector<vector<int>> mat;
    mat =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // cout<<"Enter row/col of matrix: ";
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>mat[i][j];
    //     }
    // }

    rotateImage(mat);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}