#include "project4.h"
#include<iostream>
#include<vector>
using namespace std; 
#define ll long long

int bitap(string &T, string &P);

int bitap(string &T, string &P) {
  /** Your code goes here */
  int m = P.length();
  vector<ll>mp(256,~(ll)0);

  for(int i=0;i<P.length();i++){
    mp[P[i]]= mp[P[i]]& (~((ll)1<<i));
  }
  
  ll mask_txt = ~(ll)0;
  for(int i=0;i<T.length();i++){
    mask_txt <<= 1;
    mask_txt |= mp[T[i]];
    if((mask_txt & (1<<(m-1)))==0)return i-m+1;
  }
  return -1;
}