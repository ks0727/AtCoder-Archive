#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    string t = "";
    for(int i=0;i<3;i++){
        t += s.back();
        s.pop_back();
    }
    reverse(t.begin(),t.end());
    if(t == "san") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}