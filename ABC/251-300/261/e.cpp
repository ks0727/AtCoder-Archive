#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
    int n,c; cin >> n >> c;
    int x = c;
    int prev = 0;
    int now = 0;
    int first_manu = 0;
    rep(i,n){
        int t,a; cin >> t >> a;
        if(i == 0){
            now = a;
            prev = c;
            first_manu = t;
        } 
        else{
            if(t == 1) now &= a;
            else if(t == 1) now |= a;
            else now ^= a;
        }
        if(first_manu == 1){
            prev &= now;
            cout << prev << endl;
        }else if(first_manu == 2){
            prev |= now;
            cout << prev << endl;
        }else{
            prev ^= now;
            cout << prev << endl;
        }
    }
    return 0;
}