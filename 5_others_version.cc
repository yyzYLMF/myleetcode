class Solution {
    public:
        string longestPalindrome(string s) {
            if (s.size() == 0) return s;
            int i, n = 2 * s.size() + 1;
            int f[n], mid, right, pos, len;
            char str[n];
            for (i = 0, str[n - 1] = '#'; i < s.size(); i++){
                str[i * 2] = '#';
                str[i * 2 + 1] = s[i];
            }
            f[0] = 0;
            mid = right = 0;
            pos = 0; len = 1;
            for (i = 1; i < n; i++){
                if (right > i){
                    f[i] = min(f[mid - i + mid], right - i);
                }else f[i] = 0;
                while (i - f[i] - 1 >= 0 && i + f[i] + 1 < n && str[i - f[i] - 1] == str[i + f[i] + 1]) f[i]++;
                if (len < f[i]){
                    len = f[i];
                    pos = (i - f[i]) / 2;
                }
                if (right < i + f[i]){
                    mid = i;
                    right = i + f[i];
                }
            }
            return s.substr(pos, len);
        }
    };