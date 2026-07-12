class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_min =0;
        int column_min =0;
        int row_max = matrix.size()-1;
        int column_max = matrix[0].size()-1;
        vector<int> result;
        int direction =0;
        while(row_min <=row_max and column_min <= column_max){
            if(direction == 0){
                for(int i=column_min;i<=column_max;i++){
                    result.push_back(matrix[row_min][i]);
                }
                row_min++;
            }
            if(direction==1){
                for(int i = row_min;i<=row_max;i++){
                    result.push_back(matrix[i][column_max]);
                }
                column_max--;
            }
            if(direction==2){
                for(int i=column_max;i>=column_min;i--){
                    result.push_back(matrix[row_max][i]);
                }
                row_max--;
            }
            if(direction==3){
                for(int i =row_max;i>=row_min;i--){
                    result.push_back(matrix[i][column_min]);
                }
                column_min++;
            }
            direction = (direction+1)%4;
        }
        return result;
    }
};