#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    vector<bool> small(n);
    vector<bool> big(n);
    vector<string> x;
    rep(i,n){
        if(s[i] > t[i]){
            s[i] = t[i];
            x.push_back(s);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i] < t[i]){
            s[i] = t[i];
            x.push_back(s);
        }
    }
    cout << x.size() << endl;
    for(string xs : x) cout << xs << '\n';
    return 0;
}