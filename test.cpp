
#include "LinkList.h"


void Test1()
{
	LinkList<int> a;
	a.PushBack(1);
	a.PushBack(2);
	a.PushBack(3);
	a.Print();

	a.PopBack();
	a.Print();
	a.PopBack();
	a.Print();
	a.PopBack();

	a.Print();

	a.PushFront(1);
	a.PushFront(4);
	a.PushFront(3);
	a.PushFront(2);
	a.Print();


	a.PopFront();
	a.Print();
	a.PopFront();
	a.Print();
	a.PopFront();
	a.Print();
	a.PopFront();
	a.Print();
	a.PopFront();
}


void Test2()
{
	LinkList<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.Print();

	
	l.Insert_val(3, 5);
	l.Insert_pos(4, 7);
	l.Print();

	l.Reverse();
	l.Print();

	l.Delete_pos(3);
	l.Print();
	l.Delete_val(7);
	l.Print();
	l.Length();
}
//void main()
//{
//	//Test1();
//	//Test2();
//
//}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//template <class T, int DefaultCapacity = 10 >
	LinkList<int> mylist;
	int select = 1;
	int Item;
	int pos;
flag:
	cout << endl << endl;;
	cout << "	* * * * * * * welcome to use SeqList* * * * * * * *" << endl;
	void Menu();
	{
		cout << "	*	1. PushBack		2. PushFront      *" << endl;
		cout << "	*	3. Print		4. PopBack        *" << endl;
		cout << "	*	5. PopFront		6. Insert_pos     *" << endl;
		cout << "	*	7. Insert_val	        8. Delete_pos     *" << endl;
		cout << "	*	9. Delete_val	        10.Find           *" << endl;
		cout << "	*	11. length		12.clear	  *" << endl;
		cout << "	*	13. reverse		14.sort		  *" << endl;
		cout << "	*	15. clear	         0.exit		  *" << endl;
		cout << "	*        		    			  *" << endl;
		cout << "	*       Please select:			          *" << endl;
		cout << "	* * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	}
	while (select)
	{
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "请输入要后插的值(-1结束):>";
			while (cin >> Item, Item != -1)
			{
				mylist.PushBack(Item);
			}
			break;
		case 2:
			cout << "请输入要头插的值(-1结束):>";
			while (cin >> Item, Item != -1)
			{
				mylist.PushFront(Item);
			}
			break;
		case 3:
			mylist.Print();
			break;
		case 4:
			mylist.PopBack();
			break;
		case 5:
			mylist.PopFront();
			break;
		case 6:
			cout << "请输入要插入的位置:>";
			cin >> pos;
			cout << "请输入要插入的值:>";
			cin >> Item;
			mylist.Insert_pos(pos, Item);
			break;
		case 7:
			cout << "请输入要在i插入的值:>";
			cin >> pos;
			cout << "请输入要插入的值x:";
			cin >> Item;
			mylist.Insert_val(pos, Item);
			break;
			break;
		case 8:
			cout << "请输入要删除的位置:>";
			cin >> pos;
			mylist.Delete_pos(pos);
			break;
		case 9:
			cout << "请输入要删除的值:>";
			cin >> Item;
			mylist.Delete_val(Item);
			break;
		case 10:
			cout << "请输入要查找的值:>";
			cin >> Item;
			mylist.Find(Item);
			break;
		case 11:
			mylist.Length();
			break;
		case 12:
			//mylist.clear();
			break;
		case 13:
			mylist.Reverse();
			break;
		case 14:
			//mylist.sort(/*0,a-1*/);
			break;
		case 0:
			exit(0);
		default:
			break;
		}
		cout << endl;
		goto flag;
	}
	return 0;
}