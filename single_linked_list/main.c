#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
struct Node *ListHead = NULL;

int main()
{
    uint8 UserChoice = 0;
    uint32 ListLength = 0;
      uint32 x ,y;
    printf("-> Hello to Single Linked List \n");
    while(1){
        printf("\n");
        printf("===============================\n");
        printf("-> 1) Insert_Node_At_Beginning \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Delete_Node_At_Beginning \n");
        printf("-> 5) Delete_Node \n");
        printf("-> 6) Display_All_Nodes \n");
        printf("-> 7) Get_Length \n");
        printf("-> 8) reverse list \n");
        printf("-> 9) swap two nums \n");
        printf("-> 10) sort linked list \n");
        printf("-> 11) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);

        switch(UserChoice){
            case 1:
                Insert_Node_At_The_Begining(&ListHead);
            break;
            case 2:
                Insert_Node_At_The_End(&ListHead);
            break;
            case 3:
                Insert_Node_After(ListHead);
            break;
            case 4:
                Delete_Node_Nrom_Begining(&ListHead);
            break;
            case 5:
                Delete_Specified_Node(&ListHead);
            break;
            case 6:
                Display_List(ListHead);
            break;
            case 7:
                ListLength = Get_length(ListHead);
                printf("List Length : << %i >> Nodes\n", ListLength);
            break;
            case 8:
                Revarse_list(&ListHead);
                break;
            case 9:

                printf("enter two elements you want to swap \n");
                scanf("%d%d",&x,&y);
                swap_two_elements(x,y,&ListHead);
                break;
            case 10:
                sort_nodes(ListHead);
                break;
            case 11:
                printf("Quit from application \n");
                exit(1);
            break;
            default:
                printf("User Choice out of range !!\n");
            break;
        }
    }
    return 0;
}
