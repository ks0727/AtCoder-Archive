#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int n = s.size();
    string ans = "";
    rep(i,n){
        if(i==0){
            ans+=s[i];
            continue;
        }
        if(s[i]=='A') {
            ans += 'A';
        }
        if(s[i] == 'B'){
            if(ans.back() == 'A' && i != n-1 && s[i+1] == 'C'){
                ans.pop_back();
                i++;
                continue;
            }else{
                ans += 'B';
            }
        }
        if(s[i] == 'C'){
            int na = ans.size();
            if(na >= 2 && ans[na-1] == 'B' && ans[na-2] == 'A'){
                ans.pop_back();
                ans.pop_back();
            }else{
                ans += 'C';
            }
        }
    }
    cout << ans << endl;
    return 0;
}