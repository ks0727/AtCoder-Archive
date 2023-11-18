#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26); 
    int num = 0;
    for(int i = 0;i<(n);i++){
        if(i == 0){
            num = 1;
            cnt[s[i] - 'a']++;
            continue;
        }
        if(s[i] == s[i-1]){
            num++;
            if(cnt[s[i]-'a'] < num) cnt[s[i]-'a'] = num;
        }else{
            num = 1;
            if(num > cnt[s[i]-'a']) cnt[s[i]-'a'] = num;
        }
    }
    ll ans = 0;
    rep(i,26) ans += cnt[i];
    cout << ans << endl;
    return 0;
}