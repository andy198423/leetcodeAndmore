class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> result;
        string row(n,'.');
        vector<string> board(n,row);
        solveNQueensHelper(board,result,0,n);
        return result;
    }
    
    void solveNQueensHelper(vector<string>& board, vector<vector<string>>& result, int cols, int n){
        if(cols==n){
           result.push_back(board);
           return;
        }
        for(int i=0; i<n; i++){
           if(isFit(board, i, cols, n)){
              board[i][cols]='Q';
              solveNQueensHelper(board,result,cols+1,n);
              board[i][cols]='.';
           }
        }
    }
    
    bool isFit(vector<string>& board, int row, int col, int n){
        int i=row, j=0;
        while(j<col)
            if(board[i][j++]=='Q') return false;
        i=row, j=col;
        while(i>=0 && j>=0)
            if(board[i--][j--]=='Q') return false;
        i=row, j=col;
        while(i<n && j>=0)
            if(board[i++][j--]=='Q') return false;
        return true;
    }
};