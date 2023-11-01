#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,set<int>> > data(n);
    rep(i,n){
        int p;
        cin >> p;
        data[i].first = p;
        int c;
        cin >> c;
        rep(j,c){
            int f;
            cin >> f;
            data[i].second.insert(f);
        }
    }
    for(auto product1 : data){
        for(auto product2 : data){
            if(product1 == product2) continue;
            if(product1.first > product2.first ) continue;
            bool ok = true;
            for(auto func : product2.second){
                if(!product1.second.count(func)){
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;
            if(product1.first < product2.first){
                cout << "Yes" << endl;
                return 0;
            }
            for(auto func : product1.second){
                if(!product2.second.count(func)){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}