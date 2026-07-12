class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal_triangle;
        pascal_triangle.resize(numRows);
        for(int i=0;i<numRows;i++){
            pascal_triangle[i].resize(i+1);
            for(int j=0;j<pascal_triangle[i].size();j++){
                if(j==0 or j==pascal_triangle[i].size()-1){
                    pascal_triangle[i][j]=1;
                }
                else{
                    pascal_triangle[i][j]=pascal_triangle[i-1][j-1]+pascal_triangle[i-1][j];
                }
            }
        }
        return pascal_triangle;
    }
};