#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
	public:
    	vector<string> restoreIpAddresses(string s) {
            vector<string> res;
            dfs(s, 0, 0, "", res);
            return res;
    	}
        void dfs(string &s, int begin, int step, string ip, vector<string> res) {
            if(begin == s.size() && step == 4) {
                ip.pop_back();
                res.push_back(ip);
                return;
            }

            // remaining s is too longer.
            if(s.size() - begin > (4 - step) * 3) return;
            // remaining s is too short.
            if(s.size() - begin < (4 - step)) return;
            int num = 0;
            // the longest is three digits
            for(int i= begin; i < (begin + 3); i++) {
                num = num * 10 + (s[i] - '0');
                if(num <= 255) {
                    ip += s[i];
                    dfs(s, i + 1, step + 1, ip + '.', res);
                }
                if(num == 0) break; // no 000.000.000.000
            }

        }
};
int main() {
    return 0;
}
