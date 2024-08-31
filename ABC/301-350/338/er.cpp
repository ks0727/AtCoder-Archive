#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;

int main(){
    int n; cin >> n;
    vector<P> ps;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(a > b) swap(a,b);
        ps.emplace_back(a,i);
        ps.emplace_back(b,i+n);
    }
    sort(ps.begin(),ps.end());

    stack<P> q;
    rep(i,2*n){
        if(ps[i].second < n){
            q.emplace(ps[i]);
        }else{
            if(q.empty()){
                cout << "Yes" << endl;
                return 0;
            }
            if(q.top().second+n != ps[i].second){
                cout << "Yes" << endl;
                return 0;
            }else{
                q.pop();
            }
        }
    }
    cout << "No" << endl;
    return 0;
}