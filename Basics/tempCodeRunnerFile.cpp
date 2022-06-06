[n] ;
    for( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i] ;
    }
    sort( a , a+n );
    for( int i = 0 ; i < n ; i++ )
    {
        cout << a[i] << " ";
    }
    cout << endl ;
    sort( a , a+n ,cmpint);
    for( int i = 0 ; i < n ; i++ )
    {
        cout << a[i] << " ";
    }