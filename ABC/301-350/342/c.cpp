#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<set<int> > alph(26);
    rep(i,s.size()){
        alph[s[i]-'a'].insert(i);
    }
    rep(qi,q){
        char c,d;
        cin >> c >> d;
        if(c == d) continue;
        int ci = c-'a'; int di = d-'a';
        if(alph[ci].size() == 0) continue;
        if(alph[ci].size() < alph[di].size()){
            for(int x : alph[ci]) alph[di].insert(x);
            alph[ci].clear();
        }else{
            for(int x : alph[di]) alph[ci].insert(x);
            swap(alph[ci],alph[di]);
            alph[ci].clear();
        }
    }
    string ans = "";
    rep(i,n){
        rep(j,26){
            if(alph[j].count(i)) ans += 'a'+ j;
        }
    }
    cout << ans << endl;
    return 0;
}