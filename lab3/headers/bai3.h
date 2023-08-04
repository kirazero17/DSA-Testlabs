#pragma once
#include <base.h>

namespace Lab3
{
	namespace Bai3
	{
		class Node
		{
			int value;
			Node* next;
		public:
			Node(int val = 0)
			{
				value = val;
				next = NULL;
			}
			friend class List;
		};
		
		class List
		{
			Node* Head;
			Node* Tail;
		public:
			List()
			{
				this->Head = NULL;
				this->Tail = NULL;
			}
			bool add(int value = 0)
			{
				Node* newnode = new Node(value);
				Node *p = Head, *q = Head->next;
				if (this->Head == NULL)
				{
					this->Head = newnode;
					this->Tail = this->Head;
					return true;
				}
				if (newnode->value <= Head->value)
				{
					newnode->next = Head;
					Head = newnode;
					return true;
				}
				if (newnode->value >= Tail->value)
				{
					Tail->next = newnode;
					Tail = newnode;
					return true;
				}
				
				while (q != Tail)
				{
					if (newnode->value <= q->value)
					{
						newnode->next = q;
						p->next = newnode;
						return true;
					}
					p = p->next;
					q = q->next;
				}
				return false;
			}
			bool reverse()
			{
				if (this->Head == NULL)
					return false;
				Node *p = this->Head, *q = this->Tail;
				
				return true;
			}
			
			void PrintAll()
			{
				Node* n = this->Head;
				while (n != NULL)
				{
					std::cout << n->value << "  ";
					n = n->next;
				}
				std::cout << std::endl;
			}
		};
	}
}