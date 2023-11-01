#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin >> s >> t;
    string joker = "atcoder";
    map<char,int> mp_s,mp_t;
    int size = s.size();
    rep(i,size) mp_s[s[i]]++;
    rep(i,size) mp_t[t[i]]++;
    for(auto [c,num] : mp_s){
        if(c == '@') continue;
        if(mp_t.count(c)){
            int consume = 0;
            consume = mp_s[c] - mp_t[c];
            bool ok = false;
            rep(i,joker.size()){
                if(c == joker[i]){
                    ok = true;
                    break;
                }
            }
            if(!ok && consume != 0){
                cout << "No" << endl;
                return 0;
            }
            if(consume > 0) mp_t['@'] -= consume;
            else mp_s['@'] -= consume;
            if(mp_s['@'] < 0 || mp_t['@'] < 0){
                cout << "No" << endl;
                return 0;
            }
            mp_s[c] = 0; mp_t[c] = 0;
        }else{
            bool ok = false;
            rep(i,joker.size()){
                if(c == joker[i]){
                    ok = true;
                    break;
                }
            }
            if(!ok){
                cout << "No" << endl;
                return 0;
            }
            mp_t['@'] -= mp_s[c];
            if(mp_t['@'] < 0){
                cout << "No" << endl;
                return 0;
            }
            mp_s[c] = 0;
        }
    }
    for(auto [c,num] : mp_t){
        if(c == '@') continue;
        if(num == 0) continue;
        bool ok = false;
        rep(i,joker.size()){
            if(c == joker[i]){
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << "No" << endl;
            return 0;
        }
        mp_s['@'] -= num;
        if(mp_s['@'] < 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}