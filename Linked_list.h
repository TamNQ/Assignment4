#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/
 /*Define a Fresher struct*/
struct Fresher
{
    unsigned int order;
    char name[50];
    char account[20];
    float GPA;
    struct Fresher *pNext;
};
typedef struct Fresher FRESHER; /*Define type for 'struct fresher'*/

/*Define a list struct*/
struct list{
    FRESHER *pHead;
    FRESHER *pTail;
};
typedef struct list LIST; /*Define type for 'struct list'*/

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief print linked list data out to screen.
 *
 * @param *list Pass by reference pointer point to list want to print elements.
 *
 * @return linked list elements and data of node in linked list.
 */
void printList(LIST *list);

/*!
 * @brief count the number of node in linked list.
 *
 * @param *list Pass by reference pointer point to list want to count node.
 *
 * @return number of node element in linked list.
 */
int countList(LIST *list);

/*!
 * @brief Add a  new node to linked list.
 *
 * @param *list Pass by reference pointer point to list want to add node.
 * @param *ptr pointer point to struct which want to add to linked list.
 *
 * @return new linked list contain the added element.
 */
void Add_node(LIST *list, FRESHER *ptr);

/*!
 * @brief remove the node containing the ID want to delete. 
 *
 * @param *list Pass by reference pointer point to list want to delete a node.
 * @param order: ID want to delete.
 *
 * @return new linked list which does not contain deleted element.
 */
void delete_note(LIST *list, unsigned int order);

/*!
 * @brief initialize the new node with data following the Fresher struct
 *
 * @param order: ID of a person.
 * @param name[50]: name of a person.
 * @param account[20]: account of person.
 * @param GPA: GPA of person.
 *
 * @return new node which contain inserted data.
 */
FRESHER * Initialize_Freshernode(unsigned int order, char name[50], char account[20], float GPA);

/*!
 * @brief sort the linked list by name.
 *
 * @param *list Pass by reference pointer point to list want to sort element by name.
 *
 * @return new linked list has been sorted by name.
 */
void sort_Name(LIST *list);


void sort_GPA(LIST *list);

/*!
 * @brief sort the linked list by GPA.
 *
 * @param *list Pass by reference pointer point to list want to sort element by GPA.
 *
 * @return new linked list has been sorted by GPA.
 */
void sort_GPA_node(LIST *list);

/*!
 * @brief sort the linked list by name.
 *
 * @param *list Pass by reference pointer point to list want to sort element by name.
 *
 * @return new linked list has been sorted by name.
 */
void sort_Name_node(LIST *list);

void freeList(LIST *list);
#endif /* _LINKED_LIST_ */
