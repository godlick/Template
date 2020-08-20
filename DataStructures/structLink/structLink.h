#ifndef STRUCTLINK_H
#define STRUCTLINK_H

#include <stdio.h>
#include <stdlib.h>

struct Link
{
	int data;
	struct Link *prep;
	struct Link *next;
};

struct Link *initLink(void); //创建初始一个链表
struct Link *insertLink(struct Link *head, int data, int index);//插入一个链表的节点
struct Link *deleteLink(struct Link *head, int index); //删除一个链表的节点
#endif