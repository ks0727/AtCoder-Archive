#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll tos(vector<int> x){
    ll res = 0;
    rep(i,60) res += (ll)x[i]<<i;
    return res;
}

int main(){
    ll a,b,c;
    const int M = 60;
    cin >> a >> b >> c;
    ll one = __builtin_popcountll(c);
    ll zero = M-one;

    ll d = a+b-one;
    if(d<0 || d%2 == 1){
        cout << -1 << endl;
        return 0;
    }
    d /= 2;
    a -= d; //残りのaは1にするべき
    b -= d; //残りのbは1にするべき
    if(d > zero || a < 0 || b < 0){
        cout << -1 << endl;
        return 0;
    }
    vector<int> x(M),y(M);
    vector<int> i0,i1;
    rep(i,M){
        if(c&(1<<i)) i1.push_back(i);
        else i0.push_back(i);
    }
    rep(j,d){
        int i = i0[j];
        x[i] = y[i] = 1;
    }
    rep(j,one){
        int i = i1[j];
        if(j < a) x[i] = 1;
        else y[i] = 1;
    }
    cout << tos(x) << ' ' << tos(y) << endl;
    return 0;
}