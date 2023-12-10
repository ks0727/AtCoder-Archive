#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), p(n-1);
    rep(i,n) cin >> a[i];
    rep(i,n-1) cin >> p[i];
    vector<int> b;
    b = a;
    set<int> st;
    rep(i,n-1){
        if(p[i] == 1){
            st.insert(i+1);
        }
    }
    rep(i,n-1){
        b[p[i]-1] = b[p[i]-1] + a[i+1];
    }
    vector<int> diff(n);
    rep(i,n){
        if(st.count(i)) diff[i] = b[i] - a[i];
    }
    ll sum = 0;
    for(int i = 1;i<(n);i++) sum += diff[i];
    if(sum > 0){
        cout << '+' << endl;
        return 0;
    }else if(sum < 0){
        cout << '-' << endl;
        return 0;
    }else{
        if(a[0] > 0){
            cout << '+' << endl;
            return 0;
        }else if(a[0] < 0){
            cout << '-' << endl;
            return 0;
        }else{
            cout << 0 << endl;
            return 0;
        }
    }
    return 0;
}