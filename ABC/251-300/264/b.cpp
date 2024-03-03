#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int r,c;
    cin >> r >> c;
    r--; c--;
    if(r > 7){
        int minus = r-7;
        r -= minus*2;
    }
    if(c > 7){
        int minus = c-7;
        c -= minus*2;
    }
    if(r%2==0){
        if(c >= r){
            cout << "black" << endl;
            return 0;
        }else{
            if(c%2 == 0){
                cout << "black" << endl;
                return 0;
            }else{
                cout << "white" << endl;
                return 0;
            }
        }
    }else{
        if(c >= r){
            cout << "white" << endl;
            return 0;
        }else{
            if(c%2==0){
                cout << "black" << endl;
                return 0;
            }else{
                cout << "white" << endl;
                return 0;
            }
        }
    }
    return 0;
}