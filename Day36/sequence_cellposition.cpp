#include<iostream>
using namespace std;

int main()
{
vector<pair<int, int>> points ={{1,1},{2,2},{2,3}};
  int steps = minSteps(points);
  int sum=0;
for(int i=1;i<points;i++)
  {

int xDiff = abs(points[i].first-points[i-1].first);
int yDiff = abs(points[i].second-points[i-1].second);
    sum+=max(xDiff, yDiff);
  }
  cout<<sum;
  
}
