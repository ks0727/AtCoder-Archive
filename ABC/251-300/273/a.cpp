#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    int now =1;
    for(int i=n;i>=1;i--){
        now *= i;
    }
    cout << now << endl;
    return 0;
}