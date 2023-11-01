#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    vector<vector<int> > p;  
    rep(i,n){
        cin >> c[i];
        rep(j,c[i]){
            cin >> p[i][j];
        }
    }
    vector<int> mustRead;
    rep(i,p[0].size()) mustRead.push_back(p[0][i]);
    while(true){
        rep(i,mustRead.size()){
            int iter = mustRead[i]+1;
            rep(j,p[iter].size()){
                if()
            }
        }
    }
}