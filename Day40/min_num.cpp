#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
vector<int> bulbs(num);
  vector<int> state(num);
  vector<int> dist(num);
for(int i=0;i<num;i++)
  {
cin>>state[i];
  }

  for(int i=0;i<num;i++)
    {

cin>>dist[i];
    }

  int total=0;
  for(int i=1;i<num;i++)
    {
if(state[i]==0) {
int nearest=-1;
   for (int j = i - 1; j >= 0; --j) {
                if (state[j] == 1) {
                    nearestOn = j;
                    break;
                }
            }
            if (nearestOn != -1) {
                totalCable += distance[i] - distance[nearestOn];
            }
        }
    }

    cout << totalCable << endl;

    return 0;
}
