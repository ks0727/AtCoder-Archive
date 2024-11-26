#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    vector<int> a = {1,2,3};
    auto it = a.begin();
    cout << *prev(it,100) << endl;
    return 0;
}