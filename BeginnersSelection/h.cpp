#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++);
int main(){
    int N,Y;
    cin >> N >> Y;
    int ten_thousands,five_thousands,thousands;
    int price;
    bool isBrake = false;
    for(int i=0;i<N+1;i++){
        if(isBrake) break;
        for(int j=0;j<N-i+1;j++){
            if(isBrake) break;
            for(int k=0;k<N-i-j+1;k++){
                if(i+j+k == N){
                    price = i * 10000+ j * 5000 + k * 1000;
                    if(price == Y){
                        ten_thousands = i,five_thousands =j,thousands=k;
                        isBrake = true;
                        break;
                    }
                }
                else continue;
            }
        }
    }
    if(isBrake == false){
        ten_thousands = -1,five_thousands=-1,thousands=-1;
    }
    cout << ten_thousands << ' ' << five_thousands << ' ' << thousands << endl;
}