#ifndef LIST_H
#define LIST_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
	char *name;
	int year;
	struct list *next;
} list_t;

#endif /* LIST_H */
