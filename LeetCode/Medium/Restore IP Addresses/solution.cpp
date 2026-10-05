class Solution {
public:
    vector<string> ans;
    bool isValid(string part) {
        if (part.empty())
            return false;
        if (part.size() > 1 && part[0] == '0')
            return false;
        if (part.size() > 3)
            return false;
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }
    void solve(string &s, int index, int parts, string current) {
        if (index == s.size() && parts == 4) {
            current.pop_back();
            ans.push_back(current);
            return;
        }
        if (index == s.size() || parts == 4)
            return;

        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size())
                break;
            string part = s.substr(index, len);
            if (isValid(part)) {
                solve(s,
                      index + len,
                      parts + 1,
                      current + part + ".");
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)
            return {};
        solve(s, 0, 0, "");
        return ans;
    }
};