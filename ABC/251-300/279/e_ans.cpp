#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    rep(i,m) a[i]--;
    vector<int> s(m);
    {
        int p = 0;
        rep(i,m){
            s[i] = p;
            if(a[i] == p) p++;
            else if (a[i]+1 == p) p--;
        }
    }
    vector<int> ans(m);
    {
        vector<int> p(n);
        rep(i,n) p[i] = i;
        for(int i=m-1;i>=0;i--){
            ans[i] = p[s[i]];
            swap(p[a[i]],p[a[i]+1]);
        }
    }

    rep(i,m) cout << ans[i] + 1 << endl;
    return 0;
}