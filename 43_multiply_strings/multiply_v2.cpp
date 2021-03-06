#include <iostream>
#include <string>
#include <vector>


using namespace std;

// `num1[i] * num2[j]` will be placed at indices `[i + j`, `i + j + 1]`

class Solution {
    public:
        string multiply(string num1, string num2) {
            int m = num1.size(), n = num2.size();
            vector<int> pos(m + n, 0);
            string res = "";


            for(int i = m - 1; i >= 0; i--) {
                for(int j = n - 1; j >= 0; j--) {
                    int mul = (num1[i] - '0') * (num2[j] - '0');
                    int p1 = i + j, p2 = i + j + 1;
                    int sum = mul + pos[p2];

                    pos[p1] += (sum / 10);
                    pos[p2] = (sum % 10);
                }
            }

            for(int p : pos) {
                if(!(res.size() == 0 && p == 0)) {
                    res.append(to_string(p));
                }
            }

            return (res.size() == 0)? "0" : res;
        }
};
