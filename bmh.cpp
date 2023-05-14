#include "project4.h"
using namespace std; 

int bmh(string &T, string &P);

int bmh(string &T, string &P) {
  /** Your code goes here */
  int n = T.length();
  int m = P.length();

  int L[300]={-1};
  for(int i=0;i<m;i++){
    L[P[i]]=i;
  }

  int i=m-1,j=m-1;
  do{
    if(T[i]==P[j]){
      if(j==0)return i;
      else {
        i--;j--;
      }
    } else {
      int l = L[T[i]];
      i = i + m - min(j,1+l);
      j = m-1;
    }
  }while(i<n);
  
  return -1;
}

