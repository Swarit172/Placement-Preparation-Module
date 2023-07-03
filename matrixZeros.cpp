/* 73. Set Matrix Zeros (Leetcode )
	if any element in 2D array is 0...
	mark all element in row nd column with 0.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int x=1;
        int y=1;

        //selecting if any element in firstCol is 0  
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0)
                y=0;
        }

        //selecting if any element in firstRow is 0  
        for(int j=0;j<col;j++){
            if(matrix[0][j]==0)
                x=0;
        }

        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //if anyone in firstCol is zero 
        //mark all row nd col to 0 
        for(int i=1;i<row;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<col;j++){
                    matrix[i][j]=0;
                }
            }
        }
        //if anyone in firstRow is zero 
        //mark all row nd col to 0 
        for(int i=1;i<col;i++){
            if(matrix[0][i]==0){
                for(int j=0;j<row;j++){
                    matrix[j][i]=0;
                }
            }
        }
        
        if(y==0){ //mark all element in col with 0
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }

        if(x==0){ //mark all element in row with 0
            for(int i=0;i<col;i++){
                matrix[0][i]=0;
            }
        }

    }
};
