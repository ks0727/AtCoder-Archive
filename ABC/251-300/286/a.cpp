#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,p,q,r,s;
    cin >> n >> p >> q >> r >> s;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    vector<int> pq,rs;
    b = a;
    for(int i = p-1;i<q;i++){
        pq.push_back(a[i]);
    }
    for(int i=r-1;i<s;i++){
        rs.push_back(a[i]);
    }
    for(int i=r-1;i<s;i++){
        b[i] = pq[i-(r-1)];
    }

    for(int i=p-1;i<q;i++){
        b[i] = rs[i-(p-1)];
    }
    
    rep(i,n) cout << b[i] << ' ';
    return 0;
}
int main(){
    int n,p,q,r,s;
    cin >> n >> p >> q >> r >> s;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    vector<int> pq,rs;
    b = a;
    for(int i = p-1;i<q;i++){
        pq.push_back(a[i]);
    }
    for(int i=r-1;i<s;i++){
        rs.push_back(a[i]);
    }
    for(int i=r-1;i<s;i++){
        b[i] = pq[i-(r-1)];
    }

    for(int i=p-1;i<q;i++){
        b[i] = rs[i-(p-1)];
    }
    
    rep(i,n) cout << b[i] << ' ';
    return 0;
}