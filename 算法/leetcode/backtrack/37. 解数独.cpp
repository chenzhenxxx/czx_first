class Solution {
public:
    bool backtracking(vector<vector<char>>& board)
    {
         
         for(int i=0;i<board.size();i++)
         {
             for(int j=0;j<board[0].size();j++)
             {
                 if(board[i][j]!='.') continue;
                 for(char k='1';k<='9';k++)
                 {
                     if(isVaild(board,i,j,k))
                     {
                         board[i][j]=k;
                         if(backtracking(board)) return true;
                         board[i][j]='.';
                     }
                 }
                 return false;
             }
         }
         return true;
    }
    bool isVaild(vector<vector<char>>& board,int row,int col,char val)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==val||board[i][col]==val) return false;
        }
        int startrow = (row/3)*3;
        int startcol = (col/3)*3;
        for(int i=startrow;i<startrow+3;i++)
        {
            for(int j=startcol;j<startcol+3;j++)
            {
                 if(board[i][j]==val) return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
      backtracking(board);
    }
};