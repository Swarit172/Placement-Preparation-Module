#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triangle(int n){
	vector<vector<int>> ans;
	for(int i=0;i<n;i++){
		vector<int> row(i+1,1);  // initialize a row with every element as 1 and row size (i+1)
		for(int j=1;j<i;j++){
			row[j] = ans[i-1][j] + ans[i-1][j-1];
		}
		ans.push_back(row);
	}
	return ans;
}

int main(){
	int numRow = 5;
	vector<vector<int>> an = triangle(numRow);
	// int row = an.size();
	// int col = an[row].size();
	for(int i=0;i<numRow;i++){
		for(int j=0;j<numRow;j++){
			if(j>i) continue;
			cout<<an[i][j]<<" ";
		}
		cout<<endl;
	}
	 return 0;
}
