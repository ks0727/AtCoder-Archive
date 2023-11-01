#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long Y;
    cin >>  N >> Y;
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            int c = N - (i+j); //ここがポイント！3重ループはTLEするから定数Cを固定して考えることで２重ループに落とし込むことができる
            if(c >= 0){
                if(10000 * i + 5000*j + 1000*c == Y){
                    printf("%d %d %d\n",i,j,c);
                    return 0;
                }
            }
        }
    }
    printf("-1 -1 -1\n");
}