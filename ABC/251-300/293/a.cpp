#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int size = s.size();
    rep(i,size){
        if((i+1) % 2 == 1){
            int temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;
        }
    }
    cout << s << endl;
}