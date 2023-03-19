#include <stdio.h>
#include <stdlib.h>
//Creating A struct 
typedef struct Ranking {
    int data ;
    struct Ranking *Next ;
}Ranking ;
Ranking *Add_end(Ranking* , int) ;
Ranking *Rank (Ranking* , Ranking*) ;
int main (){
    Ranking *Head = NULL ;
    Ranking *Start = malloc(sizeof(Ranking)) ;
    int n , num;
    do{
    printf("How Many Number You Want your List : ") ;
    scanf("%d",&n) ;
    }while(n <= 0) ;
    //fill your linked List 
    for (size_t i = 1; i <=n; i++)
    {
        printf("Enter Number : ") ;
        scanf("%d",&num) ;
        Start = Add_end(Start, num) ;
        if(i == 1)
        Head = Start ;
    }
    Ranking *Ptr = Head ;
    if(Ptr->Next != NULL)
        Ptr = Rank(Ptr , Ptr->Next) ;
      while (Head != NULL)
        {
            printf("%d\n",Head->data) ;
            Head = Head->Next ;
        }
}
//Function That Will add A node AT The End Of A linked List
Ranking *Add_end(Ranking* User_Linked , int val) {
    Ranking *New = malloc(sizeof(Ranking)) ;
    New->data = val ;
    New->Next = NULL ;
    if(User_Linked == NULL)
    User_Linked = New ;
    else {
        User_Linked->Next = New ;
        User_Linked = New ;
    }
    return User_Linked ;
} 
//recursive functoin that will ordering of alinked list
Ranking *Rank (Ranking* First_Link , Ranking* Second_Link){
    int swap ;
    if(First_Link == NULL)
    return First_Link ;
    else {
        if(Second_Link == NULL)
        return Rank(First_Link->Next , First_Link->Next) ;
        else if(First_Link->data <= Second_Link->data)
            return Rank(First_Link , Second_Link->Next) ;
        else {
            swap = First_Link->data ;
            First_Link->data = Second_Link->data ;
            Second_Link->data = swap ;
            return Rank(First_Link , Second_Link->Next) ;
        }
    }
} 