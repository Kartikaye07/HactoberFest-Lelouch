// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    int equilibriumPoint(long long a[], int n) {
        // Your code here
        if(n==1){
            return 1;
        }
        long long int rs=0;
        for(int i=0;i<n;i++){
            rs+=a[i];
        }
        long long int ls=0;
        for(int i=0;i+1<n;i++){
            rs-=a[i];
            if(ls==rs){
                return i+1;
            }
            ls+=a[i];
        }
        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
