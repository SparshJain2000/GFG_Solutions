// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
    int id;       // Job Id
    int dead;     // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};

// } Driver Code Ends
// Prints minimum number of platforms reqquired

class Solution {
   public:
    vector<int> JobScheduling(Job arr[], int n) {
        // your code here
        sort(arr, arr + n, [](Job a, Job b) {
            return a.profit > b.profit;
        });
        int days = 0, prof = 0;
        unordered_map<int, bool> job_done;
        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j >= 1; j--) {
                if (!job_done[j]) {
                    days++;
                    prof += arr[i].profit;
                    job_done[j] = true;
                    break;
                }
            }
        }
        return vector<int>({days, prof});
    }
};

// { Driver Code Starts.
// Driver program to test methods
int main() {
    int t;
    //testcases
    cin >> t;

    while (t--) {
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends