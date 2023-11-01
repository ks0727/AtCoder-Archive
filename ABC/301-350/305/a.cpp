#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    int s = n/5;
    int r = n%5;
    if(r > 2){
        cout << 5 * (s+1) << endl;
        return 0;
    }else{
        cout << 5 * s << endl;
        return 0;
    }
}