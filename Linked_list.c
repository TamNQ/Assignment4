#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Linked_list.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*Define data structure of struct Fresher*/


void initialize(LIST *list){
    list->pHead = NULL;
    list->pTail = NULL;
}
/*Print all the nodes in linked list*/
void printList(LIST *list){
    FRESHER *ptr_temp = list->pHead; /*Create a reference pointer of the pHead pointer (pHead manage the linked list)*/
    if(ptr_temp == NULL){
        printf("No data!");
    }
    else{
        while(ptr_temp !=NULL){ /*end of the linked list have NULL value pointer*/
            printf("%d, %s, %s, %.2f\n",ptr_temp->order,ptr_temp->name, ptr_temp->account, ptr_temp->GPA);
            ptr_temp = ptr_temp->pNext; /*reference to next node*/
        }
    }
}

/*Count the nodes in linked list*/
int countList(LIST *list){
    int i = 0;
    FRESHER *ptr = list->pHead; /*Create a reference pointer of the pHead pointer*/
    while(ptr!=NULL){
        i++;
        ptr = ptr->pNext;
    }
    return i; /*Return the number of node in the linked list*/
    free(ptr); 
}

void Add_node(LIST *list, FRESHER *ptr){
    if(list->pHead == NULL){ /*Check if linked list is empty*/
        list->pHead = list->pTail = ptr; /*pHead and pTail point to the same node*/
    }
    else{
        /*if list has node already*/
        list->pTail->pNext = ptr; /*pNext at the old node point to new node*/
        list->pTail = ptr; /*update pTail to point the new node*/
        ptr->pNext = NULL;
    }
}

/*Delete node of linked list*/
void delete_note(LIST *list, unsigned int order){ /*order is the ID want to delete*/
    FRESHER *ptr = list->pHead; /*Create a reference pointer of the pHead pointer*/
    FRESHER *ptr_temp = NULL; /*Create a NULL pointer to use as temporary memory*/
    if(ptr == NULL){
        return;
    }
    else{
        int key=0; /*key to find the location of node in the list want to delete*/
        int j; /*j is reference to find location in list*/
        int i = 1;
        for(j =1;j<=countList(list);j++){
            if(ptr->order == order){
                key = j;
                break;
            }
            ptr=ptr->pNext;
        }
        ptr = list->pHead; /*return ptr to pHead when location search is finished*/
        if (key == 1){ /*if postion want to delete is the first position */
            ptr_temp = list->pHead;
            list->pHead = list->pHead->pNext;
            free(ptr_temp); /*Free memory of the deleted node*/
        }
        else if(key == countList(list)){ /*If position want to delete is the last position*/
            while(ptr!=NULL && i != countList(list)-1){ /*Find the node in front of the node want to delete*/
                ptr=ptr->pNext;
                i++;
            }
            /*Split the node want to remove from list*/
            ptr_temp =ptr->pNext;
            ptr->pNext = NULL;
            list->pTail = ptr;
            free(ptr_temp); /*Free memory of the delete node*/
        }
        else if(key < 1 || key > countList(list)){ /*if position want to delete out of size of list*/
            printf("\nCannot delete!\n"); 
        }
        else{
            /*If positon want to delete is in the range of list*/
            while(ptr!=NULL&& i != key-1){ /*Find the node in front of the node want to delete*/
                ptr=ptr->pNext;
                i++;
            }
            /*Split the node want to remove from list*/
            ptr_temp = ptr->pNext;
            ptr->pNext=ptr->pNext->pNext;
            free(ptr_temp); /*Free memory of the delete node*/
        }
    }
    
}

/*Fresher node Initialization*/
FRESHER * Initialize_Freshernode(unsigned int order, char name[50], char account[20], float GPA)
{
    FRESHER *node = (FRESHER*) malloc(sizeof(FRESHER));
    if(node == NULL){ /*Checking conditions does not allocate memory*/
        printf("Can not allocate memory!!");
        return NULL; /*return NULL if not allocated*/
    }
    else{
    /*Assign values into the struct FRESHER*/
    node -> order = order;
    strcpy(node->name, name);
    strcpy(node->account, account);
    node -> GPA = GPA;
    node ->pNext = NULL; 
    return node; /*Return the node to add to linked list*/
    }
}

void sort_Name_node(LIST *list){
    FRESHER *ptr = list->pHead; /*Create a reference pointer of the pHead pointer*/
    /*Pointer variable use as a temporary storage*/
    FRESHER *temp1;
    FRESHER *temp2;
    if(list->pHead == NULL){ /*check if list = NULL*/
        return;
    }
    else{
        int i;
        int size = countList(list); /*number of node in the list*/
        for(i = 1;i<=size;i++,size--){
            while(ptr->pNext!=NULL){ /*end of the linked list have NULL value pointer*/
                if(strcmp(ptr->name,ptr->pNext->name) > 0){ /*Check if name order wrong*/
                    if(ptr == list->pHead){ /*check if change head pointer*/
                        /*swap two node for each other*/
                        list->pHead = ptr->pNext;
                        temp2 = ptr->pNext->pNext;
                        list->pHead->pNext = ptr;
                        ptr->pNext = temp2;
                        temp1 = list->pHead;
                        if(list->pHead->pNext->pNext == NULL){ /*update pTail pointer*/
                            list->pTail = list->pHead->pNext;
                        }
                    }
                    else{
                        /*swap two node for each other*/
                        temp1->pNext = ptr->pNext; 
                        temp2 = ptr->pNext->pNext;
                        temp1->pNext->pNext = ptr;
                        ptr->pNext = temp2;
                        temp1 = temp1->pNext;
                        if(ptr->pNext == NULL){ /*update pTail pointer*/
                            list->pTail = ptr;
                        }
                    }
                }
                else{
                    temp1 = ptr; /*save the value of ptr*/
                    ptr = ptr->pNext; /*jump to next node*/
                }
            }
            ptr=list->pHead; /*return to pHead to run next loop*/
        }
    } 
}

