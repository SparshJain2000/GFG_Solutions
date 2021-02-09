// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

int tour(petrolPump[], int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        cout << tour(p, n) << endl;
    }
}
// } Driver Code Ends

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[], int n) {
    int first = 0, second = 0;
    int res = 0;
    int d = 0;
    while (first < n) {
        if (d <= 0) second = first, res = 0;
        bool done = true;
        while ((second + 1) % n != first) {
            // cout << first << "," << second << " : " << p[second].petrol << " " << res << " " << p[second].distance << endl;
            if (p[second].petrol + res < p[second].distance) {
                done = false;
                break;
            }
            res += p[second].petrol - p[second].distance;
            second = (second + 1) % n;
            d++;
        }
        if (done && p[second].petrol + res >= p[second].distance) return first;

        res += p[first].distance - p[first].petrol;
        first++;
        d--;
    }
    return -1;
}
/*
4
4 6 7 4
6 5 3 5
*/