#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> yakusuu;
    rep(i,9){
        if(n % i == 0) yakusuu.push_back(i);
    }
    vector<char> ans(n+1);
    rep(i,n){
        rep(k,yakusuu.size()){
            if((n/yakusuu[k])%i == 0){
                ans[i] = yakusuu[k];
                break;
            }
            else{
                if(k == yakusuu.size()-1){
                    ans[i] = '-';
                }
            }
        }
    }
    rep(i,n) cout << ans[i];
    return 0;
}