#include <bits/stdc++.h>

using namespace std;

string s;
int demRieng;
set<char> slxh;

void fixIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void useFile(){
    freopen("STMIN.INP", "r", stdin);
    freopen("STMIN.OUT", "w", stdout);
}

void Load(){
    cin >> s;
    for (char c : s) {
        slxh.insert(c);
    }
    demRieng = slxh.size();
}

void Solve() {
    vector<int> dem(256, 0); 
    int start = 0, minL = s.size() + 1, demHientai = 0;
    int k = demRieng; 
    
    for (int i = 0; i < k; ++i) {
        char c = s[i];
        if (dem[c] == 0) demHientai++;
        dem[c]++;
    }

    if (demHientai == demRieng) minL = k;

    for (int end = k; end < s.size(); ++end){
        char new_c = s[end];
        dem[new_c]++;
        if (dem[new_c] == 1) demHientai++;
        char old_c = s[start];
        dem[old_c]--;
        if (dem[old_c] == 0) demHientai--;
        start++;
        if (demHientai == demRieng) minL = min(minL, end - start + 1);
    }

    if (minL > s.size()) cout << 0;
    else cout << minL;
}

int main() {
    fixIO();
    //useFile();
    Load();
    Solve();
    return 0;
}