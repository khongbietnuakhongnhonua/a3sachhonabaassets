#include <bits/stdc++.h>
#define ll long long
#define task "STSP"
using namespace std;

string s, s2, day;
ll riengbiet;

void ReadData(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    getline(cin, s);
    getline(cin, s2);
}

bool MCD(ll k){
    map<char, ll> st, st2;
    for (char c : s2) st[c]++;
    day = "";
    for (ll i = 0; i < k; i++){
        if (st.count(s[i])){
            st2[s[i]]++;
        }
        day += s[i];
        if (st == st2) return true;
    }

    for (ll i = k; i < s.length(); i++){
        if (st.count(s[i])){
            st2[s[i]]++;
        }
        day.erase(day.begin());
        day += s[i];
        if (st.count(s[i])){
            st2[s[i]]++;
        }
        if (st == st2) return true;
    }
    return false;
}

void Solve(){
    riengbiet = s2.size();
    ll ht = riengbiet;
    while (1){
        if (MCD(ht)){
            cout << day;
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
