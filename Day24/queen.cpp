class Sol{
public:

bool isSafe(int row, int col, vector<string> board, int n)
{
int dupr=row;
  int dupcol=col;
  while(row>=0 && col>=0)
    {

if(board[row][col]=='Q') return false;
      row--;
      col--;
    }
  col=dupcol;
  row=dupr;
  while(col>=0)
    {

if(board[row][col]=='Q') return false;
      col--;
    }
row=dupr;
  col=dupcol;
  while(row<n && col>= 0){
  if(board[row][col] =='Q') return false;
    row++;
    col--;
  }
  return true;
  
}
void solve(int col, vector<string>& board,  vector<vector<string>>& ans, int n)
{
if(col==n){
  ans.push_back(board)
  return;}

  for(int row=0;row<n;row++)
    {

if(isSafe(row, col, board, n))
{
board[row][col]=='Q';
  solve(col+1, board, ans, n);
  board[row][col]='';
}
    }


}

void solve2(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> & leftr, vector<int>& upperdiag, vector<int> &lowerdiag , int n)
{
if(col==n){
ans.push_back(board);
  return;
}
  for(int row=0;row<n;row++)
    {
     if(leftr[row]==0 && lowerdiag[row+col]==0 && upperdiag[n-1+col-row]==0)
     {

board[row][col]=='Q';
       leftr[row]==1;
       lowerdiag[row+col]==1;
       upperdiag[n-1+col-row]=1;
       solve(col+1,board, ans, leftr, upperdiag, lowerdiag, n);
       board[row][col]=' ';
       leftr[row]==0;
       lowerdiag[row+col]==0;
       upperdiag[n-1+col-row]=0;
       
     }
    }
}
vector<vector<string>> solveNQueen(int n)
{
vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, ' ');
  for(int i=0;i<n;i++)
    {
board[i]=s;
    }
//  solve(0, board, ans, n);
  vector<int> leftrow(n,0), upperdiag(2*n-1,0), lowerdiag(2*n-1,0);
  solve2(0, board, ans, leftrow, upperdiag, lowerdiag, n);
  return ans;
}
};

