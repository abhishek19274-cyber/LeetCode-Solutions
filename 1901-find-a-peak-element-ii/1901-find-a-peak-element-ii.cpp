class Solution {
public:
    int row_max(vector<vector<int>>& mat,int mid){
        int curr_max = INT_MIN;
        int index= -1;
        for(int i=0;i<mat.size();i++){
            if(curr_max<mat[i][mid]){
                index = i;
                curr_max = mat[i][mid];
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size()-1;
        while(low <= high){
            int mid = low +((high - low)>>1);// this will give us the column we want to search in 
            int row = row_max(mat,mid);
            int left = mid-1>=0 ? mat[row][mid-1]:-1;
            int right = mid+1 <mat[0].size()?mat[row][mid+1]:-1;
            if(left < mat[row][mid] and right < mat[row][mid]){
                return {row,mid};
            }
            else if(left > mat[row][mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            
        }
        return {-1,-1};

    }
};