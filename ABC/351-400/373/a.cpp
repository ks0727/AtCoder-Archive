#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    vector<string> s(12);
    rep(i,12) cin >> s[i];
    int cnt = 0;
    rep(i,12){
        if(s[i].size() == i+1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}