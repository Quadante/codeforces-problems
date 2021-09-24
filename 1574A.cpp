    #include <iostream>
    #include <cstring>
    #include <algorithm>
    using namespace std;
     
    void print()
    {
        
    }
     
    int main()
    {
        int T;
        cin >> T;
        while( T -- )
        {
            int n;
            cin >> n;
            for(int i = 1; i <= n; i ++ )
            {
                int cnt = 0;
                for(int j = 1; j <= i; j ++ )
                    putchar('('), cnt ++ ;
                for(int j = 1; j <= i; j ++ )
                    putchar(')'), cnt ++ ;
                
                cnt = 2 * n - cnt;
                cnt /= 2;
                while(cnt -- )
                {
                    putchar('(');
                    putchar(')');
                }
                cout << endl;
            }
        }
        return 0;
    }