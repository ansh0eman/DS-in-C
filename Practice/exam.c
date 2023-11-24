#include <stdio.h>
#include <stdlib.h>

int Beds;
int Stents;

struct patient{
    char name[10];
    int patient_number;
    int stents_required;
    struct patient* next;
};

struct WLQ{
    struct patient arr[10];
    int front, rear;
};

struct patient* createNode(char name[], int pno, int sreq){
    struct patient* p =(struct patient*)malloc(sizeof(struct patient));
    int i=0;
    for(i=0; name[i]!='\0'; i++){
        p->name[i] = name[i];
    }
    p->name[i]='\0';
    p->patient_number= pno;
    p->stents_required =sreq;
    p->next = NULL;
    return p;
}

void initWLQ(struct WLQ** wq){
    (*wq)->front =(*wq)->rear =-1;
}

void addWLQ(struct WLQ** wq, struct patient* p){
    if((*wq)->front ==-1){
        (*wq)->front = (*wq)->rear =0;
    }else{
        (*wq)->rear = (*wq)->rear +1;
    }
    (*wq)->arr[(*wq)->rear]= *p;
}

void InsertEnd(struct patient** ap, struct patient* p, struct WLQ** wq){
    struct patient* ptr = *ap;
    if(*ap ==NULL){
        *ap =p;
        Beds--;
        Stents = Stents - p->stents_required;
        free(ptr);
        return;
    }
    if(Beds>0 && Stents >= p->stents_required){
        while(ptr->next !=NULL){
            ptr = ptr->next;
        }
        ptr->next = p;
        Beds--;
        Stents = Stents - p->stents_required;
    }else{
        printf("\nNot possible to accomodate.\n");
        addWLQ(wq,p);
    }
}

void Display(struct patient** ap, struct WLQ** wq){
    printf("Admitted patients:\n");
    struct patient* ptr = *ap;
    while(ptr!=NULL){
        printf("Name: %s, Patient_number: %d, Stents_required: %d\n",ptr->name, ptr->patient_number, ptr->stents_required);
        ptr=ptr->next;
    }
    printf("\n");
    printf("Waiting List Queue: \n");
    int i =(*wq)->front;
    while(i != (*wq)->rear){
        printf("\nName: %s, patient number: %d, Stents required: %d\n",(*wq)->arr[i].name,(*wq)->arr[i].patient_number,(*wq)->arr[i].stents_required);
        i++;
    }
}

void DeleteFront(struct patient** ap, struct WLQ** wq){
    struct patient* temp = *ap;
    (*ap)=(*ap)->next;
    Beds++;
    Stents = Stents + temp->stents_required;
    free(temp);

    int i = (*wq)->front;
    if(Beds > 0 && Stents > 0){
        while(i!= (*wq)->rear){
            if((*wq)->arr[i].stents_required <= Stents){
                InsertEnd(ap, &((*wq)->arr[i]) ,wq);
                (*wq)->front++;
                break;
            }
            i++;
        }
    }
}

void Resources(){
    printf("\n Available resources:\nBeds: %d, Stents: %d\n",Beds,Stents);
}

int main(){
    printf("Enter the total number of beds and stents available at the beginning: ");
    scanf("%d %d",&Beds,&Stents);
    int inp=0;
    int pno,sreq;
    char name[10];
    struct patient* ap = NULL;
    struct WLQ* wq = (struct WLQ*)malloc(sizeof(struct WLQ));
    initWLQ(&wq);

    while(inp != -1){
        printf("\n1.Admit Patient, 2.Display Admitted and Waiting, 3.Discharge a patient, -1.Exit: ");
        scanf("%d", &inp);
        switch(inp){
            case 1:
                printf("Enter details of the patient:\nName,pno,stents req:\n");
                scanf("%s %d %d", name, &pno, &sreq);
                struct patient* p = createNode(name,pno,sreq);
                InsertEnd(&ap, p, &wq);
                Resources();
                break;
            case 2: 
                Display(&ap,&wq);
                Resources();
                break;
            case 3:
                DeleteFront(&ap,&wq);
                Resources();
                break;
            case -1:
                free(wq);
                return 0;
        }
    }
}
