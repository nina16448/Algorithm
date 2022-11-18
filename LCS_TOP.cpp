#include <bits/stdc++.h>
using namespace std;
string x, y, z;
int r[200][200][200];

int LCS(int n, int m, int l){
    if(n == 0 || m == 0 || l == 0) r[n][m][l] = 0;

    if(r[n][m][l] == -1){
        if(x[n - 1] == y[m - 1] && y[m - 1] == z[l - 1])
            r[n][m][l] = LCS(n - 1, m - 1, l - 1) + 1;
        else
            r[n][m][l] = max(max(LCS(n - 1, m, l), LCS(n, m - 1, l)), LCS(n, m, l - 1));
    }
    return r[n][m][l];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> y >> z;
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j ++)
            for(int k = 0; k < 200; k++)
                r[i][j][k] = -1;

    cout << LCS(x.size(), y.size(), z.size()) << "\n";

    return 0;
}