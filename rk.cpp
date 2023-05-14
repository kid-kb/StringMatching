#include "project4.h"
#define ll long long
using namespace std;

int rk(string &T, string &P);

ll shift_k(ll bits, ll k) {
  return (bits<<k) | (bits >> (64-k));
}

ll hash_val(char a){
  return a;
}

ll cal_hash(string &s) {
  ll ans=0;
  ll k = s.length();
  for(int i=0;i<k;i++){
    ans ^= shift_k(hash_val(s[i]),k-i-1);
  }
  return ans;
}

ll shift_hash(ll hash, char c, ll k, char d){
  return shift_k(hash, 1) ^ shift_k(hash_val(c),k) ^ hash_val(d);
}

int rk(string &T, string &P) {
  /** Your code goes here */
  int n = T.length();
  int m = P.length();

  ll hash_val_pat = cal_hash(P);
  ll hash_val_txt;
  for(int i=0;i<=n-m;i++) {
    if(i==0) {
      string temp = T.substr(0,P.length());
      hash_val_txt = cal_hash(temp);
    } else {
      hash_val_txt = shift_hash(hash_val_txt,T[i-1],m,T[i+m-1]);
    }

    if(hash_val_pat == hash_val_txt) {
      int j=0;
      while(j<m and T[i+j]==P[j]){
        j+=1;
      }
      if(j==m){
        return i;
      }
    }
  }
  return -1;
}
