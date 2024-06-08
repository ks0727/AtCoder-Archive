#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)


int pow(int a,int b){
    int res = 1;
    rep(i,b) res *= a;
    return res;
}

int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout << '#' << endl;
        return 0;
    }
    auto f = [&](auto f,int x)->vector<string>{
        if(x == 1){
            vector<string> lev1(3);
            lev1[0] = "###";
            lev1[1] = "#.#";
            lev1[2] = "###";
            return lev1;
        }
        vector<string> res(pow(3,x));
        vector<string> prev = f(f,x-1);
        rep(i,3){
            rep(ii,prev.size()){
                rep(j,3){
                    if(i==1&&j==1) res[i*prev.size()+ii] += string(prev.size(),'.');
                    else res[i*prev.size()+ii] += prev[ii];
                } 
            }
        }
        return res;
    };
    vector<string> ans = f(f,n);
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
    return 0; 
}