#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    vector<int> ans(n,-1);
    int r = 1;
    while(true){
        int changed = 0; 
        int now = 0;
        for(int i=0;i<n;i++){
            if(ans[i] == -1) now = max(now,p[i]);
        }
        for(int i=0;i<n;i++)if(p[i] == now){
            ans[i] = r;
            changed++;
        } 
        if(changed == 0) break;
        r += changed;
    }
    for(int i=0;i<n;i++) cout << ans[i] << endl;
    return 0;
}