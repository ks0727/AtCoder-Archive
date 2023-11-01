#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int cnt = 1;
    while(cnt > 0){
        cnt = 0;
        rep(i,h){
            rep(j,w-1){
                if(s[i][j] == 'T' && s[i][j+1] == 'T'){
                    s[i][j] = 'P';
                    s[i][j+1] = 'C';
                    cnt++;
                }
            }
        }
    }
    rep(i,h){
        rep(j,w){
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}