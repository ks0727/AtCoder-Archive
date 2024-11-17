#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    string s;
    cin >> s;
    int Q;
    cin >> Q;
    vector<char> ans;
    while(Q--){
        ll k;
        cin >> k;
        k--;
        ll idx = k%s.size();
        ll r = k/s.size();
        int cnt = 0;
        while(r){
            if(r%2 == 1) cnt++;
            r/=2;
        }
        char c = s[idx];
        if(cnt%2 == 0) ans.push_back(c);
        else{
            if(isupper(c)) ans.push_back(tolower(c));
            if(islower(c)) ans.push_back(toupper(c));
        }
    }
    rep(i,ans.size()) cout << ans[i] << ' '; cout << endl;
    return 0;
}