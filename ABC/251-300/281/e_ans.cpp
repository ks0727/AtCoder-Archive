#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct DS{
    int k;
    ll sum;
    multiset<int> ls,rs;
    DS(int k = 0): k(k),sum(0){}
    void ladd(int x){
        sum += x;
        ls.insert(x);
    } 
    void lerase(multiset<int>::iterator it){
        sum -= *it;
        ls.erase(it);
    }
    void add(int x){
        ladd(x);
        if(ls.size() <= k) return;
        auto it = ls.rbegin();
        rs.insert(*it);
        lerase(it);
    }
    void erase(int x){
        if(*ls.rbegin() < x){
            rs.erase(rs.find(x));
        }else{
            lerase(ls.find(x));
            auto it = rs.begin();
            ladd(*it);
            rs.erase(it);
        }
    }
};

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    DS d;
    rep(i,m){
        d.add(a[i]);
    }
    cout << d.sum << '\n';
    rep(i,n-m){
        d.add(a[i+m]);
        d.erase(a[i]);
        cout << d.sum << '\n';
    }
    return 0;
}