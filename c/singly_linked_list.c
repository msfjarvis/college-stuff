#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct
{
	node *start;
}LL;

void insertBeginning(LL *l, int ele)
{
	node *newnode;
	newnode = (node *)malloc(sizeof(node));
	newnode->data = ele;
	newnode->next = l->start;
	l->start = newnode;
}

void insertEnd(LL *l, int ele)
{
	node *newnode,*p;
	newnode = (node *)malloc(sizeof(node));
	newnode->data = ele;
	newnode->next = NULL;
	if(l->start == NULL)
		l->start = newnode;
	else
	{
		p = l->start;
		while(p->next != NULL)
			p = p->next;
		p->next = newnode;
	}
}

void insertAtPos(LL * l, int ele, int pos)
{
	int i;
	node *newnode,*p;
	newnode = (node *)malloc(sizeof(node));
	newnode->data = ele;
	if(pos > count(l)+1)
	{
		printf("Invalid Position\n");
		return;
	}
	if(pos == 1)
	{
		newnode->next = l->start;
		l->start = newnode;
		return;
	}
	p=l->start;
	for(i = 1; i < pos-1; i++)
		p = p->next;
	newnode->next = p->next;
	p->next = newnode;
}

int deleteBeginning(LL *l)
{
	node *p;  //p must refer to node to delete
	if(l->start == NULL)
		return -1;
	p = l->start;
	l->start = l->start->next;
	return p->data;
}

int deleteEnd(LL *l)
{
	node *p,*q; // p must refer to node to delete
	if(l->start == NULL)
		return -1;
	/* if only one element */
	if(l->start->next == NULL)
	{
		p = l->start;
		l->start = NULL;
	}
	else /* take q to 2nd last node */
	{
		q = l->start;
		while(q->next->next != NULL)
			q = q->next;
		p = q->next;
		q->next = NULL;
	}
	return p->data;
}

int deletePos(LL *l,int pos)
{
	/* p must refer to the node to be deleted */
	node *p,*q;
	int i;
	if(pos == 1)
		return deleteBeginning(l);
	/* q will refer to node just before the postion to delete */
	q=l->start;
	for(i = 1; i < pos-1; i++)
		q = q->next;
	p = q->next;
	q->next = p->next;
	p->next = NULL;
	return p->data;
}

int count(LL *l)
{
	node *p;
	int c = 0;
	p = l->start;
	
	while(p!=NULL)
	{
		c++;
		p = p->next;
	}
	return c;
}

void deleteElement(LL *l, int ele)
{
	node *p,*q;
	if(l->start->data == ele)
	{
		p = l->start;
		l->start = l->start->next;
		p->next = NULL;
		return;
	}
	q = l->start;
	while(q->next != NULL)
	{
		if(ele == q->next->data)
			break;
		else
			q  = q->next;
	}
	p = q->next;
	if(p == NULL)
		printf("%d is not found\n",ele);
	else
	{
		q->next = p->next;
		p->next = NULL;
	}
}

int search(LL *l, int ele)
{
	node *p;
	p = l->start;
	while(p != NULL)
	{
		if(ele == p->data)
			return 1;
		else 
			p = p->next;
		
	}
	return 0;
}

void sort(LL *l)
{
	int t;
	node *i,*j,*p,*q;
	
	for(i = l->start; i->next != NULL; i=i->next)
	{
		for(j = l->start; j->next != NULL; j=j->next)
		{
			if(j->data > j->next->data)
			{
				t = j->data;
				j->data = j->next->data;
				j->next->data = t;
			}
		}
	}
}

void reverse(LL *l)
{
	node *p, *q, *r;
	p = l->start;
	q = NULL;
	while(p!=NULL)
	{
		r = p->next;
		p->next = q;
		q = p;
		p = r;
	}
	l->start = q;
}

void display(LL *l)
{
	node *p;
	if(l->start == NULL)
	{
		printf("list is empty\n");
		return;
	}
	p = l->start;
	while(p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
}

int main()
{
	int ch,ele,pos;
	LL l;
	l.start = NULL; 
	while(1)
	{	
		printf("\n1:  Insert Beginning\n2:  Insert End\n3:  Insert at postion\n4:  Delete Beginning\n5:  Delete End\n6:  Delete at Position\n7:  Count\n8:  Delete Element\n9:  Search\n10: Sort\n11: Reverse\n12: Display\n13: Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		if(ch == 13)
			break;
		switch(ch)
		{
			case 1:
				printf("Enter element: ");
				scanf("%d",&ele);
				insertBeginning(&l,ele);
				display(&l);
				break;
			case 2:
				printf("Enter element: ");
				scanf("%d",&ele);
				insertEnd(&l,ele);
				display(&l);
				break;
			case 3:
				printf("Enter Postion: ");
				scanf("%d",&pos);
				printf("Enter element\n");
				scanf("%d",&ele);
				insertAtPos(&l,ele,pos);
				display(&l);
				break;
			case 4:
				ele=deleteBeginning(&l);
				if(ele == -1)
					printf("Linked list empty\n");
				else
					printf("Deleted node having %d data element\n",ele);
				display(&l);
					break;
			case 5:
				ele=deleteEnd(&l);
				if(ele == -1)
					printf("Linked list empty\n");
				else
					printf("Deleted node having %d data element\n",ele);
				display(&l);
					break;
			case 6:
				printf("Enter position: ");
				scanf("%d",&pos);
				ele=deletePos(&l,pos);
				printf("Deleted node having %d data element\n",ele);
				display(&l);
				break;
			case 7:
				printf("Count = %d",count(&l));
				break;
			case 8:
				printf("Enter element to delete: ");
				scanf("%d",&ele);
				deleteElement(&l,ele);
				display(&l);
				break;
			case 9:
				printf("Enter Element to Search\n");
				scanf("%d",&ele);
				if(search(&l,ele))
					printf("Element present\n");
				else
					printf("Element not found\n");
				break;
			case 10:
				sort(&l);
				printf("Sorted Linked list\n");
				display(&l);
				break;
			case 11:
				reverse(&l);
				printf("Reversed Linked list\n");
				display(&l);
				break;
			case 12:
				display(&l);
				break;
			default:
				printf("Invalid Input\n");
				break;
		}
	}
	return 0;
}