void sort_Name(LIST *list){
    FRESHER *ptr = list->pHead; /*Create a reference pointer of the pHead pointer*/
    /*temporary data variables*/
    unsigned int order_temp; 
    char name_temp[50];
    char account_temp[20];
    float GPA_temp;
    int i;
    int size=countList(list); /*size of list*/
    for (i =0;i<size;i++){
        while(ptr->pNext!=NULL){ /*end of the linked list have NULL value pointer*/
            if(strcmp(ptr->name,ptr->pNext->name) > 0){ /*Check if name order wrong*/
                /*Change data of two nodes*/
                /*Change order data*/
                order_temp = ptr->order;
                ptr->order = ptr->pNext->order;
                ptr->pNext->order = order_temp;
                /*change name*/
                strcpy(name_temp,ptr->name);
                strcpy(ptr->name, ptr->pNext->name);
                strcpy(ptr->pNext->name, name_temp);
                /*change account*/
                strcpy(account_temp, ptr->account);
                strcpy(ptr->account, ptr->pNext->account);
                strcpy(ptr->pNext->account, account_temp);
                /*change GPA*/
                GPA_temp = ptr->GPA;
                ptr->GPA = ptr->pNext->GPA;
                ptr->pNext->GPA = GPA_temp;
            }
            ptr = ptr->pNext; /*jump to next node*/
        }
        ptr= list->pHead; /*return to pHead to run next loop*/
    }
}
void sort_GPA_node(LIST *list){
    FRESHER *ptr = list->pHead; /*Create a reference pointer of the pHead pointer*/
    /*Pointer variable use as a temporary storage*/
    FRESHER *temp1;
    FRESHER *temp2;
    if(list->pHead == NULL){ /*check if list = NULL*/
        return;
    }
    else{
        int i;
        int size = countList(list); /*number of node in the list*/
        for(i = 1;i<=size;i++){
            while(ptr->pNext!=NULL){ /*end of the linked list have NULL value pointer*/
                if(ptr->GPA > ptr->pNext->GPA){ /*Check if GPA order wrong*/
                    if(ptr == list->pHead){ /*check if change head pointer*/
                        /*swap two node for each other*/
                        list->pHead = ptr->pNext;
                        temp2 = ptr->pNext->pNext;
                        list->pHead->pNext = ptr;
                        ptr->pNext = temp2;
                        temp1 = list->pHead;
                        if(list->pHead->pNext->pNext == NULL){ /*update pTail pointer*/
                            list->pTail = list->pHead->pNext;
                        }
                    }
                    else{
                        /*swap two node for each other*/
                        temp1->pNext = ptr->pNext;
                        temp2 = ptr->pNext->pNext;
                        temp1->pNext->pNext = ptr;
                        ptr->pNext = temp2;
                        temp1 = temp1->pNext;
                        if(ptr->pNext == NULL){ /*Update pTail pointer*/
                            list->pTail = ptr;
                        }
                    }
                }
                else{
                    temp1 = ptr; /*save the value of ptr*/
                    ptr = ptr->pNext; /*jump to next node*/
                }
            }
            ptr=list->pHead; /*return to pHead to run next loop*/
        }
    }
}

void sort_GPA(LIST *list){
    FRESHER *ptr = list->pHead; /*Create a reference pointer of the pHead pointer*/
    /*temporary data variables*/
    unsigned int order_temp;
    char name_temp[50];
    char account_temp[20];
    float GPA_temp;
    int i;
    int size=countList(list); /*size of list*/
    for(i = 1;i<=size;i++){
        while(ptr->pNext !=NULL){ /*end of the linked list have NULL value pointer*/
            if(ptr->GPA > ptr->pNext->GPA){ /*Check if GPA order wrong*/
                /*Change data of two nodes*/
                /*Change order data*/
                order_temp = ptr->order;
                ptr->order = ptr->pNext->order;
                ptr->pNext->order = order_temp;
                /*change name*/
                strcpy(name_temp,ptr->name);
                strcpy(ptr->name, ptr->pNext->name);
                strcpy(ptr->pNext->name, name_temp);
                /*change account*/
                strcpy(account_temp, ptr->account);
                strcpy(ptr->account, ptr->pNext->account);
                strcpy(ptr->pNext->account, account_temp);
                /*change GPA*/
                GPA_temp = ptr->GPA;
                ptr->GPA = ptr->pNext->GPA;
                ptr->pNext->GPA = GPA_temp;
            }
            ptr = ptr->pNext; /*jump to next node*/
        }
        ptr=list->pHead; /*return to pHead to run next loop*/
    }
}

void freeList(LIST *list){
    FRESHER *ptr = list->pHead;
    FRESHER *ptr_temp = NULL;
    while(ptr!=NULL){
            ptr_temp = ptr->pNext;
            free(ptr);
            ptr = ptr_temp;
    }
}

