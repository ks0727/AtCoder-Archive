#include <bits/stdc++.h>
using namespace std;
#include<atcoder/dsu>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    cin >> n >> m;
    int ans = 0;
    dsu uf(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(!uf.same(a,b)) uf.merge(a,b);
        else ans++;
    }
    cout << ans << endl;
    return 0;
}