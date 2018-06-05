#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Khoi tao cau truc cua fresher va mot con tro pnext - cau truc cua node*/ 
struct Fresher{
    int order;
    char name[50];
    char account[20];
    float GPA;
    struct Fresher *pnext;
};

typedef struct Fresher FRESHER; /*Dinh nghia kieu cho struct fresher*/

/*Khoi tao list co head va tail bang null*/
struct list{
    FRESHER *pHead;
    FRESHER *pTail;
};
typedef struct list LIST; /*Dinh nghia kieu cho struct list*/

void initialize(LIST *l){
    l.pHead = NULL;
    l.pTail = NULL;
}


/*Tao ra mot Fresher node de them vao danh sach lien ket don*/
FRESHER *Initialize_Freshernode(int order, char name[50], char account[20], float GPA){
    /*Cap phat vung nho cho node Fresher*/
    FRESHER *ptr = (FRESHER*)malloc(sizeof(FRESHER));
    if(ptr = NULL){
        printf("Khong du bo nho cap phat");
        return NULL; /*Neu ptr khong duoc cap phat thi tra ve null*/
    }
    else{
        /*truyen cac gia tri vao cho node Fresher*/
        ptr->order = order;
        strcpy(ptr->name, name);
        strcpy(ptr->account, account);
        ptr->GPA = GPA;
        ptr->pnext = NULL; /*Do node moi chua lien ket voi node nao khac nen de con tro cua node tro toi NULL*/
        return ptr; /*Tra ve node Fresher vua khoi tao*/
    }
    
}

void Themvaodau(LIST *list, FRESHER *ptr){
    if(list.pHead == NULL){ /*Check dieu kien danh sach rong hay khong*/
        list.pHead = ptr;
        list.pTail = ptr; /*node dau bang node cuoi bang ptr luon*/
    }
    else{
        /*Danh sach da co phan tu*/
        ptr->pnext = list.pHead; /*Cho con tro node can them lien ket voi node dau - vi pHead dang tro vao 1 node roi*/
        list.pHead = ptr; /*Cap nhat lai pHead de cho pHead tro vao node vua them*/
    }
}

void Themvaocuoi(LIST *list, FRESHER *ptr){
    if(list.pHead == NULL){ /*Check dieu kien danh sach rong hay khong*/
        list.pHead = ptr;
        list.pTail = ptr; /*node dau bang node cuoi bang ptr luon*/
    }
    else{
        list.pTail->pnext = ptr; /*Con tro cua pTail lien ket voi node ptr*/
        list.pTail = ptr /*Cap nhat lai pTail tro vao node vua them*/
    }
}

void printList(){
    FRESHER *ptr_temp = pHead;
    while(ptr_temp !=NULL){
        printf("%d, %s, %s, %.2f\n",ptr_temp->order,ptr_temp->name, ptr_temp->account, ptr_temp->GPA);
        ptr_temp = ptr_temp->pnext;
    }
}

int main(){
    LIST list;
    initialize(list);
    Themvaocuoi(1,"Nguyen Quang Tam","TamNQ", 8);
    Themvaocuoi(2,"Nguyen Khanh", "KhanhN3", 9);
    printList();
    return 0;
}

