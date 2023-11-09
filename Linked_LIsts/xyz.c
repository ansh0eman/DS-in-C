#include <stdio.h>
#include <Stdlib.h>

struct dlist{
    int data;
    struct dlist *rlink;
    struct  dlist *llink;
};

int main(){
    struct dlist *header, b, *last;
    header = calloc(1,sizeof(b));
    header->data =-999;
    header->llink =header->rlink = header;
    last = header;

    insertfront(&header,&last,18);
    insertfront(&header,&last,19);
    insertrear(&header,&last, 20);
    insertrear(&header,&last, 21);
    display(header);
    convert(&header,&last);
    display(header);
}

void insertfront(struct dlist *head, struct dlist *last, int d){
    
}
