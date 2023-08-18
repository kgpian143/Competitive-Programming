#include <iostream>
#include <vector>
using namespace std ;
int lastRoundTripTime( vector<int>& a2b, vector<int>& b2a) {
   
   int ind1 = 0 ;
   int ind2 = 0 ;
   int t1 = 0  ; 
   while( ind1 < a2b.size() && ind2 < b2a.size())
   {
       while( t1 > )
   }
}

int main() {
    // Example usage:
    vector<int> a2b = {100, 300, 600}; // Times for flights from A to B
    vector<int> b2a = {200, 400, 700}; // Times for flights from B to A

    int lt = lastRoundTripTime(a2b, b2a);
    cout << "Last Round Trip Time: " << lt << " minutes" << endl;

    return 0;
}
