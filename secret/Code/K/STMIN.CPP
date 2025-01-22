#include <bits/stdc++.h>
#define ll long long
#define task "STMIN"
using namespace std;

string s;
ll riengbiet;

void ReadData(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    getline(cin, s);
}

bool MCD(ll k){
    map<char, ll> mp;
    for (ll i = 0; i < k; i++){
        mp[s[i]]++;
    }
    if (mp.size() == riengbiet) return true;

    for (ll i = k; i < s.length(); i++){
        mp[s[i-k]]--;
        if (mp[s[i-k]] == 0) mp.erase(s[i-k]);
        mp[s[i]]++;
        if (mp.size() == riengbiet) return true;
    }
    return false;
}

void Solve(){
    set<char> temp(s.begin(), s.end());
    riengbiet = temp.size();
    ll ht = riengbiet;
    while (1){
        if (MCD(ht)){
            cout << ht;
            break;
        } else {
            ht++;
        }
    }
}

int main(){
    ReadData();
    Solve();
    return 0;
}
