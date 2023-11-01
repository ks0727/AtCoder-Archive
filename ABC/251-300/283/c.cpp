#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    rep(i,n){
        if(s[i] != '0') ans++;
        else{
            if(i == n-1) ans++;
            else{
                if(s[i+1] == '0'){
                    ans++;
                    i++;
                }else{
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}