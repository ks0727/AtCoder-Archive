#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    int g,h,i,j,k,l;
    cin >> g >> h >> i >> j >> k >> l;
    if(g >= d || h >= e || i >= f){
        cout << "No" << endl;
        return 0;
    } 
    if(j <= a || k <= b || l <= c){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}