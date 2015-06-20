// Copyright 2015 © Ayush Garg , B.E. (Hons.) (in COE) , NSIT, Delhi
// All or any part of the code should not be copied without consent
// Since I strictly oppose plagiarism.


#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define rep(i,x,y) for(i=x;i<y;i++)
#define rrep(i,x,y) for(i=x;i>y;i--)
#define ll long long
#define llu unsigned long long
#define pri(x) printf("%d",x)
#define prc(c) printf("%c",c)
#define prs(s) printf("%s",s)
#define sci(x) scanf("%d",&x)
#define scc(c) scanf("%c",&c)
#define scs(s) scanf("%s",&s)
#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)
#define debug(x) cerr<<#x<<" "<<x<<endl
#define debugsp(x) cerr<<#x<<" "<<x<<" "

using namespace std;

// Implementation of Kadane's algorithm for 1D array. The function returns the
// maximum sum and stores starting and ending indexes of the maximum sum subarray
// at addresses pointed by start and finish pointers respectively.
int kadane(int* arr, int* start, int* finish, int n)
{
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i;

    // Just some initial value to check for all negative values case
    *finish = -1;

    // local variable
    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

     // There is at-least one non-negative number
    if (*finish != -1)
        return maxSum;

    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];
    *start = *finish = 0;

    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,t,n,start,finish,sum;
    int a[1001];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        sum=kadane(a,&start,&finish,n);
        cout<<start<<" "<<finish<<" "<<sum<<endl;
    }
    return 0;
}
