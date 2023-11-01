#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    bool upd = true;
    while(upd){
        int size = a.size();
        rep(i,size-1){
            if(a[i] - a[i+1] < -1){
                int diff = a[i+1] - a[i];
                int value = a[i];
                int cnt = 0;
                while(diff > 1){
                    a.insert(a.begin()+cnt+i+1,value+1);
                    value++;
                    cnt++;
                    diff--;
                }
                break;
            }
            if(a[i] - a[i+1] > 1){
                int diff = a[i] - a[i+1];
                int value = a[i];
                int cnt = 0;
                while(diff > 1){
                    a.insert(a.begin()+cnt+i+1,value-1);
                    value--;
                    cnt++;
                    diff--;
                }
                break;
            }
            if(i == size - 2) upd = false;
        } 
    }
    rep(i,a.size()) cout << a[i] << ' ';
    cout << endl;
    return 0;
}