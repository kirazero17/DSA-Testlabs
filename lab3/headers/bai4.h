#pragma once


namespace Lab3
{
	namespace Bai4
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
			friend class Stack;
		};
		
		class Stack
		{
			Node* Head;
			Node* Tail;
		public:
			Stack()
			{
				this->Head = NULL;
				this->Tail = NULL;
			}
			
			~Stack()
			{
				Node *p = this->Head;
				while (p != NULL)
				{
					Node* q = p;
					p = p->next;
					delete(q);
				}
			}
			
			bool push(int value)
			{
				if (value == -2147483648)
					return false;
				Node* newnode = new Node(value);
				if (this->Head == NULL)
				{
					this->Head = newnode;
					this->Tail = this->Head;
					return true;
				}
				newnode->next = this->Head;
				this->Head = newnode;
				return true;
			}
			
			int pop()
			{
				if (Head == NULL)
					return -2147483648;
				int v = this->Head->value;
				Node* p = this->Head;
				this->Head = p->next;
				delete(p);
				return v;
			}
		};
	}
}