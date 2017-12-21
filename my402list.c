#include "my402list.h"
#include <stdio.h>

extern int  My402ListLength(My402List*);
extern int  My402ListEmpty(My402List*);

extern int  My402ListAppend(My402List*, void*);
extern int  My402ListPrepend(My402List*, void*);
extern void My402ListUnlink(My402List*, My402ListElem*);
extern void My402ListUnlinkAll(My402List*);
extern int  My402ListInsertAfter(My402List*, void*, My402ListElem*);
extern int  My402ListInsertBefore(My402List*, void*, My402ListElem*);

extern My402ListElem *My402ListFirst(My402List*);
extern My402ListElem *My402ListLast(My402List*);
extern My402ListElem *My402ListNext(My402List*, My402ListElem*);
extern My402ListElem *My402ListPrev(My402List*, My402ListElem*);

extern My402ListElem *My402ListFind(My402List*, void*);

extern int My402ListInit(My402List*);

int My402ListLength (My402List* temp)
{
	temp->num_numbers = 0;
	temp->anchor.obj = NULL;
	temp->anchor.next = NULL;
	temp->anchor.prev = NULL;
	temp->x = NULL; 
}

int My402ListLength (My402List* list)
{
	return temp->num_numbers;
}

int My402ListAppend (My402List* list, void* data)
{
	My402ListElem *newnode = (My402ListELem *) malloc (sizeof(My402ListElem));
	My402ListElem *last = My402ListLast(&list);

	if (last==NULL)
	{
		newnode->obj=*data;
		newnode->prev=list->anchor;
		newnode->next=list->anchor;
		last=newnode;
		num_number = num_number +1;
		return num_number;
		
	}
	
	else
	{	
		last->next=newnode;
		newnode->next=list->anchor;
		newnode->prev=last;
		last=newnode;
		num_number = num_number +1;
		return num_number;
	}
	return 0;

}

int My402ListPrepend (My402List* list, void* data)
{
	My402ListElem *newnode = (My402ListELem *) malloc (sizeof(My402ListElem));
	My402ListElem *first = My402ListFirst(&list);
	My402ListElem *temp;

	if (first==NULL)
	{
		newnode->obj=*data;
		newnode->prev=list->anchor;
		newnode->next=list->anchor;
		first=newnode;
		num_number = num_number +1;
		return num_number;
		
	}
	
	else
	{	
		temp = list->anchor.next;
		newnode->next=first;
		newnode->prev=list->anchor;
		first =newnode;
		num_number = num_number +1;
		return num_number;
	}
	return 0;

}

void My402ListUnlink(My402List* list, My402ListElem* list_elem )
{
	My402ListElem *prev = My402ListPrev(&list, &list_elem);
	My402ListElem *temp;
	
	if(list_elem == NULL)
		return;
	
	else if( prev==NULL)
	{
		free(list_elem);
		list->anchor.next=list->anchor;
		list->anchor.prev=list->anchor;
		num_number = num_number - 1;
		return;
	}
	else
	{
		temp=list_elem->next;
		prev->next=temp;
		temp->prev=prev;
		free(list_elem);
		num_number = num_number - 1;
		return;
	}
		
}

void My402ListUnlinkAll(My402List* list)
{
	My402ListElem *first = My402ListFirst(&list);
	My402ListElem *prev;
	if (first == NULL)
		return;
	while (first ! = list-> anchor)
	{
		prev=first;
		first = first -> next;
		free(prev);
		num_number =num_number -1;
	}
	return;
}

int My402ListInsertAfter(My402List* list, void* data, My402ListElem* list_elem)
{
	My402ListElem *next = My402ListElem(&list, &list_elem);
	
	My402ListElem *newnode = (My402ListELem *) malloc (sizeof(My402ListElem));

	newnode -> obj = *data;
	
	list_elem->next=newnode;
	newnode->next = next;
	newnode->prev = list_elem;
	
	num_number = num_number+1;
	return num_number;
}

}

int  My402ListInsertBefore(My402List* list, void* data, My402ListElem* list_elem)
{
	My402ListElem *prev = My402ListElem(&list, &list_elem);
	
	My402ListElem *newnode = (My402ListELem *) malloc (sizeof(My402ListElem));

	newnode -> obj = *data;
	
	prev->next  = newnode;
	newnode->next = list_elem;
	newnode->prev = prev;
	
	num_number = num_number+1;
	return num_number;
}



My402ListElem * My402ListFirst(My402List * list)
{
	if (list->anchor.next = list->anchor)
		return NULL;
	else 
		return list->anchor.next;
}


My402ListElem * My402ListLast(My402List * list)
{
	if (list->anchor.prev = list->anchor)
		return NULL;
	else 
		return list->anchor.prev;
}
	
My402ListElem * My402ListNext(My402List* list, My402ListElem* list_elem)
{
	if (list->anchor.next = list->anchor)
		return NULL;
 

	if ( list_elem->next == list->anchor)
		return NULL;
		
	else
		return list_elem->next;
}

My402ListElem * My402ListPrev(My402List* list, My402ListElem* list_elem)
{
	if (list->anchor.next = list->anchor)
		return NULL;
 

	if ( list_elem->prev == list->anchor)
		return NULL;
		
	else
		return list_elem->prev;
}	
		
My402ListElem * My402ListFind(My402List* list, void* data)
{
	My402ListElem * curr = list->anchor.next;
	while (curr!=NULL && curr!= list->anchor)
	{
		if( curr->obj == *data)
			return curr;
		curr=curr->next;
	}
	return 0;
}


		
			
	

	


