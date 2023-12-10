#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int muji = m;
    int rogo = 0;
    int ans = 0;
    rep(i,n){
        if(s[i] == '0'){
            muji = m;
            rogo = ans;
        }
        else if(s[i] == '1'){
            if(muji > 0) muji--;
            else if(rogo > 0) rogo--;
            else{
                ans++;
            }
        }
        else if(s[i] == '2'){
            if(rogo > 0) rogo--;
            else ans++;
        }
    }
    cout << ans << endl;
    return 0;
}