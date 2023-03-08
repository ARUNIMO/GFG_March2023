/*


You have a garden with n flowers lined up in a row. The height of ith flower is ai units. You will water them for k days. In one day you can water w continuous flowers (you can do this only once in a single day). Whenever you water a flower its height increases by 1 unit. You need to maximize the height of the smallest flower all the time.

Example 1:

Input:
n=6
k=2
w=3
a[]={2,2,2,2,1,1}
Output:
2
Explanation:
Water last three flowers for first day & 
first three flowers for second day.The 
new heights will be {3,3,3,3,2,2}
Example 2:

Input:
n=2
k=5
w=1
a[]={5,8}
Output:
9
Explanation:
For the first four days water the first flower then
water the last flower once.
Your Task: 
You don't need to read input or print anything. Your task is to complete the function maximizeMinHeight() which takes the array a[], its size N, integer K, and an integer W as input parameters and returns the maximum height possible for the smallest flower.

Expected Time Complexity: O(NLogN)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n<= 105
1<=w<=n
1<=k<=105
1 <= a[i] <= 109

*/


//Code
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution{
    public:
    long long  maximizeMinHeight(int n, int k, int w, vector <int> &a) {
    	ll l = *min_element(a.begin(), a.end()) + 1, r = l + k, ans = l - 1;
    	auto works = [&](ll mnheight) {
    		ll days = 0, prefsum = 0;
    		vector<ll>dp(n + 1);
    		for (int i = 0; i < n; i++) {
    			prefsum += dp[i];
    			int height = a[i] + prefsum;
    			if (height < mnheight) {
    				int add = mnheight - height;
    				days += add;
    				prefsum += add;
    				dp[i] += add;
    				dp[min(n, i + w)] -= add;
    			}
    		}
    		return days <= k;
    	};
    
    	while ( l <= r) {
    		int guessheight = (l + r) / 2;
    		if (works(guessheight)) {
    			ans = guessheight;
    			l = guessheight + 1;
    		}
    		else
    			r = guessheight - 1;
    	}
    	return ans;
    }
};





//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
