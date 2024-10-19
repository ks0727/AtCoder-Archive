#include <iostream>
using namespace std;

int main(){
  long long x;
  cin >> x;
  string s = to_string(x);
  int digit = s.size();
  if(digit == 1){
    cout << s << endl;
  }
  if(digit >= 11){
    for(int i=1;i<=9;i++){
      char num = i+'0';
      string t = "";
      for(int j=0;j<digit;j++) t += num;
      long long y = stoll(t);
      if(y >= x){
        cout << t << endl;
        return 0;
      }
    }
  }
  int fd = s[0]-'0'; //初項
  for(int i=-9;i<=9;i++){
    string t = "";
    t += s[0];
    for(int j=0;j<digit;j++){
      if(j==0) continue;
      int prev = t.back() - '0';
      int now = prev + i;
      if(now >= 10 || now < 0) break;
      t += now+'0';
      if(j == digit-1){
        long long y = stoll(t);
        if(y >= x){
          cout << t << endl;
          return 0;
        }
      }
    }
  }
  if(fd == 9){
    for(int i=0;i<digit+1;i++) cout << '1';
    cout << endl;
  }else{
    fd++;
    for(int i=-9;i<=9;i++){
    string t = "";
    t += fd+'0';
      for(int j=0;j<digit;j++){
        if(j==0) continue;
        int prev = t.back() - '0';
        int now = prev + i;
        if(now >= 10 || now < 0) break;
        t += now+'0';
        if(j == digit-1){
          long long y = stoll(t);
          if(y >= x){
            cout << t << endl;
            return 0;
          }
        }
      }
    }
  }
  return 0;
}

