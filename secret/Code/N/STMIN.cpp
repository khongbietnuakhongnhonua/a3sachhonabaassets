#include<bits/stdc++.h>
using namespace std;
string t;
void fi(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("STMIN.inp", "r", stdin);
    freopen("STMIN.out", "w", stdout);
}

void solve(){
    unordered_map<char, int> mp;
    for (auto i : t) mp[i]=0;
    unordered_map<char, int> dp;
    int r=0, l=0,  res=t.length(), cnt=0;
    while (r<t.length()){
        dp[t[r]]++;
        if (dp[t[r]]==1 && mp.count(t[r])) ++cnt;
        while (cnt == mp.size()){
            res=min(res, r-l+1);
            dp[t[l]]--;
            if (dp[t[l]]==0 && mp.count(t[l])) --cnt;
            ++l;
            ;
        }

        ++r;

    }
    cout << res;

}

int main (){
    fi();
    getline(cin, t);
    solve();
    return 0;
}
