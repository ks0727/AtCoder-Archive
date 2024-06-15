#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;

    vector<string> s = {"#"};
    rep(ni,n){
        int m = s.size(); int m3 = m*3;
        vector<string>  t(m3,string(m3,'.'));
        //まずK-1のカーペットで埋める
        rep(i,m3){
            rep(j,m3){
                t[i][j] = s[i%m][j%m];
            }
        }
        ///真ん中を白で埋める
        rep(i,m){
            rep(j,m){
                t[m+i][m+j] = '.';
            }
        }
        swap(s,t);
    }   
    rep(i,s.size()){
        cout << s[i] << endl;
    }
    return 0;
}