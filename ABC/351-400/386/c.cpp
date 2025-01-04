#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int k; string s,t;
    cin >> k >> s >> t;
    if(s.size() > t.size()) swap(s,t);
    if(t.size() > s.size()+1){
        cout << "No" << endl;
        return 0;
    }
    if(s.size() == t.size()){
        int dif = 0;
        rep(i,s.size()){
            if(s[i] != t[i]){
                dif++;
            }
            if(dif >= 2){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }else{
        int tidx = 0;
        bool ok = true;
        rep(i,s.size()){
            if(s[i] != t[tidx]){
                if(!ok){
                    cout << "No" << endl;
                    return 0;
                }
                tidx++;
                ok = false;
            }
            tidx++;
        }
        cout << "Yes" << endl;
    }
    return 0;
}