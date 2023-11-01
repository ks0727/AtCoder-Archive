#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> yakusuu;
    for(int i=1;i<10;i++){
        if(n % i == 0) yakusuu.push_back(i);
    }
    int size = yakusuu.size();
    vector<char> ans(n+1);
    rep(i,n+1){
        if(i == 0){
            ans[i] = yakusuu[0] + '0';
            continue;
        }
        rep(k,size){
            if(i >= n/yakusuu[k]){
                if( i % (n/yakusuu[k]) == 0 && (n/yakusuu[k]) <= i ){
                    ans[i] = yakusuu[k] + '0';
                    break;
                }
            }
            if(i < n/yakusuu[k]){
                if((n/yakusuu[k]) % i == 0 && (n/yakusuu[k]) <= i ){
                    ans[i] = yakusuu[k] + '0';
                    break;
                }
            }
            if(k == size-1 ){
                ans[i] = '-';
            }
        }
    }
    rep(i,n+1) cout << ans[i];
    return 0;
}