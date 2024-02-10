#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int q;
    cin >> q;
    vector<int> arr;
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            arr.push_back(x);
        }
        else if(type == 2){
            int k;
            cin >> k;
            int index = arr.size() - k;
            cout << arr[index] << endl;
        }
    }
    return 0;
}