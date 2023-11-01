#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string n;
    cin >> n;
    string head = n.substr(0,3);
    int size = n.size();
    if(size == 3){
        cout << head << endl;
        return 0;
    }else{
        rep(i,size-3){
            head += '0';
        }
        cout << head << endl;
        return 0;
    }
    return 0;
}