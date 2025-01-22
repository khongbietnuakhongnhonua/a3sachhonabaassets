#include <bits/stdc++.h>

using namespace std;

int n, k, a[1000000];

void fixIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
}

void useFile(){
    freopen("WINNE.INP", "r", stdin);
    freopen("WINNE.OUT", "w", stdout);
}

void Load(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void Solve() {
    deque<int> dq;
    
    for (int i = 0; i < k; i++) {
        if (a[i] < 0) dq.push_back(i);
    }
    
    if (!dq.empty()) cout << a[dq.front()] << " ";
    else cout << 0 << " ";
    
    for (int i = k; i < n; i++){
        while (!dq.empty() && dq.front() <= i-k) {
            dq.pop_front();
        }
        if (a[i] < 0) dq.push_back(i);
        if (!dq.empty()) cout << a[dq.front()] << " ";
        else cout << 0 << " ";
    }
}

int main() {
    fixIO();
    //useFile();
    Load();
    Solve();
    return 0;
}
