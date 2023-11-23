#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct guest{
    char name[50];
    char city[50];
    int age;
    int aadharNO;
    int phoneNo;
    struct guest* next;
};  

static int total_Guest_Count=0;
static int guestExit_Gate1=0;
static int guestExit_Gate2=0;

struct guest* createGuest(char name[],char city[], int age, int aadharNO, int phoneNO){
    struct guest* newGuest = (struct guest*)malloc(sizeof(struct guest));
    strcpy(newGuest->name,name);
    strcpy(newGuest->city,city);
    newGuest->age=age;
    newGuest->aadharNO=aadharNO;
    newGuest->phoneNo=phoneNO;
    newGuest->next=NULL;
    return newGuest;
    total_Guest_Count++;
}

void enqueue(){
    
}

