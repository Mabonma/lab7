#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

template <class T>
class BinariTree
{
private:

	//ready
	void AddElement(T neweleminfo, BinariTree<T> *Root)
	{
		if (info == neweleminfo)
		{
			cout << "This element is in binari tree" << endl;
		}
		else if (info > neweleminfo)
		{
			if (right == NULL)
			{
				BinariTree<T>* temp = new BinariTree<T>(neweleminfo);
				temp->root = root;
				right = temp;
			}
			else
			{
				right->AddElement(neweleminfo, Root);
			}
		}
		else
		{
			if (left == NULL)
			{
				BinariTree<T>* temp = new BinariTree<T>(neweleminfo);
				temp->root = root;
				left = temp;
			}
			else
			{
				left->AddElement(neweleminfo, Root);
			}
		}
	}

	//ready
	void DeleteAfter()
	{
		if (left != NULL)
		{
			if (left->left != NULL || left->right != NULL)
			{
				left->DeleteAfter();
			}
			delete left;
		}

		if (right != NULL)
		{
			if (right->left != NULL || right->right != NULL)
			{
				right->DeleteAfter();
			}
			delete right;
		}
	}

	/*BinariTree(T Info, BinariTree<T> Root)
	{
		info = Info;
		root = Root;
	}*/

public:
	T info;
	BinariTree<T>* left = NULL, * right = NULL, * root = NULL;

	BinariTree() { }

	BinariTree(T Info)
	{
		info = Info;
		root = this;
	}

	//ready
	void AddElem(T neweleminfo)
	{
		if (info == neweleminfo)
		{
			cout << "This element is in binari tree" << endl;
		}
		else if (neweleminfo > info)
		{
			if (right == NULL)
			{
				BinariTree<T>* temp = new BinariTree<T>(neweleminfo);
				temp->root = root;
				right = temp;
			}
			else
			{
				right->AddElement(neweleminfo, root);
			}
		}
		else
		{
			if (left == NULL)
			{
				BinariTree<T>* temp = new BinariTree<T>(neweleminfo);
				temp->root = root;
				left = temp;
			}
			else
			{
				left->AddElement(neweleminfo, root);
			}
		}
	}

	//ready
	void DeleteElem(T deleleminfo)
	{ 
		if (deleleminfo > info)
		{
			if (right == NULL)
			{
				cout << "There is no element like that" << endl;
			}
			else if (right->info == deleleminfo)
			{
				right->DeleteAfter();

				delete right;
			}
			else
			{
				right->DeleteElem(deleleminfo);
			}
		}
		else if (deleleminfo < info)
		{
			if (left == NULL)
			{
				cout << "There is no element like that" << endl;
			}
			else if (left->info == deleleminfo)
			{
				left->DeleteAfter();

				delete left;
			}
			else
			{
				left->DeleteElem(deleleminfo);
			}
		}
		else
		{
			DeleteAfter();

			delete this;
		}
	}
	
	//ready
	void Print()
	{
		cout << info << endl;

		if (left != NULL)
		{
			left->Print();
		}

		if (right != NULL)
		{
			right->Print();
		}
	}

	/*ostream operator<<(ostream &os)
	{
		string output = "";
		queue<BinariTree<T>> q;
		q.push(this);
		while (q.empty())
		{
			BinariTree<T> temp = q.pop();
			if (temp.left != NULL)
			{
				q.push(temp.left);
			}
			if (temp.right != NULL)
			{
				q.push(temp.right);
			}
			output += temp.info + " ";
		}

		return os << output;
	}*/
	//friend std::ostream& operator<< (std::ostream &os, const BinariTree<T> &tree);

	void Average()
	{
		if (typeid(T) != typeid(short) && typeid(T) != typeid(unsigned short) && typeid(T) != typeid(int) && 
			typeid(T) != typeid(unsigned int) && typeid(T) != typeid(long) && typeid(T) != typeid(unsigned long) &&
			typeid(T) != typeid(long long) && typeid(T) != typeid(unsigned long long) && typeid(T) != typeid(float) &&
			typeid(T) != typeid(double) && typeid(T) != typeid(long double))
		{
			cout << "This Binari Tree don`t support Avarage" << endl;
			return;
		}
		double avg = 0;
		int count = 0;
		queue<BinariTree<T>> q;
		q.push(*this);
		while (!q.empty())
		{
			count++;
			ostringstream str;
			str << q.front().info;
			avg += stod(str.str());
			if (q.front().left != NULL)
			{
				q.push(*q.front().left);
			}
			if (q.front().right != NULL)
			{
				q.push(*q.front().right);
			}
			q.pop();
		}

		avg /= count;
		cout << "Avarage numbers in Tree - " << avg << endl;
	}

	BinariTree<T> operator+=(T newelem)
	{
		AddElem(newelem);
		return *this;
	}

	//~BinariTree()
	//{
	//	DeleteAfter();
	//}
};
template <class T>
std::ostream& operator<< (std::ostream &os, const BinariTree<T> tree)
{
	string output = "";
	queue<BinariTree<T>> q;
	q.push(tree);
	while (!q.empty())
	{
		ostringstream str;
		str << q.front().info;
		output += str.str() + " ";
		if (q.front().left != NULL)
		{
			q.push(*q.front().left);
		}
		if (q.front().right != NULL)
		{
			q.push(*q.front().right);
		}
		q.pop();
	}

	return os << output;
}


int main()
{
	BinariTree<int> root(10);
	root.AddElem(45);
	root.AddElem(3);
	root.AddElem(45);
	root.AddElem(6);

	cout << root << endl;
	root.Print();
	root.Average();

	root += 8;
	root += 45;
	root += 22;
	root += 1;
	root += 7;
	root.Print();
	root.Average();

	root.DeleteElem(3);
	cout << root << endl;
	root.Print();
}