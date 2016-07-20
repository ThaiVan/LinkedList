/*
Author: dgtvan
Email: dgtvan@gmail.com
Date: 19/7/2016
*/

#pragma once

#include <string>

#ifndef __LINKED_LIST__H__
#define __LINKED_LIST__H__

class LinkedList
{
public:
	struct Link_Node
	{
		void* pdata;
		Link_Node* next;
	};

private:
	size_t list_size;
	Link_Node* head;
	Link_Node* tail;
	Link_Node* current;

	Link_Node* NewNode(const void* item, const size_t& item_size);
	void ReleaseNode(LinkedList::Link_Node* Node);

	bool Remove(const LinkedList::Link_Node* node);

public:
	LinkedList();
	virtual ~LinkedList();

	bool AddFront(const void* item, const size_t& item_size);
	bool AddBack(const void* item, const size_t& item_size);

	size_t Size();

	bool RemoveFront();
	bool RemoveBack();
	
	bool Front(void* item, const size_t& item_size);
	bool Back(void* item, const size_t& item_size);

	void BeginInterate();
	bool Next(void* item, const size_t& item_size);
};

#endif