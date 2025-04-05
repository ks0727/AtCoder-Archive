#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    vector<int> to(26,-1);
    int rest = 0;
    for(int i=0;i<n;i++){
            if(to[s[i]-'a'] == -1) to[s[i]-'a']=t[i]-'a';
            else{
                if(to[s[i] - 'a'] != t[i] - 'a'){
                    cout << -1 << endl;
                    return 0;
                }
            }
    }
    for(int i=0;i<n;i++) if(to[i] == -1) rest++;
    vector<bool> seen(n);
    int ans = 0;
    for(int i=0;i<26;i++){
        int v= i;
        set<int> st;
        while(true){
            v = to[v];
            if(v == -1) break;
            if(st.count(v)) break;
            st.insert(v);
        }
        if(v == -1){
            ans += st.size();
            for(int x : st) seen[x] = true;
            continue;
        }
        else if(v == i){
            if(rest == 0){
                cout << -1 << endl;
                return 0;
            }
            rest--;
            ans += st.size()+1;
        }
    }
    cout << ans << endl;
    return 0;
}