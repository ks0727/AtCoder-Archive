#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin >> s >> t;
    int n = t.size();
    vector<bool> fro(n),bac(n);
    bool ok = true;
    rep(i,n){
        if(s[i] != t[i] && s[i] != '?' && t[i] != '?'){
            break;
        }
        fro[i] = true;
    }
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    rep(i,n){
        if(s[i] != t[i] && s[i] != '?' && t[i] != '?'){
            break;
        }
        bac[i] = true;
    }
    int back = n;
    int front = 0;
    while(back >= 0){
        if(front == 0){
            if(bac[back-1]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        if(back == 0){
            if(fro[front-1]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        if(front > 0 && back > 0){
            if(bac[back-1] && fro[front-1]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        front++;
        back--;
    }
    return 0;
}