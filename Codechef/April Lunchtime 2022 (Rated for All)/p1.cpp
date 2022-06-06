/*
Mario's bullet moves at X pixels per frame. He wishes to shoot a goomba standing Y pixels away from him. The goomba does not move.

Find the minimum time (in seconds) after which Mario should shoot the bullet, such that it hits the goomba after at least Z seconds from now.
*/
#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int x , y ,  z ;
        cin>>x>>y>>z;
        float time = float(y)/x ;
        if( time >= z )cout<<0<<endl;
        else cout<<z-time<<endl;
    } 
    return 0;
}