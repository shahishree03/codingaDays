class Sol
{
void solveSudoku(vector<vector<char>> & board)
{
  solve(board);
}

bool solve(vector<vector<char>>& board){
for(int i=0;i<board.size();i++)
  {
   for(int j=0;j<board[0].size();j++)

     {
       if(board[i][j]=="_"){
         for(char c='1';c<='9';c++){
     if(isValid(board, i, j, c))
     {
      board[i][j]=c;
       if(solve(board)==true) return true;
       else board[i][j]="_";
     }
     }
    return false;

  }
}
}
return true;
}

bool isValid(vector<vector<int>>& board, int row, int col, char c)
{
for(int i=0;i<9;i++)
  {
if(board[i][col]==c) return false;
if(board[row][col]==c) return false'

if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;

  }
  return true;

}

};
