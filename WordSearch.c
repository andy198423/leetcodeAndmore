class Solution{
     public: bool exist(vector<vector<char>> &board, string word){
         int M=board.size();
         int N=board[0].size();
         vector<vector<bool>> visited(M,vector<bool>(N, false));         
         for(int i=0; i<M; i++){
            for(int j=0; j<N; j++)
            {
                if(existHelper(board, visited, word, 0, i, j)) return true;
            }
         }
         return false;
     }
     
     public: bool existHelper(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int pos, int i, int j){
         if(word[pos]!=board[i][j]) return false;
         if(pos+1==word.size()) return true;
         int M=board.size();
         int N=board[0].size();
         visited[i][j]=true;
         if((i>0 && !visited[i-1][j]) && existHelper(board, visited, word, pos+1, i-1, j)) return true;
         if((i<M-1 && !visited[i+1][j]) && existHelper(board, visited, word, pos+1, i+1, j)) return true;
         if((j>0 && !visited[i][j-1]) && existHelper(board, visited, word, pos+1, i, j-1)) return true;
         if((j<N-1 && !visited[i][j+1]) && existHelper(board, visited, word, pos+1, i, j+1)) return true;
         visited[i][j]=false;
         return false;
     }
};