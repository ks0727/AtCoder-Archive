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
    sort(money.rbegin(),money.rend());
    for(auto [price,num] : money){
        int need = x / price;
        if(need < num){
            num -= need;
            x %= price;
        }else{
            x -= price * num;
            num = 0;
        }
        if(x == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}