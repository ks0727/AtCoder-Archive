#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> vec(n);
    rep(i,n){
        rep(j,n){
            if(s[i][j] == 'o'){
                vec[i]++;
            }
        }
    }
    int max = 100;
    while(max > -1){
        rep(i,n){
            if(max == vec[i]) cout << i+1 << ' ';
        }
        max--;
    }
    cout << endl;
    return 0;
}