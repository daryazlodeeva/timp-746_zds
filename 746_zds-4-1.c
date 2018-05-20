#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct _node {
int value;
struct _node *next;
struct _node *prev;
} node;

typedef struct  _stek{
size_t size;
node *head;
node *tail;
} stek;

stek *createstek(){
stek *tmp = (stek*) malloc(sizeof(stek));
tmp->size=0;
tmp->head=NULL;
tmp->tail=NULL;
return tmp;
}


bool empty(stek *list){
if (list->tail=NULL)return true; else return false;
}

void pushfr(stek *list,int val1){
node *tmp=(node*)malloc(sizeof(node));
tmp->prev=NULL;
tmp->value=val1;
if(list->head){list->head->prev=tmp; tmp->next=list->head;}
list->head=tmp;
if (list->tail==NULL){list->tail=tmp;}
list->size++;
}

void show(stek *list){
node *tmp=list->head;
while(tmp){
        printf("%d",tmp->value);
        if(tmp->next) printf(" ");
tmp=tmp->next;
}
printf("\n");
}

void popfr(stek *list)
{node *prev;
prev=list->head;
list->head=list->head->next;
if (list->head){list->head->prev=NULL;}
if(prev==list->tail){list->tail=NULL;}
free(prev);
list->size--;
}

void deletestek(stek *list){
node *tmp;
while(list->head){
        tmp=list->head->next;
        free(list->head);
        list->head=tmp;
}free(list);
list=NULL;
}



void main(){
stek *sd=createstek();
int k,n,i;
scanf("%d",&n);
for (int i=0;i<n;i++)
{
scanf("%d",&k);
pushfr(sd,k);
}
show(sd);
for (int i=0;i<n-1;i++)
{
popfr(sd);
show(sd);
}
deletestek(sd);
show(sd);
}
