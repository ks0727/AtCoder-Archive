#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    string s;
    cin >> n >> s;
    int q;
    cin >> q;
    vector<bool> upper(n);

    rep(i,n){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            upper[i] = true;
        }
    }
    rep(i,q){
        int t,x;
        char c;
        cin >> t >> x >> c;
        x--;
        if(t == 1){
            s[x] = c;
            if(c >= 'A' && c <= 'Z'){
                upper[x] = true;
            }else{
                upper[x] = false;
            }
        }
        if(t == 2){
            upper = vector<bool>(n,false);
        }
        if(t == 3){
            upper = vector<bool>(n,true);
        }
        
    }
    rep(j,n){
            if(upper[j]){
                char c = s[j];
                if(c >= 'a' && c <='z'){
                    c -= 32;
                }
                cout << c;
                continue;
            }
            if(!upper[j]){
                char c = s[j];
                if(c >= 'A' && c <='Z'){
                    c += 32;
                }
                cout << c;
            }
        }
        cout << endl;
    return 0;
}