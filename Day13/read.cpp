#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,vis[N];
ll x,a[N],b[N];
bool check(ll x){
    int p=1,l=1,r=1;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        ll dis=abs(b[r]-b[l])+min(abs(a[i]-b[l]),abs(a[i]-b[r]));
        while(r<=m&&dis<=x){
            r++;
            dis=abs(b[r]-b[l])+min(abs(a[i]-b[l]),abs(a[i]-b[r]));
        }
        l=r;
        if(r==m+1) return 1;
    }
    return 0;
}

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    ll l=0,r=1e18;
    while(l<=r){
        ll mid=l+r>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}