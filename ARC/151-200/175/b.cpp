#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n; ll a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int n2 = 2*n;
    int fw = 0;
    rep(i,n2){
        if(s[i] == '(') fw++; 
    }
    ll ans = 0;
    if(fw < n){ // '('が不足している時
        ll shortage = n - fw;
        ans += b*shortage;
        rep(i,n){
            if(s[i] == ')'){
                s[i] = '(';
                shortage--;
                if(shortage <= 0) break;
            }
        }
    }else if(fw > n){ // ')'が不足している時
        ll shortage = fw-n;
        ans += b*shortage;
        for(int i = n2-1;i>=n;i--){
            if(s[i] == '('){
                s[i] = ')';
                shortage--;
                if(shortage <= 0) break; 
            }
        }
    }
    //以上で置き換え作業完了
    //以下正しい括弧列にする作業
    int wrong = 0;
    int over = 0;
    rep(i,n2){
        if(s[i] == '(') over++;
        else{
            if(over == 0){
                wrong++;
                over = 1;
            }else over--; 
        }
    }
    ll flip = min(a,2*b);
    ans += (ll)flip*(ll)wrong;
    cout << ans << endl;
}