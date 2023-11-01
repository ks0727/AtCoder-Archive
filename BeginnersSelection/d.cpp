#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    int X;
    cin >> X;
    int ans = 0;
    for(int i=0;i<A+1;i++){
        for(int j=0;j<B+1;j++){
            for(int k=0;k<C+1;k++){
                if(500*i+100*j+50*k == X) ans++;
            }
        }
    }    
    cout << ans << endl;
}
//この問題はA,B,C<50の条件があるから、最大でも50*50*50のオーダーでできるから愚直にやればいい