#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    int right = n;
    int left = 0;
    int middle;
    if(n % 2 == 0) middle = n/2;
    else middle = (n+1)/2;
    rep(i,20){
        cout << "? " << middle << endl;
        char si;
        cin >> si;
        if(si == '0'){
            left = middle;
        }else{
            right = middle;
        }
        middle = (right+left)/2;
    }
    cout << "! " << left << endl;
    return 0;
}