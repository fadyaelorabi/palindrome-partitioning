#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkPalindrome(const string& s) {
    int len = s.size();
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - i - 1])
            return false;
    }
    return true;
}

void solve(const string& s, int start, vector<string>& cur, vector<vector<string>>& ret) {
    // Base case
    if (start == s.size()) {
        ret.push_back(cur);
        return;
    }

    for (int pi = start; pi < s.size(); ++pi) {
        string left = s.substr(start, pi - start + 1);
        if (checkPalindrome(left)) {
            cur.push_back(left);    // Do
            solve(s, pi + 1, cur, ret); // Recur
            cur.pop_back();         // Undo
        }
    }
}

vector<vector<string>> partition(const string& s) {
    vector<vector<string>> ans;
    vector<string> cur;
    solve(s, 0, cur, ans);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input = "aab";
    vector<vector<string>> result = partition(input);

    // Print the result
    for (const auto& v : result) {
        cout << "[";
        for (const string& str : v) {
            cout << str << " ";
        }
        cout << "]" << "\n";
    }

    return 0;
}
