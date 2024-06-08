#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    int now = 0;
    rep(qi,q){
        int t,x;
        cin >> t >> x;
        x--;
        if(t == 1){
            now = (now+x+1)%n;
        }else{
            cout << s[(x-now+n)%n] << endl;
        }
    }
    return 0;
}