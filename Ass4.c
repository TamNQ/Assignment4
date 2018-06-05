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

int main(void){
    LIST Fresher_list; /*Create a new list*/
    initialize(&Fresher_list);
    printf("Original list when no elements exists:---------\n");
    printList(&Fresher_list);
    printf("\nList after adding elements:---------\n");
    /*Insert data to list*/
    Add_node(&Fresher_list, Initialize_Freshernode(444,"Be","BeLV", 10));
    Add_node(&Fresher_list, Initialize_Freshernode(888,"Hien","HienBN", 7));
    Add_node(&Fresher_list, Initialize_Freshernode(111,"Tam","TamNQ", 9));
    Add_node(&Fresher_list, Initialize_Freshernode(222,"Khanh","KhanhN", 9));
    Add_node(&Fresher_list, Initialize_Freshernode(333,"Quan","QuanDH", 7));
    Add_node(&Fresher_list, Initialize_Freshernode(444,"Duy","DuyB", 6));
    Add_node(&Fresher_list, Initialize_Freshernode(555,"Tung","TungNQ", 5));
    printList(&Fresher_list);
    /*Delete ID 333*/
    delete_note(&Fresher_list, 333);
    printf("\nList after delete elements (ID 333):---------\n");
    printList(&Fresher_list);
    printf("\nList after sort GPA element:---------\n");
    /*Sort data by GPA*/
    sort_GPA_node(&Fresher_list);
    printList(&Fresher_list);
    printf("\nList after sort name element:---------\n");
    /*Sort data by name*/
    sort_Name_node(&Fresher_list);
    printList(&Fresher_list);
    freeList(&Fresher_list);
    return 0;
}
