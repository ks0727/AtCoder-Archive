#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    string s;
    cin >> s;
    for(int i=0;i<3;i++){
        cout << s[(i+1)%3];
    }
    cout << ' ';
    for(int i=0;i<3;i++){
        cout << s[(i+2)%3];
    }
    cout << endl;
    return 0;
}