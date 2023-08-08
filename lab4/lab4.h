#pragma once
#include <cstddef>

int lab4();

namespace Lab4
{
	class Node
	{
		int value;
		Node* left;
		Node* right;
		bool isLeaf()
		{
			if (this->left == NULL && this->right == NULL)
				return true;
			return false;
		}
	public:
		Node(int value)
		{
			this->value = value;
			this->left = NULL;
			this->right = NULL;
		}
		friend class BSTree;
	};
	
	//Bai 1
	class BSTree
	{
		Node* root;
		void RecursiveDestroy(Node* node)
		{
			if (node != NULL)
			{
				RecursiveDestroy(node->left);
				RecursiveDestroy(node->right);
				delete(node);
			}
		}
	public:
		BSTree()
		{
			root = NULL;
		}

		~BSTree()
		{
			RecursiveDestroy(this->root);
		}
		
		bool AddNode(int value)
		{
			Node* newnode = new Node(value);
			if (this->root == NULL)
			{
				this->root = newnode;
				return true;
			}
			Node* p = root;
			while (p != NULL)
			{
				if (newnode->value == p->value)
					return false;
				if (newnode->value > p->value)
				{
					if (p->right == NULL)
					{
						p->right = newnode;
						return true;
					}
					p = p->right;
				}
				else
				{
					if (p->left == NULL)
					{
						p->left = newnode;
						return true;
					}
					p = p->left;
				}
			}
			return false;
		}
		
		bool Search(int value)
		{
			if (this->root == NULL)
				return false;
			Node* p = this->root;
			while (p != NULL)
			{
				if (value == p->value)
					return true;
					
				if (value > p->value)
					p = p->right;
				else
					p = p->left;
			}
			return false;
		}
		
		bool Delete(int value)
		{
			if (this->root == NULL)
				return false;
			
			Node* p = root;
			while (p != NULL)
			{
				if (value == p->value)
				{
					if (p->isLeaf())
						delete(p);
					else
					{
						Node* q = root;
						while (q->left != p && q->right != p)
						{
							if (value > q->value)
								q = q->right;
							else
								q = q->left;
						}
						
						Node* r = p;
						
						if (r->right == NULL)
						{
							r = r->left;
							if (q->right == p)
								q->right = r;
							if (q->left == p)
								q->left = r;
							delete(p);
						}
						else if (r->left == NULL)
						{
							r = r->right;
							if (q->right == p)
								q->right = r;
							if (q->left == p)
								q->left = r;
							delete(p);
						}
						else
						{
							Node* r_parent = r;
							r = r->right;
							while (r->left != NULL) 
							{
								r_parent = r;
								r = r->left;
							}
							
							if (r_parent == p)
								r_parent->right = r->right;
							else
								r_parent->left = r->right;
							
							p->value = r->value;
							delete(r);
						}
					}
					return true;
				}
					
				if (value > p->value)
					p = p->right;
				else
					p = p->left;
			}
			return false;
		}
		
		//Bai 2
		int Height(Node* base)
		{
			if (base == NULL || base->isLeaf())
				return 0;
			
			int leftHeight = Height(base->left);
			int rightHeight = Height(base->right);
			if (leftHeight > rightHeight)
				return (leftHeight + 1);
			return (rightHeight + 1);
		}
		
		int Height()
		{
			return Height(this->root);
		}
	};
}