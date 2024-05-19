#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
int main(){
    int n; cin >> n;
    vector<P> a(n),b(n);
    vector<P> p(n);
    rep(i,n){
        cin >> a[i].first >> b[i].first;
        a[i].second = b[i].second = i;
    } 
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    set<P> st;
    rep(i,n-1){
        if(a[i].first == a[i+1].first){
            if(a[i].second > a[i+1].second) swap(a[i].second,a[i+1].second);
            st.insert(P(a[i].second,a[i+1].second));
        }
        if(b[i].first == b[i+1].first){
            if(b[i].second > b[i+1].second) swap(b[i].second,b[i+1].second);
            st.insert(P(b[i].second,b[i+1].second));
        }
    }
    auto f = [&](auto f,set<P> st,set<int> used)->bool{
        if(st.size() == 0) return false;
        for(auto [x,y] : st){
            if(!used.count(x) && !used.count(y)){
                st.erase(P(x,y));
                used.insert(x);
                used.insert(y);
                if(f(f,st,used)) return true;
            }
        }
        return false;
    };
    if(f(f,st,set<int>())) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}