#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int A,B;
    cin >> N >> A >> B;
    int ans=0;
    for(int i=0;i<N+1;i++){
        int ten_thousands,thousands,hundreds,tens,ones;
        ten_thousands = (int) (i / 10000);
        thousands = (int) ((i - 10000*ten_thousands) / 1000);
        hundreds = (int) ((i - 10000*ten_thousands- 1000*thousands) / 100);
        tens = (int) ((i - 10000*ten_thousands - 1000*thousands - 100 * hundreds) / 10);
        ones = i % 10;
        int value = ten_thousands + thousands + hundreds + tens + ones;
        if(value >= A && value <= B) ans += i;
    }
    cout << ans << endl;
}