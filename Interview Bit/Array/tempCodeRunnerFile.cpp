 vector<int> ans;
    int l = -1, r = -1, max_sum = INT_MIN;
    int curr_sum = 0;
    int st = 0;
    int n = A.size();
    int cnt = 0 ;
    for( int i = 0 ; i < n ; i++)
    {
        if( A[i] >= 0 )
        {
            cnt++ ;
            break;
        }
    }
    if( cnt == 0 )return ans ;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
        {
            if (curr_sum == max_sum && A[i-1] >= 0)
            {
                if (i - st > r - l)
                {
                    l = st;
                    r = i - 1;
                }
            }
            if (curr_sum > max_sum)
            {
                l = st;
                r = i-1;
                max_sum = curr_sum;
            }
            curr_sum = 0;
        }
        else
        {
            if (curr_sum == 0 && A[i-1] != 0)
            {
                st = i;
            }
            curr_sum += A[i];
        }
    }
    if (curr_sum == max_sum)
    {
        if (n - 1 - st > r - l)
        {
            l = st;
            r = n - 1 ;
        }
    }
    if (curr_sum > max_sum )
    {
        l = st;
        r = n-1;
        max_sum = curr_sum;
    }
    for (int j = l; j <= r; j++)
        ans.push_back(A[j]);
    return ans;