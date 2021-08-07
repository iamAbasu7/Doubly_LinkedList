// C program for the all operations in
// the Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
        int info;
        struct node *prev, *next;
};
struct node* start = NULL;

//prototypes

void traverse();
void insertAtFront();
void insertAtEnd();
void insertAtPosition();
void deleteFirst();
void deleteEnd();
void deletePosition();
void reverseList();
void printBack();




int main()
{
        int choice;
        while (1) {

                        printf("\n\t1 To see list\n");
                printf("\t2 For insertion at starting\n");
                printf("\t3 For insertion at end\n");
                printf("\t4 For insertion at any position\n");
                printf("\t5 For deletion of first element\n");
                printf("\t6 For deletion of last element\n");
                printf("\t7 For deletion of element at any position\n");
                printf("\t8 To reverse the list\n");
                printf("\t9 To Display from Back\n");
                printf("\t10 To exit\n");
                printf("\nEnter Choice :\n");
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                        traverse();
                        break;
                case 2:
                        insertAtFront();
                        break;
                case 3:
                        insertAtEnd();
                        break;
                case 4:
                        insertAtPosition();
                        break;
                case 5:
                        deleteFirst();
                        break;
                case 6:
                        deleteEnd();
                        break;
                case 7:
                        deletePosition();
                        break;

                case 8:
                        reverseList();
                        break;
                        case 9:
                                    printBack();
                                    break;
                        case 10:
                        exit(1);
                        break;
                default:
                        printf("Incorrect Choice\n");
                }
        }
        return 0;
}




// Function to traverse the linked list
void traverse()
{
        struct node* temp;
        // List is empty
        if (start == NULL)
        {
               printf("\nList is empty\n");

        }
        // Else print the DLL
        else
        {

                temp = start;
                while (temp != NULL) {
                        printf(" %d ->",temp->info);

                        temp = temp->next;
                }
        }
}

// Function to insert at the front
// of the linked list
void insertAtFront()
{
        int data;
        struct node* temp;
//      temp=start;
        temp = (struct node*)malloc(sizeof(struct node));// temp=*prev<-NULL->next*
          //NULL<-temp->NULL
        printf("\nEnter number to be inserted: ");
        scanf("%d", &data); //taking data from client
        temp->info = data;  // temp=NULL<-data->NULL
        temp->prev = NULL;  // NULL <- data //temp= NULL<-data->next*

        // Pointer of temp will be
        // assigned to start
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                start->prev=temp;
                temp->next=start;
                start=temp;
        }
        traverse();
        main();

}
// Function to insert at the end of
// the linked list
void insertAtEnd()
{
        int data;
        struct node *temp, *trav;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->prev = NULL;
        temp->next = NULL;
        printf("\nEnter number to be inserted: ");
        scanf("%d", &data);
        temp->info = data;
        temp->next = NULL;
        trav = start;

        // If start is NULL
        if (start == NULL) {
                printf("The Linklist is empty so your data will be inserted in the First Position\n");
                start = temp;
                traverse();
        }

        // Changes Links
        else {
                while (trav->next != NULL)
                        trav = trav->next;
                temp->prev = trav;
                trav->next = temp;
                traverse();
        }
}

// Function to insert at any specified
// position in the linked list
void insertAtPosition()
{
        int pos,i=1;
        int length=0;

        struct node *ptr1,*newp;
        ptr1=start;
        newp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the position you want to insert: ");
        scanf("%d",&pos);

        while(ptr1!=NULL)
        {
                ptr1=ptr1->next;
                length++;
        }

        if(start==NULL)
        {
                if(pos==0)
                {
                        printf("Invalid Input\n");
                        main();
                }
                 if(pos==1)
                 {
                         insertAtFront();
                 }


                printf("The Linklist is empty, So your data will be inserted in th first position\n");
                insertAtFront();
        }

        else if(pos<=0)
        {
                printf("Invalid Position\n");
                main();
        }
        else if(pos==1)
        {
                insertAtFront();
        }
        else if(pos==length+1)
        {
                insertAtEnd();
        }
        else if(pos>=length+2)
        {
                printf("We have ony %d nodes in the List, please choose between 1 and %d to insert",length,length+1);
        }
        else
        {
                ptr1=start;
                printf("Enter the data :");
                scanf("%d",&newp->info);


                while(i<pos-1)
                {
                        ptr1=ptr1->next;
                        i++;
                }
                newp->prev=ptr1;
                newp->next=ptr1->next;
                ptr1->next=newp;
                newp->next->prev=newp;

                traverse();
        //      main();
        }

}
// Function to delete from the front
// of the linked list
void deleteFirst()
{
        struct node* temp;
        if (start == NULL)
        {
                traverse();
        }
        else {
                temp = start;
                start = start->next;
                if (start != NULL)
                        start->prev = NULL;
                free(temp);

                traverse();
         }
}

// Function to delete from the end
// of the linked list

void deleteEnd()
{
         struct node* temp;
    if (start == NULL)
    {
        traverse();

    }
    else
        {
        temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    if (start->next == NULL)
        start = NULL;
    else {
        temp->prev->next = NULL;
        free(temp);
    }
    traverse();
}
}
        // Function to delete from any specified
// position from the linked list
void deletePosition()
{
        int pos, i = 1;
        struct node *temp, *position;
        temp = start;
        int count=0;
        while(temp != NULL)
        {
                temp=temp->next;
                count++;
        }
        // If DLL is empty
        if (start == NULL)
                printf("\nList is empty\n");

        // Otherwise
        else {
                // Position to be deleted
                printf("\nEnter position : ");
                scanf("%d", &pos);
                position=malloc(sizeof(struct node));
                temp=start;
                if(pos>count)
                {
                        printf("We have only %d nodes in the list, please choose between 1 to %d\n",count,count);
                        main();
                }
                else if(pos==0)
                {
                        printf("Invalid Input\n");
                }
                else if(pos ==1)
                {
                        deleteFirst();
                }
                else{

                // Traverse till position
                while (i < pos - 1) {
                        temp = temp->next;
                        i++;
                }
                // Change Links
                position = temp->next;
                if (position->next != NULL)
                        position->next->prev = temp;
                temp->next = position->next;

                // Free memory
                free(position);
                traverse();
        }
}}
void reverseList()
{
        struct node *temp = NULL;
     struct node *current = start;

     /* swap next and prev for all nodes of
       doubly linked list */
     while (current !=  NULL)
     {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;
       current = current->prev;
     }

     /* Before changing head, check for the cases like empty
        list and list with only one node */
     if(temp != NULL )
        start = temp->prev;

        traverse();
}

void printBack()
{
        struct node *tail=start;

        if(start==NULL)
        {
                printf("List is empty\n");
                main();
        }
        while(tail->next != NULL)
        {
                tail=tail->next;
        }
        while(tail!=start)
        {
                printf(" %d ",tail->info);
                tail=tail->prev;
        }
        printf(" %d ",tail->info);
}
