#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    for(int w=1;w<n;w++){
        rep(i,w){
            string ns = "";
            int now = i;
            while(now < n){
                ns += s[now];
                now += w;
            }
            if(ns == t){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}