#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n; cin >> n;
    vector<int> ls,rs;
    rep(i,n){
        int a; char c;
        cin >> a >> c;
        if(c == 'L') ls.push_back(a);
        else rs.push_back(a);
    }
    int l = 0,r = 0;
    if(ls.size() >= 1){
        rep(i,ls.size()-1){
            l += abs(ls[i+1] - ls[i]);
        }
    }
    if(rs.size() >= 1){
        rep(i,rs.size()-1){
            r += abs(rs[i+1] - rs[i]);
        }
    }
    cout << l + r << endl;
    return 0;
}