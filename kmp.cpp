#include "project4.h"
using namespace std;

int kmp(string &T, string &P);

void failureFunction(int F[], string &P, int m){
  F[0]=0;
  int i=1,j=0;

  while(i<m){
    if(P[i]==P[j]){
      F[i] = j+1;
      i++;
      j++;
    } else if(j>0){
      j=F[j-1];
    } else {
      F[i]=0;
      i++;
    }
  }
}

int kmp(string &T, string &P) {
  /** Your code goes here */
  int n = T.length();
  int m = P.length();
  int F[m];
  failureFunction(F, P, m); 
  int i=0,j=0;
  while(i<n){
    if(T[i]==P[j]){
      if(j==m-1) {
        return i-j;
      } else{
        i++;
        j++;
      }
    } else{
      if(j>0){
        j = F[j-1];
      } else{
        i++;
      }
    }
  }
  return -1;
}
