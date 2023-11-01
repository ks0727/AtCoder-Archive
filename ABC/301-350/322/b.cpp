#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    if(t.substr(0,n) == s && t.substr(m-n,n) == s){
        cout << 0 << endl;
        return 0;
    }
    else if(t.substr(0,n) == s){
        cout << 1 << endl;
        return 0;
    }
    else if(t.substr(m-n,n) == s){
        cout << 2 << endl;
        return 0;
    }
    else{
        cout << 3 << endl;
    }
    return 0;
}