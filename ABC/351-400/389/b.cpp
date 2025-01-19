#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    long long x;
    cin >> x;
    long long i = 1;
    long long now = 1;
    while(true){
        now *= i;
        if(now == x){
            cout << i << endl;
            return 0;
        }
        i++;
    }
    return 0;
}