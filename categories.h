#ifndef CATEGORIES_H
#define CATEGORIES_H

#include "questions.h"

struct categories {
	char* name;
	bool markL;
	int idL;
	int countN;
	struct questions *first;
} typedef categories;

categories* categories_init (char* pName, int pIdL){
	categories *lista = (categories*) malloc (sizeof(categories));
	lista->name = pName;
	lista->markL = false;
	lista->countN = 1;
	lista->idL = pIdL;
	lista->first = NULL;
	return lista;
}

void insert(categories *l, char* pQuestion, char* pOptions, char* pResponse){
	questions *temp = questions_init(pQuestion, pOptions, pResponse, l->countN);
	l->countN++;
	if (l->first == NULL){
		l->first = temp;
	} else {
		questions *aux = l->first->next;
		while (aux->next != NULL){
			aux = aux->next;
		}
		aux->next = temp;
	}
} 
/*
bool search(int pId){
	Questions *temp = first;
	while (temp != nullptr){
		if (temp->getId() == pId){
			return true;
		} else {
			temp = temp->getFirst();
		}
	}
	return false;
}

char* getName(){ return name; }
bool getMarkL(){ return markL; }
int getcountN(){ return countN; }
int getIdL(){ return idL; }
Categories getFirst(){ return first; }

void setMarkL(){ this->markL = true; }
void clearMarkL(){ this->mark = false; }
void setFirst(Categories *pFirst){ this->first = pFirst; }
*/
#endif // CATEGORIES_H
