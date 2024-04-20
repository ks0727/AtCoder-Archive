#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    string t = s.substr(3,3);
    int num = stoi(t);
    if(num>=1 && num <= 349 && num != 316){
        cout << "Yes" << endl;
    }else cout << "No" << endl;
    return 0;
}