class Solution {
public:
    void solution(int col,int n,vector<int>& left_row,vector<int>& lower_diagnol,vector<int>& upper_diagnol,vector<vector<string>>& result,vector<string> &board){
        if(col == n){
            result.push_back(board);
            return ;
        }
        for(int i =0;i<n;i++){
            if(left_row[i]==0 and lower_diagnol[i+col]==0 and upper_diagnol[n-1 + col - i]==0){
                board[i][col] = 'Q';
                left_row[i]=1;
                lower_diagnol[i+col] =1;
                upper_diagnol[n-1+col-i]=1;
                solution(col+1,n,left_row,lower_diagnol,upper_diagnol,result,board);
                board[i][col] ='.';
                left_row[i]=0;
                lower_diagnol[i+col] =0;
                upper_diagnol[n-1+col-i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> left_row(n,0),lower_diagnol(2*n-1,0),upper_diagnol(2*n-1,0);
        vector<string> board(n);
        vector<vector<string>> result;
        for(int i=0;i<n;i++){
            board[i] = string(n,'.');
        }
        solution(0,n,left_row,lower_diagnol,upper_diagnol,result,board);
        return result;
    }
};