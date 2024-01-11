#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,m;
    cin >> h >> m;
    auto ismiss = [&](int hour,int min){
        int a = hour / 10;
        int b = hour % 10;
        int c = min / 10;
        int d = min % 10;
        if(a * 10 + c < 24 && b * 10 + d < 60) return true;
        else return false;
    };
    int ansh = -1, ansm = -1;
    while(true){
        if(ismiss(h,m)){
            ansh = h; ansm = m;
            break;
        }else{
            m++;
            if(m >= 60){
                m = 0;
                h++;
                if(h >= 24){
                    h = 0;
                }
            }
        }
    }
    cout << ansh << ' ' << ansm << endl;
    return 0;
}