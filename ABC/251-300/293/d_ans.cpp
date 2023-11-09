#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    dsu uf(n);
    int x = 0;
    rep(i,m){
        int a,c;
        char b,d;
        cin >> a >> b >> c >> d;
        a--; c--;
        if(uf.same(a,c)) x++;
        else uf.merge(a,c);
    }
    int y = n-m;
    cout <<x << ' ' << y << endl;
    return 0;
}