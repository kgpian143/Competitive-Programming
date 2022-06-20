#include<stdio.h>
#include<stdlib.h>
struct num
{
    int ele ;
    struct num *neighbores[11] ;
};

int main()
{
    struct num arr[11] ;
    for( int i = 1 ; i < 11 ; i++ )
    {
        arr[i].neighbores[0] = &arr[i] ;
        arr[i].ele = i ;
        for( int j = 1 ; j < 10 ; j++ )arr[i].neighbores[j] = NULL ;
    }
    printf("Add relations elements : \n") ;
    int a , b ;
    scanf("%d%d",&a,&b);
    while( a != -1 && b != -1)
    {
       arr[a].neighbores[b] = &arr[b] ;
       scanf("%d%d",&a,&b);
    }
    printf("Elements in relation : \n");
    int flag1 = 0 , a1 ,  b1 ; 
    for( int i = 1 ; i < 11 ; i++ )
    {
        printf("(%d,%d) : ", i , i );
        for( int j = 1 ; j < 10 ; j++ )
        {
            if( arr[i].neighbores[j] == NULL )continue;
            if( arr[i].ele > arr[i].neighbores[j]->ele && flag1 == 0 )
            {
                 if( arr[arr[i].neighbores[j]->ele].neighbores[i] != NULL )
                 {
                    flag1++ ;
                    a1 = arr[i].ele ;
                    b1 = arr[i].neighbores[j]->ele;
                 } 
            } 
            if( flag2 != 0 )
            {
                int ind = arr[i].neighbores[j]->ele ;
                
            }
            printf("(%d,%d) , ",arr[i].ele , arr[i].neighbores[j]->ele) ;
        }
        printf("\n");
        if( flag1 == 0 )printf("The set is antisymmetric\n");
        else{
            printf("Violeting relation : %d %d \n", a1 , b1 );
            printf("Violeting relation : %d %d \n", b1 , a1 );
            printf("The set is not antisymmetric\n");
        }
    }
    return 0 ;
}