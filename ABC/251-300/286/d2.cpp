#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x;
    cin >> n >> x;
    vector<pair<int,int> > money(n);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        money[i].first = a;
        money[i].second = b;
    }
    sort(money.begin(),money.end());
    set<int> prices;
    for(auto [price,num] : money){
            for(int i=1;i<=num;i++){
                prices.insert(price*i);
                for(auto p : prices){
                    prices.insert(p+price*i);
                }
            }
    }
    if(prices.count(x)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}