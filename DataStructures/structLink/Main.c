#include "structLink.h"

int main(int argc, char const *argv[])
{
	struct Link *mlink;
	mlink = initLink();
	mlink = insertLink(mlink, 2,0);
	mlink = insertLink(mlink, 4,1);
	mlink = insertLink(mlink, 6,1);
	mlink = insertLink(mlink, 5,1);
	mlink = deleteLink(mlink,4);
	struct Link *head = mlink;
	struct Link *temp = mlink;
	do
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}while(temp != head);
	printf("\n");
	int i = 0;
	while(1)
	{
		i++;
		if(temp->next == head)
		{
			printf("%d\n", i);
			break;
		}
		temp = temp->next;
	}
	return 0;
}