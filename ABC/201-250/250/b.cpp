#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<string> ans(a*n);
    rep(i,n){
        rep(j,n){
            //vector<string> s(a);
            rep(ii,a){
                rep(jj,b){
                    if((i+j) % 2 == 0){ //白
                        ans[i*a+ii] += ".";
                    }else{ //黒
                        ans[i*a+ii] += "#";
                    }
                }
            }
        }
    }
    rep(i,a*n){
        cout << ans[i] << endl;
    }
    return 0;
}