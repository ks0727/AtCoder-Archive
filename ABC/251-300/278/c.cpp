#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    map<int,set<int> > mp;
    rep(qi,q){
        int t,a,b;
        cin >> t >> a >> b;
        a--; b--;
        if(t == 1){
            mp[a].insert(b);
        }
        else if(t==2){
            mp[a].erase(b);
        }
        else if(t == 3){
            if(mp[a].count(b) && mp[b].count(a)) cout << "Yes" << endl; 
            else cout << "No" << endl;
        }
    }
    return 0;
}