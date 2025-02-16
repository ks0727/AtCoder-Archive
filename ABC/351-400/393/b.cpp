#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for(int d=1;d<n;d++){
        rep(i,n){
            if(s[i] != 'A') continue;
            if(i+2*d >= n) continue;
            string now =  "";
            now += s[i];
            now += s[i+d];
            now += s[i+2*d];
            if(now == "ABC") ans++;
        }
    }
    cout << ans << endl;
    return 0;
}