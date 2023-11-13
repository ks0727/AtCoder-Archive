#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    int loops = 0;
    dsu uf(n);
    rep(i,m){
        int a,c; char b,d;
        cin >> a >> b >> c >> d;
        a--; c--;
        if(uf.same(a,c)) loops++;
        else{
            uf.merge(a,c);
        }
    }
    set<int> leaders;
    rep(i,n){
        leaders.insert(uf.leader(i));
    }
    cout << loops << ' ' << leaders.size() - loops << endl;
    return 0;
}