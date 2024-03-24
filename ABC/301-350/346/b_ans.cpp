#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int w,b;
    cin >> w >> b;
    int n = w+b;
    string s = "wbwbwwbwbwbw";
    int m = s.size();
    rep(si,m){
        int cnt = 0;
        rep(i,n){
            if(s[(si+i)%m] == 'w') cnt++;
        }
        if(cnt == w){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}