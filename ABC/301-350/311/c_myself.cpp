#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int key = 1;
    vector<int> list;
    vector<bool> seen(n);
    int index;
    while(true){
        seen[key-1] = true;
        list.push_back(a[key-1]);
        key = a[key-1];
        index++;
        if(seen[key-1]) break;
    }
    int len = list.size();
    vector<int> ans;
    int value = list[len-1];
    int token = -1;
    rep(i,len){
        if(i != len-1){
            if(value == list[i]){
                token = i;
            }
        }
    }
    if(token == -1){
        cout << len << endl;
        rep(i,len){
            cout << list[i] << ' ';
        }
        cout << endl;
    }
    else{
        cout << len - (token+1) << endl;
        for(int i=token+1;i<len;i++){
            cout << list[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}