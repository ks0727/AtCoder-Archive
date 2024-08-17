#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26);
    rep(i,n) cnt[s[i]-'a']++;
    string ans = s;
    int diff_l = 0;
    string t = "";
    rep(i,n){
        rep(j,26){
            if(cnt[j] != 0){
                t += 'a'+j;
                cnt[j]--;
                break;
            }
        }
        if(s[i] != t[i]){
            diff_l++;
        }
        int rest = k - diff_l;
        if(rest < 0) break;
        int error = 0;
        vector<int> cur = cnt;
        string latter  = "";
        for(int j = i+1;j<n;j++){
            int ch = s[j] - 'a';
            if(cur[ch] == 0){
                error++;
                latter += '?';
            } 
            else{
                cur[ch]--;
                latter += s[j];
            }
        }
        if(error > rest) break;
        rep(j,latter.size()){
            if(latter[j] == '?'){
                rep(k,26){
                    if(cur[k] != 0){
                        cur[k]--;
                        latter[j] = 'a' + k;
                        break;
                    }
                }
            }
        }
        string now = t + latter;
        ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}