#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include "Platform_Types.h"
typedef struct Node{
void * NodeData;
struct Node *NodeLink;
} Node_list;

typedef enum {
NODE_NOK,
NODE_OK
} node_status;
/*-------------------------------------------------------------------------------*/
 /**
   *@brief this function insert node at the begining
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Insert_Node_At_The_Begining(Node_list **List );
/*-------------------------------------------------------------------------------*/
 /**
   *@brief this function insert node at the end
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Insert_Node_At_The_End(Node_list **List );
/*-------------------------------------------------------------------------------*/
 /**
   *@brief this function calculate the number of nodes in the linked list
   *@param list  is a list head points to the first node at the list
   *@retval uint32  the number of nodes at linked list
 */
 /*-------------------------------------------------------------------------------*/
uint32 Get_length(Node_list *List );
/*-------------------------------------------------------------------------------*/
 /**
   *@brief this function insert node After specific index
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Insert_Node_After(Node_list *List );
/*-------------------------------------------------------------------------------*/
 /**
   *@brief this function delete  node fro the beginig
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Delete_Node_Nrom_Begining(Node_list **List );
/*-------------------------------------------------------------------------------*/
 /**
   *@brief this function delete SPECIFIED node
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Delete_Specified_Node(Node_list **List );
 /*-------------------------------------------------------------------------------*/

/**
   *@brief this function display all nodes in the list
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Display_List(Node_list *List );
 /*-------------------------------------------------------------------------------*/
/**
   *@brief this function reverse the list
   *@param list  is a list head points to the first node at the list
   *@retval node_status is a return status 1 or 0
 */
 /*-------------------------------------------------------------------------------*/
node_status Revarse_list(Node_list **List );
/*-------------------------------------------------------------------------------*/
/**
   *@brief this function to swap two elements in linked list
   *@param list  is a list head points to the first node at the list
   *@param x  is the first element i want to swap
   *@param y  is the second element i want to swap
   *@retval void
 */
 /*-------------------------------------------------------------------------------*/
void swap_two_elements (uint32 x ,uint32 y,Node_list **List );
/*-------------------------------------------------------------------------------*/
/**
   *@brief this function sort the nodes in the list
   *@param list  is a list head points to the first node at the list
   *@retval void
 */
 /*-------------------------------------------------------------------------------*/
void sort_nodes(Node_list *List );
#endif // _LINKED_LIST_
