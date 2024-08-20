#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    while(s.size() > 0){
        if('1'<=s.back() && s.back() <= '9') break;
        if(s.back() == '.'){
            s.pop_back();
            break;
        }
        s.pop_back();
    }
    cout << s << endl;
    return 0;
}