#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int passed = 0;
    bool done = false;
    rep(i,n){
        if(!done){
            if(s[i] == 'o') passed++;
            if(passed >= k){
                done = true;
            }
        }else{
            s[i] = 'x';
        }
    }
    cout << s << endl;
    return 0;
}