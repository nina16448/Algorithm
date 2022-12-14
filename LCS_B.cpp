#include<bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
  string x = "gxtxayb"; 
  string y = "abgtab"; 
  string z = "gyaytahjb"; 
  int n = x.length(), m = y.length(), l = z.length();
  
  int dp[n][m][l];
  memset(dp, 0, sizeof dp);
  for (int i=0; i<n; i++){ 
    for (int j=0; j<m; j++){ 
      for (int k=0; k<l; k++){
        if (x[i] == y[j] && x[i] == z[k])
          dp[i][j][k] = ((i>0 && j>0 && k>0) ? dp[i-1][j-1][k-1] : 0) + 1;
        else
          dp[i][j][k] = max({i>0 ? dp[i-1][j][k] : 0, j>0 ? dp[i][j-1][k] : 0, k>0 ? dp[i][j][k-1] : 0}); 
      } 
    } 
  } 
  cout<<dp[n-1][m-1][l-1];
  return 0; 
}
