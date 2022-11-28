#ifndef QUESTIONS_H
#define QUESTIONS_H

struct questions {
	char* question;
	char* options;
	char* response;
	bool mark;
	int id;
	struct questions *next;
} typedef questions;

questions*  questions_init (char* pQuestion, char* pOptions, char* pResponse, int pId){
	questions *nodo = (questions*) malloc (sizeof (questions));
	nodo->question = pQuestion;
	nodo->options = pOptions;
	nodo->response = pResponse;
	nodo->mark = false;
	nodo->id = pId;
	nodo->next = NULL;
	return nodo;
}
/*
char* getQuestion(){ return question; }
char* getOptions(){ return options; }
char* getResponse(){ return response; }
bool getMark(){ return mark; }
int getId(){ return id; }
Questions getNext(){ return next; }

void setMark(){ mark = true; }
void clearMark(){ mark = false; }
void setNext(Questions *pNext){ next = pNext; }
*/
#endif // QUESTIONS_H
