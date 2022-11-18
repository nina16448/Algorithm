#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
#define range(x) x.begin(),x.end()

int table[1000];

class event{
    public:
        int begin;
        int end;
        int val;
        event () {}
        event (int _b, int _e, int _v): begin(_b), end(_e), val(_v) {}
        bool operator < (event& b) { return end < b.end; }
        bool operator == (event& b) { return end == b.end; }
        bool operator > (event& b) { return end > b.end;}
        friend ostream& operator << (ostream& _out, event& a);
};

ostream& operator << (ostream& _out, event& a){
    cout << "b = " << a.begin << " e = " << a.end << " v = " << a.val;
    return _out;
}

int latest(vector<event>& arr, int level){
    for (int i = level - 1; i >= 0; i--){
        if (arr[i].end <= arr[level - 1].begin)
            return i;
    }
    return -1;
}

int DP(vector<event>& arr, int level){
    if(level == 1) return arr[0].val;

    table[0] = arr[0].val;

    for(int i = 1; i < level; i++){
        int incV = arr[i].val;

        if(latest(arr, i) != -1) 
            incV += table[i - 1];

        table[i] = max(incV, table[level - 1]);
    }
    return table[level - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, be, en, va;
    cin >> n;
    vector <event> arr;

    for(int i = 0; i < n; i++){
        cin >> be >> en >> va;
        arr.push_back(event(be, en, va));
    }

    sort(range(arr));
    cout << DP(arr, n) << endl;

    for(auto x: arr) cout << x << "\n";

    for(int i = 0; i < n; i++)
            cout << table[i] << " ";
    

    return 0;
}