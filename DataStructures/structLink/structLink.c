#include "structLink.h"

struct Link *initLink(void)
{
	struct Link *head; //申明一个头指针
	head = (struct Link*)malloc(sizeof(struct Link));//申请空间
	if(head != NULL)//申请空间成功
	{
		//单链结操作
		head->next = head;
		head->prep = head;
		head->data = 1;
	}
	return head;
}

struct Link *insertLink(struct Link *head, int data ,int index)  //尾插法
{
	struct Link *Node =  (struct Link*)malloc(sizeof(struct Link));
	Node->data = data;
	Node->prep = NULL;
	Node->next = NULL;
	if(Node != NULL)
	{
		int i = 0;
		struct Link *temp = head;
		while(1)
		{
			if(i == index)
			{
				Node->next = temp->next;
				Node->next->prep = Node;

				temp->next = Node;
				Node->prep = temp;
				break;
			}
			else
			{
				
				if(temp->next != head)
				{
					i++;
					temp = temp->next;
				}
				else
				{
					break;
				}
			}
		}
		if(i < index)
		{
			printf("%s\n", "fail to insert!");
			free(Node);
		}
	}
	return head;
}

struct Link *deleteLink(struct Link *head, int index)
{
	struct Link *temp = head; 
	struct Link *delTemp = NULL;
	int i = 0;
	while(1)
	{
		if(i == index)
		{
			delTemp = temp;
			temp->prep->next = temp->next;
			temp->next->prep = temp->prep;
			if(i == 0)
				head = head->next;
			break;
		}
		else
		{
			
			if(temp->next != head)
			{
				i++;
				temp = temp->next;
			}
			else
			{
				break;
			}
		}
	}
	if(i < index)
	{
		printf("%s\n", "fail to delete!");
	}
	else
	{
		free(delTemp);
	}
	return head;
}