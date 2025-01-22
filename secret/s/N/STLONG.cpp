#include<bits/stdc++.h>
using namespace std;
string t;
void fi(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen ("STLONG.inp", "r", stdin);
    freopen("STLONG.out", "w", stdout);
}
void solve(){
    set<char> s;
    int i=0, j=0, res=-16072009;
    while (i <t.length() && j <t.length()){
            if (s.count(t[j])==0){
                s.insert(t[j]);
                res=max(res, j-i+1);
                j++;
            }
            else{
                s.erase(t[i]);
                i++;
            }
            cout << j <<' ' <<i << endl;
    }
    cout << endl;
    cout << res;
}


int main (){
    fi();
    getline(cin, t);
    solve();

}
