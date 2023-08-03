#pragma once

#include <string>
#include <iostream>
#include <base.h>

namespace Lab3
{
	namespace Bai1
	{
		class sinhvien
		{
			static int id;
			int Mssv;
			std::string Ten;
			float DTB;
			
		public:
			sinhvien(std::string ten = "", float tb = 0)
			{
				this->Mssv = id;
				this->Ten = ten;
				this->DTB = tb;
			}
			
			void show()
			{
				std::string rate;
				std::cout << this->Mssv << "\t" << this->Ten << "\t" << this->DTB << "\t";
				if (this->DTB < 5.0)
				{ rate = "Yeu";}
				if (this->DTB >= 5.0 && this->DTB < 6.5)
				{ rate = "Trung binh"; }
				if (this->DTB >= 6.5 && this->DTB < 7.0)
				{ rate = "Trung binh kha"; }
				if (this->DTB >= 7.0 && this->DTB < 8.0)
				{ rate = "Kha"; }
				if (this->DTB >= 8.0 && this->DTB < 9.0)
				{ rate = "Gioi"; }
				else
				{ rate = "Xuat sac"; }
				std::cout << rate << "\n";
			}
			
			friend class List;
		};

		int sinhvien::id = 20520001;
		
		class Node
		{
		public:
			sinhvien info;
			Node* next;
			
			Node(std::string name = "", float avg = 0)
			{
				this->info = sinhvien(name, avg);
				this->next = NULL;
			}
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
			bool push(std::string name = "", float avg = 0)
			{
				if (name == "" || name == " ")
					return false;
				Node* newnode = new Node(name, avg);
				if (this->Head == NULL)
				{
					this->Head = newnode;
					this->Tail = this->Head;
					sinhvien::id++;
					return true;
				}
				newnode->next = this->Head;
				this->Head = newnode;
				sinhvien::id++;
				return true;
			}
			bool find(std::string name)
			{
				Node* n = this->Head;
				while (n != NULL)
				{
					if (n->info.Ten == name)
						return true;
					n = n->next;
				}
				return false;
			}
			bool del(int mssv)
			{
				Node* n = this->Head;
				Node* p;
				if (n != NULL)
					if (n->info.Mssv == mssv)
					{
						this->Head = n->next;
						delete(n);
						return true;
					}
				while (n != NULL)
				{
					if (n->next->info.Mssv == mssv)
					{
						p = n->next;
						n->next = p->next;
						delete(p);
						return true;
					}
					n = n->next;
				}
				return false;
			}
			void list(float dtb)
			{
				Node* n = this->Head;
				bool check = false;
				while (n != NULL)
				{
					if (n->info.DTB == dtb)
					{
						n->info.show();
						check = true;
					}
				}
				if (check == false)
					std::cout << "Khong co hoc sinh dap ung tieu chi tim kiem !" << std::endl;
			}
			bool sort()
			{
				if (this->Head == NULL)
					return false;
				Node *p, *min = this->Head, *q = this->Head, *x;
				bool minishead = false;
				while (min->next != this->Tail)
				{
					minishead = false;
					if (min == this->Head)
						minishead = true;
					
					p = min;
					while (p != this->Tail)
					{
						if (p->next->info.DTB < min->info.DTB)
						{
							//swap p->next with min
							x = min->next;
							min->next = p->next->next;
							p->next->next = x;
							if (minishead)
							{
								q = p->next;
								p->next = min;
								min = q;
								this->Head = min;
							}
							else
							{
								q->next = p->next;
								p->next = min;
								min = q->next;
							}
						}
						p = p->next;
					}
					q = min;
					min = min->next;
				}
				if (this->Tail->info.DTB < min->info.DTB)
				{
					this->Tail->next = min;
					min->next = NULL;
					q->next = this->Tail;
					this->Tail = min;
				}
				return true;
			}
			void PrintAll()
			{
				Node* n = this->Head;
				while (n != NULL)
					n->info.show();
			}
		};
	}
}
