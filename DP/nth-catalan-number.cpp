// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;   // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
   public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) {
        //code here
        vector<cpp_int> dp(n + 2, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n + 1; i++) {
            for (int j = 0; j <= i / 2; j++) {
                if (j != (i - j))
                    dp[i] += 2 * dp[j] * dp[i - j];
                else
                    dp[i] += dp[j] * dp[i - j];
            }
        }
        return dp[n + 1];

        cpp_int ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (((2 * i) * (2 * i - 1) * ans) / (i * (i + 1)));
        }
        return ans;
    }
};
//C(0)=1
//C(1)=C(0)*C(0)
//C(2)=C(0)*C(1) + C(1)*C(0)
//C(4)= C(0)*C(3) + C(1)*C(2) + C(2)*C(1) + C(3)*(0)
//C(5)= C(0)*C(4) + C(1)*C(3) + C(2)*C(2)

// dp[i] = (((2*i)*(2*i-1)*dp[i-1])/(i*(i+1)));
// { Driver Code Starts.

int main() {
    //taking count of testcases
    int t;
    cin >> t;
    while (t--) {
        //taking nth number
        int n;
        cin >> n;
        Solution obj;
        //calling function findCatalan function
        cout << obj.findCatalan(n) << "\n";
    }
    return 0;
}   // } Driver Code Ends