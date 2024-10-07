#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s,t;
    cin >> s >> t;
    if(s == t){
        cout << 0 << endl;
        return 0;
    } 
    else{
        int n =s.size(),m = t.size();
        int sz = min(n,m);
        for(int i=0;i<sz;i++){
            if(s[i] != t[i]){
                cout << i+1 << endl;
                return 0;
            }
        }
        cout << sz+1<< endl;
        return 0;
    }
    return 0;
}