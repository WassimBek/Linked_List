#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
    int data ;
    struct nodes *link ;
}nodes ;

nodes *add_data (nodes *Head ,int data){
    nodes *Newnode = (struct nodes *) malloc(sizeof(nodes)) ;
    Newnode->data = data ;
    Newnode->link = NULL ;
    if (Head == NULL)
        Head = Newnode ;
    else {
        Head->link = Newnode ;
        Head = Newnode ;
    }
    return Head ;
}

nodes *reverse (nodes *dis ,nodes **save) {
    nodes *a ;
    if (dis->link == NULL){
        *save = dis ;
        return dis ;
        }
    else {
        a = reverse(dis->link,save) ;
        a->link = dis ;
        return dis ;
    }
}

void display (nodes *userNode) {
    if (userNode->link == NULL)
        printf("%d ",userNode->data) ;
    else {
        printf("%d ",userNode->data) ;
        display(userNode->link) ;
    }
}


int main (){
    nodes *head = NULL ;
    nodes *tmp = NULL ;
    int n ;
    printf("How Many Num in Your List ? : ") ;
    scanf("%d",&n) ;
    for (size_t i = 1; i <= n; i++)
    {
        tmp = add_data(tmp,i) ;
        if (i == 1)
            head = tmp ;
    }
    tmp = reverse(head,&head) ;
    tmp->link = NULL ;
    display(head) ;
}