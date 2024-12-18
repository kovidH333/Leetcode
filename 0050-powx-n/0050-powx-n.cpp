class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 1) return 1;
        
        long long exp = n; 
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        
        double res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res *= x;
            }
            x *= x;
            exp /= 2;
        }
        
        return res;
    }
};
