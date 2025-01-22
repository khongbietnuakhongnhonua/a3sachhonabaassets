#include <bits/stdc++.h>
#define task "WINSA2"
#define ll long long
using namespace std;

ll t, n, x, k;
vector<ll> vec;
multiset<ll> ms;

void ReadData(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> t;
}

int CuaSoTruot(){
    for (ll i = 0; i < k; i++){
        auto it = ms.lower_bound(vec[i] - x);
        if (it != ms.end() && *it <= vec[i] + x ){
            return 1;
        }
        ms.insert(vec[i]);
    }
    for (ll i = k; i < n; i++){
        ms.erase(ms.find(vec[i - k]));

        auto it = ms.lower_bound(vec[i] - x);
        if (it != ms.end() && *it <= vec[i] + x ){
            return 1;
        } else {
            ms.insert(vec[i]);
        }
    }
    return 0;
}

void Solve(){
    while (t--){
        cin >> n >> k >> x;
        vec.clear(); vec.resize(n);
        ms.clear();
        for (ll i = 0; i < n; i++){
            cin >> vec[i];
        }
        cout << CuaSoTruot() << '\n';
    }
}

int main(){
    ReadData();
    Solve();
    return 0;
}
