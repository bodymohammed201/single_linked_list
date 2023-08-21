#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------------------------------*/
 /**
   *@brief this function insert node at the begining
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Insert_Node_At_The_Begining(struct Node  **List ){
node_status retval = NODE_NOK;
struct Node  *TempNode = NULL;
TempNode = (struct Node*)malloc(sizeof (struct Node ));
if(NULL !=TempNode ){
    printf("enter the node data : ");
    scanf("%i",&TempNode->NodeData);

    if(NULL == *List){
        TempNode->NodeLink = NULL;
        *List = TempNode;
    }
    else{
        TempNode->NodeLink = *List;
        *List = TempNode;
    }
    retval = NODE_OK;
}
else{
    retval = NODE_NOK;
}
return retval;

}
/*-------------------------------------------------------------------------------*/
/**
   *@brief this function insert node at the end
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Insert_Node_At_The_End(struct Node **List ){
node_status retval = NODE_NOK;
 struct Node *TempNode = NULL;
    struct Node *LastNode = NULL;

    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode){
        printf("Enter Node Data : ");
        scanf("%i", &TempNode->NodeData);
        TempNode->NodeLink = NULL;

        /* Check if linked list is empty */
        if(NULL == *List){ /* Linked list is empty */
            *List = TempNode;
        }
        else{ /* Linked list is not empty */
            LastNode = *List;
            if(LastNode->NodeLink == NULL){
                LastNode->NodeLink =TempNode;
            }
            else{

            while(LastNode->NodeLink != NULL){
                LastNode = LastNode->NodeLink;
            }
            LastNode->NodeLink = TempNode;
        }
        }
         retval = NODE_OK;
    }
    else{
        /* Nothing */ retval = NODE_NOK;
    }
    return retval;

}
/*-------------------------------------------------------------------------------*/
 /**
   *@brief this function calculate the number of nodes in the linked list
   *@param list  is a list head points to the first node at the list
   *@retval uint32  the number of nodes at linked list
 */
 /*-------------------------------------------------------------------------------*/
uint32 Get_length(Node_list *List ){
uint32 length = 0;
Node_list *list_counter =NULL;

list_counter = List;
if(List == NULL){
    length = 0;
}
else{

    length = 1;
    while(list_counter->NodeLink != NULL){
        length++;
      list_counter=  list_counter->NodeLink;
    }
}
return length;


}
/*-------------------------------------------------------------------------------*/
 /**
   *@brief this function insert node After specific index
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Insert_Node_After(Node_list *List ){
node_status retval = NODE_NOK;
uint32 NodePosition ,listLength , NodeCounter= 1 ;
Node_list *TempNode=NULL,*NodeListCounter=NULL;
listLength=Get_length(List);
printf("enter the position you want to add node after \n");
scanf("%d",&NodePosition);
if(NodePosition>listLength){
    printf("invalid position->list has (%d)\n ",listLength);
    retval = NODE_NOK;
}
else{
     NodeListCounter= List;
     while(NodeCounter<NodePosition){
        NodeCounter++;
        NodeListCounter = NodeListCounter->NodeLink;
     }
     TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode){
        printf("Enter Node Data : ");
        scanf("%i", &TempNode->NodeData);
        TempNode->NodeLink = NodeListCounter->NodeLink;
        NodeListCounter->NodeLink= TempNode;
      retval = NODE_OK;
        }
        else{

        }


}
return retval;

}
/*-------------------------------------------------------------------------------*/
 /**
   *@brief this function delete  node fro the beginig
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Delete_Node_Nrom_Begining(Node_list **List ){
node_status retval = NODE_NOK;
if(*List ==NULL){
printf("NO Nodes to delete the list is empty\n");
 retval = NODE_NOK;
}
else{
    *List = (*List)->NodeLink;
     retval = NODE_OK;
}
return retval;
}
/*-------------------------------------------------------------------------------*/
 /**
   *@brief this function delete SPECIFIED node
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Delete_Specified_Node(Node_list **List ){

    node_status retval = NODE_NOK;
uint32 NodePosition ,listLength , NodeCounter= 1 ;
Node_list *TempNode=NULL,*NodeListCounter=NULL,*LeftNode=NULL;
listLength=Get_length(*List);
printf("enter the node position you want to delete  \n");
scanf("%d",&NodePosition);
if(NodePosition>listLength){
    printf("invalid position->list has (%d)\n ",listLength);
    retval = NODE_NOK;
}
else{
        if(NodePosition == 1){
            *List = (*List)->NodeLink;
          retval = NODE_OK;
        }
        else {
            NodeListCounter= *List;

            LeftNode= *List;
            while(NodeCounter<NodePosition){
        NodeCounter++;
        NodeListCounter = NodeListCounter->NodeLink;
     }
     NodeCounter=1;
           while(NodeCounter<NodePosition-1){
        NodeCounter++;
        LeftNode = LeftNode->NodeLink;
     }

     LeftNode->NodeLink=NodeListCounter->NodeLink;
     free(NodeListCounter);
      retval = NODE_OK;
        }
        }

return retval;
}
 /*-------------------------------------------------------------------------------*/

