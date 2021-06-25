    #include<iostream>
    using namespace std;
    int main()
    {
        long long t;
        cin>>t;
        while(t--)
        {
            long long n;
            cin>>n;
            long long arr[n];
            for(long long i = 0; i<n; i++)
            {
                cin>>arr[i];
            }
            long long count = 0;
            for(long long i =0; i<n-1; i++)
            {
                for(long long j = arr[i]-i-2; j<n; j+= arr[i])
                {
                    if(j>i && arr[i]*arr[j] == i+j+2)
                    count ++;
                }
            }
            cout<<count<<endl;
        }
        return 0;
    }