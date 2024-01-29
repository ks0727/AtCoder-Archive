#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> x(2*n+2);
    for(int i =1;i<=(n);i++){
        int ai;
        cin >> ai;
        x[2*i] = ai;
        x[2*i+1] = ai;
    }
    vector<int> ans(2*n+2,-1);
    ans[1] = 0;
    auto f = [&](auto f,int n,int d)->int{
        if(ans[n] != -1) return ans[n]+d;
        else{
            ans[n] =  f(f,x[n],d+1);
            return ans[n];
        }
    }; 
    for(int i=1;i<=(2*n+1);i++){
        ans[i] = f(f,i,0);
        cout << ans[i] << '\n';
    }
    return 0;
}