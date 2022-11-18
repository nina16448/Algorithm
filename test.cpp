#define NDEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,y;
    cin >> x >> y;
    assert(x*y>INT_MAX);
    cout << x*y << endl;
    return 0;
}