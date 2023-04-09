#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data ;
    struct node *link ;
}node ;
void Add_Data (node **Head , int val){
    node *New_Node =(node *) malloc(sizeof(node)) ;
    New_Node->data = val ;
    New_Node->link = NULL ;
    if (*Head == NULL)
        *Head = New_Node ;
    else {
        New_Node->link = *Head ;
        *Head = New_Node ;
    }
}
node *Delete_Data(node *User_Linked ,node *Seconde_Linked , int Data){
    if(Seconde_Linked->link == NULL || Seconde_Linked->data == Data){
        if(Seconde_Linked->link == NULL && Seconde_Linked->data == Data){
            User_Linked->link = NULL ;
            free(Seconde_Linked) ;
            Seconde_Linked = NULL ;
            return User_Linked ;
        } else if(Seconde_Linked->link == NULL)
        return User_Linked ; 
        else {
            User_Linked->link = Seconde_Linked->link ;
            return User_Linked ;
        }
    } else 
    return Delete_Data(Seconde_Linked , Seconde_Linked->link , Data) ;
}
int main (){
    node *Head ;
    node *Start = NULL;
    int Number , n ;
    printf("How Many Number You Want :") ;
    scanf("%d",&n) ;
    for (size_t i = 1; i <= n; i++)
    {
        printf("Enter Number : ") ;
        scanf("%d",&Number) ;
        Add_Data(&Start,Number) ;
    }
    Head = Start ;
    printf("Wich Number you want To remove ?") ;
    scanf("%d",&Number) ;
    if(Head->data != Number)
    Start = Delete_Data(Start,Start,Number) ;
    else {
        Start = Start->link ;
        free(Head) ;
        Head = NULL ;
        Head = Start ;
    }
    while (Head != NULL)
    {
        printf("%d ",Head->data) ;
        Head = Head->link ;
    }
}