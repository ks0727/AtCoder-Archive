#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m,x,t,d;
    cin >> n >> m >> x >> t >> d;
    if(m >= x){
        cout << t << endl;
        return 0;
    }else{
        int s = t-x*d;
        cout << s+m*d << endl;
    }
    return 0;
}