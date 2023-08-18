#include<bits/stdc++.h>
using namespace std ;

string solution(vector<string> A, int N) {
    vector<int> inDegree(26, 0);
    vector<int> outDegree(26, 0);
    vector<bool> equal(26, false);

    string result;
    for (int i = 0; i < N; ++i) {
        inDegree[A[i][0] - 'a'] += 1 ;
        outDegree[A[i][1] - 'a' ] += 1 ; 
        if(A[i][0] == A[i][1] ) equal[A[i][1] - 'a'] = true ;
        int cnt1 = 0 , cnt2  = 0  ;
        if( i == 0 )
        {
            result += '1' ;
            continue;
        }
        for( int i = 0 ; i < 26 ; i++)
        {
            if( inDegree[i] == outDegree[i] ){
                if(equal[i] && outDegree[i] == 1 ){
                    cnt1 = -1 ;
                    break;
                }
                else continue;
            }
            if( abs( inDegree[i] - outDegree[i] ) > 1 ) {
                cnt1 = -1 ;
                break;
            }
            if ( inDegree[i] - outDegree[i] == 1 )cnt1++ ;
            else if( outDegree[i] - inDegree[i] == 1 )cnt2++ ; 
        }
        if( (cnt1 == 1 && cnt2 == 1 ) || ( cnt1 == 0 && cnt2 == 0 )  )result +='1' ;
        else result += '0' ;
    }

    return result;
}

int main() {
    vector<string> A1 = {"he", "ll", "lo", "el"};
    int N1 = A1.size();
    string result1 = solution(A1, N1);
    cout << result1 << endl;  // Output: "1001"

     vector<string> A2 = {"ab", "ba", "bq"};
    int N2 = A2.size();
    string result2 = solution(A2, N2);
    cout << result2 << endl;  // Output: "111"

    // char* A3[] = {"ee", "ea", "eg"};
    // int N3 = sizeof(A3) / sizeof(A3[0]);
    // string result3 = solution(A3, N3);
    // cout << result3 << endl;  // Output: "110"

    return 0;
}
