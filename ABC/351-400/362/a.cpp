#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    string s;
    cin >> s;
    if(s == "Red"){
        cout << min(g,b) << endl;
    }else if(s == "Green"){
        cout << min(r,b) << endl;
    }else{
        cout << min(r,g) << endl;
    }
    return 0;
}