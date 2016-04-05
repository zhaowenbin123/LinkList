#include"List.h"
//
//
//void Test1()
//{
//	List<int> l;
//	l.PushBack(1);
//	l.PushBack(2);
//	l.PushBack(3);
//	l.PushBack(4);
//	l.Print();
//
//
//	l.PopBack();
//	l.PopBack();
//	l.Print();
//	l.PopBack();
//	l.PopBack();
//	l.Print();
//
//
//	l.PushFront(1);
//	l.PushFront(2);
//	l.Print();
//	l.PushFront(3);
//	l.PushFront(4);
//	l.Print();
//
//
//	l.PopFront();
//	l.Print();
//
//	l.PopFront();
//	l.PopFront();
//	l.Print();
//	
//	l.PopFront();
//	l.Print();
//}
//
//void Test2()
//{
//	List<int> s;
//	s.PushBack(1);
//	s.PushBack(2);
//	s.PushBack(3);
//	s.PushBack(4);
//	s.PushBack(5);
//	s.Print();
//
//	s.Find(4);
//	/*s.Insert_pos(2, 6);
//	s.Print();*/
//
//	s.Insert_val(3, 7);
//	s.Print();
//	s.Delete_pos(10);
//	s.Print();
//
//
//	s.Delete_val(2);
//	s.Print();
//
//	s.Reverse();
//	s.Print();
//	
//}
//int main()
//{
//	//Test1();
//	Test2();
//	return 0;
//}




int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//template <class T, int DefaultCapacity = 10 >
	List<int> mylist;
	int select = 1;
	int Item;
	int pos;
flag:
	cout << endl << endl;;
	cout << "	* * * * * * * welcome to use  List  * * * * * * * *" << endl;
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
			cout << "请输入要在i后插入的值:>";
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