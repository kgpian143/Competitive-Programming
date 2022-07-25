#include<bits/stdc++.h>
using namespace std ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef unsigned long long ull; 
typedef long double ld; 
typedef vector<pii> vpii; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
const int N = 2e5 + 5; 
// int board[8][8] ; 
bool filled( int board[8][8] )
{
    for( int i = 0 ; i < 8 ; i++ )
    {
        for( int j = 0 ; j < 8 ; j++ )
        {
             if( board[i][j] == 0 )return false  ;
        }
    }
    return true  ;
}
void print(int sol[8][8])
{
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}
bool tour(int board[8][8]  , int row , int col , int cnt   )
{
    // cout<<1<<endl;
    print(board);
    cout<<endl;
    if( cnt == 62 )return true ;
    vpii mvm = { { 1 , 2 } , { 2 , 1 } , { -1 , 2 } , { 2 , -1} , { -1 , -2} , { -2 , -1 } , { -2 , 1} , { 1 , -2}} ;
    for( auto it : mvm ) 
    {
         int i = it.first ; 
         int j = it.second ; 
         if( (row + i >= 0) && (row + i < 8) && (col + j >= 0) && (col + j < 8) && (board[row + i][col + j ] == 0) )
         {
            board[row + i][col + j ] = cnt ; 
            if(tour( board , row + i , col + j , cnt + 1 ))return true ;
            board[row + i][col + j ] = 0 ; 
         }
    }
    return false ;
}
#define N 8
 
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[], int yMove[]);
 
/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N
            && sol[x][y] == -1);
}
 
/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}
 
/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
int solveKT()
{
    int sol[N][N];
 
    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
 
    /* xMove[] and yMove[] define next move of Knight.
    xMove[] is for next value of x coordinate
    yMove[] is for next value of y coordinate */
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
    // Since the Knight is initially at the first block
    sol[0][0] = 0;
 
    /* Start from 0,0 and explore all tours using
    solveKTUtil() */
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "Solution does not exist";
        return 0;
    }
    else
        printSolution(sol);
 
    return 1;
}
 
/* A recursive utility function to solve Knight Tour
problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[8], int yMove[8])
{
    printSolution(sol);
    cout<<endl;
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;
 
    /* Try all next moves from
    the current coordinate x, y */
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove)
                == 1)
                return 1;
            else
                
               // backtracking
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int board[8][8] ;
        memset( board , 0 , sizeof(board)) ;
        board[0][0] = 1 ;
        // if(tour(board , 0 , 0 , 2 ) )print(board) ;
        // print(board);
        solveKT() ;
    }
    return 0;
}