#include<bits/stdc++.h>
using namespace std;
string t, st;
void fi(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("STSP.inp", "r", stdin);
    freopen("STSP.out", "w", stdout);
}

void solve(){
    if (st.length() < t.length()) {
        cout <<-1;
        return ;
    }
    unordered_map<char, int> mp;
    for (auto i : t) mp[i]++;
    unordered_map<char, int> dp;
    int l=0,  res=2e8, cnt=0, x=-1;
    for (int r=0; r<st.length(); r++){
        if (mp.find(st[r])!=mp.end()) {
            dp[st[r]]++;
            if (dp[st[r]]==mp[st[r]] ) ++cnt;
        }
        while (cnt==mp.size()){
            if (res > r-l+1){
                res=r-l+1;
                x=l;
            }
            if (mp.find(st[l]) != mp.end()){
                if (dp[st[l]]==mp[st[l]])--cnt;
                dp[st[l]]--;
            }
            ++l;

        }
    }
    if (x==-1) cout << -1;
    else cout << st.substr(x, res);

}

int main (){
    fi();
    getline(cin, st);
    getline(cin, t);
    solve();
    return 0;
}
