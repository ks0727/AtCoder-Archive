#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    int ans = 0;
    bool pa = false;
    rep(i,s.size()){
        if(pa){
            pa = false;
            continue;
        }
        if(i != s.size()-1 && s[i] == '0' && s[i+1] == '0'){
            ans++;
            pa = true;
        }else{
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}