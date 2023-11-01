#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    int left = 1;
    int right = n;
    while(right - left > 1){
        int mid = (left + right) / 2;
        cout << "? " << mid << endl;
        int p;
        cin >> p;
        if(p == 0) left = mid;
        else right = mid;
    }
    cout << "! " << left << endl;
    return 0;
}