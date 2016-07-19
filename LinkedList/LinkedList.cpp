#include "LinkedList.h"

LinkedList::LinkedList()
{
	list_size = 0;
	head = NULL;
	tail = NULL;
}


LinkedList::~LinkedList()
{
	do
	{
		if (!RemoveFront())
		{
			break;
		}
	} while (1);
}

LinkedList::Link_Node* LinkedList::NewNode(const void* item, const size_t& item_size)
{
	Link_Node* new_node = new Link_Node;
	
	if (new_node != NULL)
	{
		new_node->pdata = new char[item_size];

		if (new_node->pdata != NULL)
		{ 
			memcpy(new_node->pdata, item, item_size);
			new_node->next = NULL;
		}
		else
		{
			delete new_node;
			new_node = NULL;
		}
	}

	return new_node;
}

void LinkedList::ReleaseNode(LinkedList::Link_Node* Node)
{
	if (Node != NULL)
	{
		if (Node->pdata != NULL)
		{
			delete[] Node->pdata;
		}
		delete Node;
	}
}

bool LinkedList::AddFront(const void* item, const size_t& item_size)
{
	bool ret = false;

	Link_Node* new_node = NewNode(item, item_size);

	if (new_node != NULL)
	{
		if (head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next = head;
			head = new_node;
		}

		ret = true;
		list_size++;
	}

	return ret;
}


bool LinkedList::AddBack(const void* item, const size_t& item_size)
{
	bool ret = false;

	Link_Node* new_node = NewNode(item, item_size);
	
	if (new_node != NULL)
	{
		if (head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{	
			tail->next = new_node;
			tail = new_node;
		}

		ret = true;
		list_size++;
	}

	return true;
}

size_t LinkedList::Size()
{
	return list_size;
}

bool LinkedList::Remove(const LinkedList::Link_Node* node)
{
	bool ret = false;

	if (head == NULL || tail == NULL)
	{
		//false
	}
	else
	{
		if (head == node) //if the node being removed is the first node
		{
			Link_Node* t = head;

			if (head == tail)
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				head = head->next;
			}

			list_size--;
			ReleaseNode(t);

			ret = true;
		}
		else
		{
			Link_Node* previous_node = head;
			Link_Node* current_node = head->next;

			while (current_node != NULL)
			{
				if (current_node == node)
				{
					previous_node->next = current_node->next;

					if (current_node == tail)
					{
						tail = previous_node;
					}

					list_size--;
					ReleaseNode(current_node);

					ret = true;
					break;
				}

				previous_node = current_node;
				current_node = current_node->next;
			}
		}
	}

	return ret;
}

bool LinkedList::RemoveFront()
{
	if (head == NULL)
	{
		return false;
	}
	else
	{
		return Remove(head);
	}
}

bool LinkedList::RemoveBack()
{
	if (tail == NULL)
	{
		return false;
	}
	else
	{
		return Remove(tail);
	}
}

bool LinkedList::Front(void* item, const size_t& item_size)
{
	bool ret = false;

	if (item != NULL)
	{
		if (head != NULL)
		{
			memcpy(item, head->pdata, item_size);
			ret = true;
		}
	}

	return ret;
}

bool LinkedList::Back(void* item, const size_t& item_size)
{
	bool ret = false;

	if (item != NULL)
	{
		if (tail != NULL)
		{
			memcpy(item, tail->pdata, item_size);
			ret = true;
		}
	}

	return ret;
}
