#include "project4.h"
using namespace std; 

int brute(string &T, string &P);

int brute(string &T, string &P) {
  /** Your code goes here */
  int n = T.length();
  int m = P.length();

  for(int i=0;i<=n-m;i++){
    int j=0;
    while(j<m and T[i+j]==P[j]){
      j++;  
    }
    if(j==m)return i;
  }
  return -1;
}

