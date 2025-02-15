#include <iostream>
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  if(a == b){
    cout << "EQUAL" << endl;
    return 0;
  }
  if(a.size() > b.size()){
    cout << "GREATER" << endl;
    return 0;
  }else if(a.size() < b.size()){
    cout << "LESS" << endl;
    return 0;
  }
  for(int i=0;i<a.size();i++){
    int na = a[i]-'0';
    int nb = b[i]-'0';
    if(na > nb){
      cout << "GREATER" << endl;
      return 0;
    }else if(na < nb){
      cout << "LESS" << endl;
      return 0;
    }
  }
  return 0;
}

