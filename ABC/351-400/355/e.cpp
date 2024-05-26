#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using P = pair<int,int>;

ll pow(int a, int b){
    ll res = 1;
    rep(i,b) res *= a;
    return res;
}

int main(){
    int N,L,R;
    cin >> N >> L >> R;
    vector<P> ans;
    while(L != R){
        int i = 0;
        while(L % pow(2,i+1) == 0 && L+pow(2,i+1) <= R) i++;
        ans.push_back(P(i,L+pow(2,i)));
        L += pow(2,i);
    }
    sort(ans.begin(),ans.end());
    int r = 0;
    for(auto[l,r] : ans){
        cout << "? " << r << ' ' << r << endl;
        int x;
        cin >> x;
        r += x;
        r %= 100;
    }
    cout << "! " << r % 100 << endl;
    return 0;
}