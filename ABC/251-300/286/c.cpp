#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int same = 10000;
    rep(i,n){
        if(s[i] == s[i+1]){
            same = i;
            break;
        }
    }
    long long ans = 0;
    if((long long)(same+1)*a < b){
        string t = s;
        rep(i,n){
            s[i] = t[(i+same+1)%n];
        }
        ans += (long long)(same+1)*a;
    }
    //cout << s << endl;
    //cout << ans << endl;
    for(int i=0;i*2<(n);i++){
        if(s[i] == s[n-i-1]) continue;
        else{
            s[i] = s[n-i-1];
            ans += (long long)b;
            cout << i << endl;
        }
        cout << s << endl;
    }
    cout << ans << endl;
}