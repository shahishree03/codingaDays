class Sol
{
public:
void func(int ind, int sum , vector<int> & arr,int N,  vector<int> &sumSubset)
{
  if(ind==N){
    sumzsubset.push_back(sum);
    return;
  }
  func(ind+1, sum+arr[ind], arr, N, sumSubset);
  func(ind+1, sum, arr, N , sumSubset);
}
vector<int> subsetsum(vector<int> arr, int n)
{
vector<int> sumSubset;
  
}



};
