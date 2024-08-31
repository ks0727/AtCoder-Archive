#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    int x = n;
    int m = 0;
    x--;
    while(x > 0){
        x /= 2;
        m++;
    }
    cout << m << endl;
    vector<vector<int> > fs(m);
    rep(i,n){
        rep(j,m){
            if((i >> j) & 1){
                fs[j].push_back(i);
            }
        }
    }
    rep(i,m){
        if(fs[i].size() == 0) continue;
        cout << fs[i].size() << ' ';
        rep(j,fs[i].size()){
            cout << fs[i][j]+1 << ' ';
        }
        cout << endl;
    }
    string s;
    cin >> s;
    int ans= 0;
    rep(i,m){
        if(s[i] == '1'){
            ans += 1<<i;
        }
    }
    cout << ans+1 << endl;
    return 0;
}