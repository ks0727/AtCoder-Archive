#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    string s;
    cin >> s;
    vector<vector<int> > m(3,vector<int>(n+1));
    vector<vector<int> > x(3,vector<int>(n+1));
    rep(i,n){
        m[0][i+1] = m[0][i]; 
        m[1][i+1] = m[1][i]; 
        m[2][i+1] = m[2][i]; 
        if(s[i] == 'M'){
            if(a[i] == 0){
                m[0][i+1]++;
            }else if(a[i] == 1){
                m[1][i+1]++;
            }else{
                m[2][i+1]++;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        x[0][i] = x[0][i+1]; 
        x[1][i] = x[1][i+1]; 
        x[2][i] = x[2][i+1]; 
        if(s[i] == 'X'){
            if(a[i] == 0){
                x[0][i]++;
            }else if(a[i] == 1){
                x[1][i]++;
            }else{
                x[2][i]++;
            }
        }
    }
    //rep(i,n+1) cout << m[2][i] << ' '; cout << endl;
    //rep(i,n+1) cout << x[2][i] << ' '; cout << endl;
    ll ans = 0;
    rep(i,n){
        if(s[i] == 'E'){
            if(a[i] == 0){
                ans += (ll)m[0][i+1]*x[0][i+1];
                ans += (ll)m[0][i+1]*x[1][i+1]*2;
                ans += (ll)m[0][i+1]*x[2][i+1];
                ans += (ll)m[1][i+1]*x[0][i+1]*2;
                ans += (ll)m[1][i+1]*x[1][i+1]*2;
                ans += (ll)m[1][i+1]*x[2][i+1]*3;
                ans += (ll)m[2][i+1]*x[0][i+1];
                ans += (ll)m[2][i+1]*x[1][i+1]*3;
                ans += (ll)m[2][i+1]*x[2][i+1];
            }else if(a[i] == 1){
                ans += (ll)m[0][i+1]*x[0][i+1]*2;
                ans += (ll)m[0][i+1]*x[1][i+1]*2;
                ans += (ll)m[0][i+1]*x[2][i+1]*3;
                ans += (ll)m[1][i+1]*x[0][i+1]*2;
                ans += (ll)m[1][i+1]*x[1][i+1]*0;
                ans += (ll)m[1][i+1]*x[2][i+1]*0;
                ans += (ll)m[2][i+1]*x[0][i+1]*3;
                ans += (ll)m[2][i+1]*x[1][i+1]*0;
                ans += (ll)m[2][i+1]*x[2][i+1]*0;
            }else{
                ans += (ll)m[0][i+1]*x[0][i+1];
                ans += (ll)m[0][i+1]*x[1][i+1]*3;
                ans += (ll)m[0][i+1]*x[2][i+1];
                ans += (ll)m[1][i+1]*x[0][i+1]*3;
                ans += (ll)m[1][i+1]*x[1][i+1]*0;
                ans += (ll)m[1][i+1]*x[2][i+1]*0;
                ans += (ll)m[2][i+1]*x[0][i+1];
                ans += (ll)m[2][i+1]*x[1][i+1]*0;
                ans += (ll)m[2][i+1]*x[2][i+1]*0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}