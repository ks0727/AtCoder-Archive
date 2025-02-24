#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    for(int i=s.size()-2;i>=0;i--){
        if(s.substr(i,2) == "WA"){
            s[i] = 'A';
            s[i+1] = 'C';
        }
    }
    cout << s << endl;
    return 0;
}