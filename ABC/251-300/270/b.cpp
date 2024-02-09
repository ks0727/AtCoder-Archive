#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    if(x > 0){ //xが正
        if(x < y || y < 0){ //壁がxと0の間にない
            cout << x << endl;
            return 0;
        }else{//壁が間に存在
            if(z > 0){
                if(z < y){
                    cout << x << endl;
                    return 0;
                }else{
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }else{ //xが負
        if(y < x || y > 0){//壁が間にない
            cout << x << endl;
            return 0;
        }else{ //壁が間に存在
            if(z < 0){ //壁とハンマーが同符号
                if(z > y){
                    cout << x << endl;
                    return 0;
                }else{
                    cout << -1 << endl;
                    return 0;
                }
            }else{ //壁とハンマーが異符号
                cout << abs(z)+abs(x-z) << endl;
                return 0;
            }
        }
    }
    return 0;
}