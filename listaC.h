#ifndef LISTAC_H
#define LISTAC_H

#include "categories.h"

struct listaC {
	int countLC;
	struct categories *head;
} typedef listaC;

listaC *listaC_init (){
	listaC *listaN = (listaC*) malloc (sizeof(listaC));
	listaN->countLC = 1;
	listaN->head = NULL;
	return listaN;
}

void insertCategory(listaC *n, char* pName){
	categories *temp1 = categories_init(pName, n->countLC);
	n->countLC++;
	if (n->head == NULL){
		n->head = temp1;
	} else {
		categories *aux1 = n->head->first;
		while (aux1->first != NULL) {
			aux1 = aux1->first;
		}
		aux1->first = temp1;
	}
} 
/*
int getCountLC(){ return countLC; }
Questions getHead(){ return head; }

void setHead(Questions *pFirst){ this->head = pHead; }
*/
#endif // LISTAC_H
