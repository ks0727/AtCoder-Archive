#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k,p;
    cin >> n >> k >> p;
    vector<vector<int> > all;
    rep(i,p+1){
        rep(j,p+1){
            rep(k,j+1){
                vector<int> b;
                b.push_back(i);
                b.push_back(j);
                b.push_back(k);
                all.push_back(b);
            }
        }
    }
    
}