/**
   *@brief this function display the nodes in the list
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Display_List(Node_list *List ){
 node_status retval = NODE_NOK;
 if(List ==NULL){
    retval = NODE_NOK;
    printf("list is empty\n");
 }
 else{
Node_list *List_counter=List;
uint32 size = Get_length(List);
for(int i =1;i<=size ; i++){
    printf("element  ->(%d) \n",(uint32*)List_counter->NodeData);
    List_counter=List_counter->NodeLink;
}
retval = NODE_OK;
 }
 return retval;
}
 /*-------------------------------------------------------------------------------*/
/**
   *@brief this function reverse list
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Revarse_list(Node_list **List ){

node_status retval = NODE_NOK;
Node_list *current = *List;
Node_list *next = NULL,*prev=NULL;
if(current ==NULL){
    retval = NODE_NOK;
}
else{
while(current !=NULL){

    next = current->NodeLink;
     current->NodeLink = prev;
     prev = current;
     current = next ;
     *List = prev;

}
retval = NODE_OK;
}
return retval;
}

/*-------------------------------------------------------------------------------*/
/**
   *@brief this function to swap two elements in linked list
   *@param list  is a list head points to the first node at the list
   *@param x  is the first element i want to swap
   *@param y  is the second element i want to swap
   *@retval void
 */
 /*-------------------------------------------------------------------------------*/
void swap_two_elements(uint32 x ,uint32 y,Node_list **List ){
   if (x == y)
        return;

    // Search for x (keep track of prevX and CurrX
    struct Node *prevX = NULL, *currX = *List;
    while (currX && currX->NodeData != x) {
        prevX = currX;
        currX = currX->NodeLink;
    }

    // Search for y (keep track of prevY and CurrY
    struct Node *prevY = NULL, *currY = *List;
    while (currY && currY->NodeData != y) {
        prevY = currY;
        currY = currY->NodeLink;
    }

    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;

    // If x is not head of linked list
    if (prevX != NULL)
        prevX->NodeLink = currY;
    else // Else make y as new head
        *List = currY;

    // If y is not head of linked list
    if (prevY != NULL)
        prevY->NodeLink = currX;
    else // Else make x as new head
        *List = currX;

    // Swap next pointers
    struct Node* temp = currY->NodeLink;
    currY->NodeLink = currX->NodeLink;
    currX->NodeLink = temp;

}
 /*-------------------------------------------------------------------------------*/
/**
   *@brief this function sort the nodes in the list
   *@param list  is a list head points to the first node at the list
   *@retval void
 */
 /*-------------------------------------------------------------------------------*/
void sort_nodes(Node_list *List ){

Node_list *current;
Node_list *Next;
for( current =List ;current!=NULL;current=current->NodeLink){
    for (Next = current->NodeLink ;Next!=NULL;Next=Next->NodeLink){

         if(current->NodeData>Next->NodeData){
        uint32 temP = (current->NodeData);
        (current->NodeData) = (Next->NodeData);
            (Next->NodeData) = temP;
         }

    }

}

}



