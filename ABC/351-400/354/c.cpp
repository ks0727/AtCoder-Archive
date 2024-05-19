#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = tuple<int,int,int>;

int main(){
    int n;
    cin >> n;
    vector<P> cards(n);
    rep(i,n){
        int a,c;
        cin >> a >> c;
        cards[i] = P(a,c,i+1);
    }
    sort(cards.begin(),cards.end());
    vector<int> ans;
    int mn = 1001001001;
    for(int i=n-1;i>=0;i--){
        auto [a,c,idx] = cards[i];
        if(c > mn){
            continue;
        }else{
            mn = c;
            ans.push_back(idx);
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for(int x: ans) cout << x << ' '; cout << endl;
    return 0;
}