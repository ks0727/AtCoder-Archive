#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>; 
int main(){
    int n,m;
    cin >> n >> m;
    vector<P> a(n);
    vector<P> b(m);
    rep(i,n){
        cin >> a[i].first;
        a[i].second = 0;
    }
    rep(i,m){
        cin >> b[i].first;
        b[i].second = 1;
    }
    vector<P> c;
    rep(i,n){
        c.push_back(a[i]);
    } 
    rep(i,m) c.push_back(b[i]);
    sort(c.begin(),c.end());
    vector<int> a_ans;
    vector<int> b_ans;
    rep(i,n+m){
        if(c[i].second == 0) a_ans.push_back(i+1);
        if(c[i].second == 1) b_ans.push_back(i+1);
    }
    rep(i,n) cout << a_ans[i] << ' ';
    cout << endl;
    rep(i,m) cout << b_ans[i] << ' ';
}