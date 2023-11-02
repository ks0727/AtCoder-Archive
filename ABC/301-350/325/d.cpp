#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll> > data(n);
    rep(i,n){
        cin >> data[i].first >> data[i].second;
    }
    rep(i,n){
        data[i].second = data[i].first + data[i].second;
    }
    vector<bool> printed(n);
    sort(data.begin(),data.end());
    rep(i,n){
        if(!printed[i]){
            
        }
    }
}
