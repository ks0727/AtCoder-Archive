#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<set<int> > st(n);
    rep(i,n){
        int c;
        cin >> c;
        rep(j,c){
            int a;
            cin >> a;
            st[i].insert(a);
        }
    }
    int x;
    cin >> x;
    int mn = 100;
    vector<int> ans;
    rep(i,n){
        if(st[i].count(x)){
            if((int)st[i].size() == mn){
                ans.push_back(i+1);
            }
            if(st[i].size() < mn){
                ans.clear();
                ans.push_back(i+1);
                mn = mn = st[i].size();;
            }
        }
    }
    cout << ans.size() << endl;
    rep(i,int(ans.size())) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
