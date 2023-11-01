#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    map<int,set<int> > mp;
    rep(i,n){
        int price,c;
        cin >> price >> c;
        rep(j,c){
            int func;
            cin >> func;
            mp[price].insert(func);
        }
    }
    for(auto [price1,funcs1] : mp){
        for(auto [price2,funcs2] : mp){
            if(price2 > price1) continue;
            bool ok = true;
            for(auto func : funcs1){
                if(!funcs2.count(func)){
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;
            if(price2 < price1){
                cout << "Yes" << endl;
                return 0;
            }else{
                for(auto func : funcs1){
                    if(!funcs2.count(func)){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}