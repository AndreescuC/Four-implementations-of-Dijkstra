#ifndef _STRUCTH_
#define _STRUCTH_

typedef struct node{
	int val;
	int cost;
	struct node * next;
	struct node * prev;
} nod;

#endif