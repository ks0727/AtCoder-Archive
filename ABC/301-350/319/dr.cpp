#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    ll sum = 0;
    rep(i,n) sum += (ll)l[i];
    ll w = (sum+2)/3;
    while(1){
        int ls = 0;
        ll now = 0;
        rep(j,n-1){
            if(now == 0) now = (ll)l[j];
            else{
                if(now+1+(ll)l[j+1] <= w){
                    now += (ll)l[j+1]+1;
                }else{
                    ls++;
                    if(ls > m) break;
                    now = 0;
                }
            }
        }
        if(ls == m){
            cout << w << endl;
            return 0;
        }
        w++;
    }
    return 0;
}