#pragma once
#include <base.h>

namespace Lab3
{
	namespace Bai2n3
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
			
			~List()
			{
				Node *p = this->Head;
				while (p != NULL)
				{
					Node* q = p;
					p = p->next;
					delete(q);
				}
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
			
			//Bai 2
			bool add(int value = 0)
			{
				Node* newnode = new Node(value);
				
				//tao node dau tien
				if (this->Head == NULL)
				{
					this->Head = newnode;
					this->Tail = this->Head;
					return true;
				}
				
				//neu chi co 1 node, chi co the them vao dau hoac duoi
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
				
				//chi co the toi doan nay neu mang da co it nhat 2 phan tu (p = head va q = tail)
				Node *p = Head, *q = Head->next; // khong phai lo p va q = NULL
				do
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
				while (q != Tail);
				
				//truong hop du phong - khong the them phan tu (khong nen xay ra !)
				return false;
			}
			bool sort()
			{
				if (this->Head == NULL)
					return false;
				Node *p, *min = this->Head;
				while (min != this->Tail)
				{
					p = min;
					while (p != NULL)
					{
						if (p->value < min->value)
						{
							DSA::swap((p->value), (min->value));
						}
						p = p->next;
					}
					min = min->next;
				}
				return true;
			}
			
			//Bai 3
			bool Reverse()
			{
				if (this->Head == NULL)
					return false; //khong sap xep danh sach rong

				Node *p = this->Head, *q = p->next, *x = q->next;
				while (x != NULL)
				{
					q->next = p;
					p = q;
					q = x;
					x = x->next;
				}
				if (q != NULL) // q = NULL chi xay ra khi danh sach co 1 phan tu duy nhat
				{
					q->next = p;
					this->Tail = this->Head;
					this->Tail->next = NULL;
					this->Head = q;
				}
				return true;
			}
		};
	}
}