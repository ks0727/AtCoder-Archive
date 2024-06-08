#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int k;
    cin >> k;
    int s = k/60;
    int m = k%60;
    int h = s+21;
    auto f = [&](int x){
        string res = "";
        if(x > 9){
            res += (x/10) + '0';
            res += (x%10) + '0';
        }else{
            res += '0';
            res += x+'0';
        }
        return res;
    };
    cout << f(h) << ':' << f(m) << endl;
    return 0;
}