class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       int hang[9][10];
       int lie[9][10];
       int martix[9][10];
       memset(hang,0,sizeof(hang));
       memset(lie,0,sizeof(lie));
       memset(martix,0,sizeof(martix));
      for(int i=0;i<9;i++)
      {   
          for(int j=0;j<9;j++)
      {   if(board[i][j]!='.')
          
          {
            int m=board[i][j]-'0';
          hang[i][m]++;
          lie[j][m]++;
          martix[3*(i/3)+j/3][m]++;
          }
      }
      }
      for(int i=0;i<9;i++)
      {   
          for(int j=0;j<=9;j++)
      {   if(hang[i][j]>1||lie[i][j]>1||martix[i][j]>1)
          return false;
      }
      }
      
    return true;

    }
};