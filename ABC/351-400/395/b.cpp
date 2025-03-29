#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n)s[i] = string(n,'.');
    rep(i,n){
        int j = n-i-1;
        if(i > j || i%2 == 1) continue;
        int ci = i, cj = i;
        s[ci][cj] = '#';
        while(cj != j){
            s[ci][cj] = '#';
            cj++;
        }
        while(ci != j){
            s[ci][cj] = '#';
            ci++;
        }
        while(cj != i){
            s[ci][cj] = '#';
            cj--;
        }
        while(ci != i){
            s[ci][cj] = '#';
            ci--;
        }
    }
    rep(i,n) cout << s[i] << endl;
    return 0;
}