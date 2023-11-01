#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    vector<int> a(3);
    a[0] = 0;
    a[1] = 5;
    a[2] = 6;
    int value = 0;
    int diff = a[1] - a [0];
    int cnt = 0;
    while(diff > 1){
        a.insert(a.begin()+cnt+1,value);
        cnt++;
        value++;
        diff--;
    }
    rep(i,a.size()) cout << a[i] << ' ';
    cout << endl;
}