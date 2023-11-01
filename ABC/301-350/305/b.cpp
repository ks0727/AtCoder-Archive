#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    map<char,int> mp;
    mp['A'] = 0;
    mp['B'] = 3;
    mp['C'] = 4;
    mp['D'] = 8;
    mp['E'] = 9;
    mp['F'] = 14;
    mp['G'] = 23;
    char p,q;
    cin >> p >> q;
    int a = mp[p];
    int b = mp[q];
    cout << abs(a - b) << endl;
    return 0; 
}