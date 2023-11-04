#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    rep(i,m) cin >> a[i];
    rep(i,m) cin >> b[i];
    set<int> zero,one;
    rep(i,m){
        if(a[i] == b[i]){
            cout << "No" << endl;
            return 0;
        }
        bool azero = zero.count(a[i]);
        bool bzero = zero.count(b[i]);
        bool aone = one.count(a[i]);
        bool bone = one.count(b[i]);
        if(azero && bzero){
            cout << "No" << endl;
            return 0;
        }
        if(aone && bone){
            cout << "No" << endl;
            return 0;
        }
        if(aone && bzero) continue;
        if(bone && azero) continue;
        if(azero && !bzero){
            one.insert(b[i]);
            continue;
        }
        if(bzero && !azero){
            one.insert(a[i]);
            continue;
        }
        if(aone && !bone){
            zero.insert(b[i]);
            continue;
        }
        if(bone && !aone){
            zero.insert(a[i]);
            continue;
        }
        else{
            zero.insert(a[i]);
            one.insert(b[i]);
        }
    }
    cout << "Yes" << endl;
    return 0;
}