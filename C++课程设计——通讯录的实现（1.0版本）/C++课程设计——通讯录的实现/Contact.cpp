#define _CRT_SECURE_NO_WARNINGS   1
#include"Contact.h"

//初始化通讯录
void InitContact(struct Contact *pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));//memset是用来设置内存的
}


//交换
void Swap(struct PeoInfo *pc1, struct PeoInfo * pc2)
{
	struct PeoInfo tmp;
	tmp = *pc1;
	*pc1 = *pc2;
	*pc2 = tmp;

}
//增加一个人的信息
void AddContact(struct Contact *pc)
{
	if (pc->sz == 1000)
	{
		cout << "抱歉，当前通讯录储存信息数已达到最大可存储数，您不可再增加信息" << endl;
	}
	else
	{
		cout << "请输入姓名" << endl;
		cin>>pc->data[pc->sz]._name;
		cout << "请输入院系" << endl;
		cin >> pc->data[pc->sz]._department;
		cout << "请输入班级" << endl;
		cin >> pc->data[pc->sz]._class;
		cout << "请输入电话" << endl;
		cin >> pc->data[pc->sz]._telephone;
		cout << "请输入邮件" << endl;
		cin >> pc->data[pc->sz]._email;
		cout << "请输入地址" << endl;
		cin >> pc->data[pc->sz]._address;
		cout << "请输入邮编" << endl;
		cin >> pc->data[pc->sz]._postcode;

		pc->sz++; 
		cout << "添加成功" << endl<<endl<<endl;
	}
}


//显示一个人的信息
void ShowContact(const struct Contact *pc)
{
	if (pc->sz == 0)
	{
		cout << "您的通讯录尚无联系人！" << endl<<endl<<endl;
	}
	else
	{
		int i = 0;
		cout << setw(20) << "姓名" << setw(20) << "院系"
			<< setw(20) << "班级"<<setw(20) << "电话"<< 
			setw(20) << "邮件" <<setw(20) << "地址"<< setw(20)
			<< "邮编"<<endl<<endl;
		for (i = 0; i < pc->sz; ++i)
		{
			cout 
				<< setw(20)<< pc->data[i]._name
				<< setw(20) << pc->data[i]._department
				<< setw(20) << pc->data[i]._class
				<< setw(20) << pc->data[i]._telephone
				<< setw(20) << pc->data[i]._email
				<< setw(20) << pc->data[i]._address
				<< setw(20) << pc->data[i]._postcode
				<< endl << endl;
		}
	}
}


//通过姓名查找
int SearchContactByName(struct Contact *pc, string Name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._name==Name)
			return i;
	}
	//没找到
	return -1;
}
//通过院系查找
int SearchContactByDepartment(struct Contact *pc, string Department)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[pc->sz]._department==Department)
			return i;
	}

	//没找到
	return -1;
}
//通过班级查找
int SearchContactByClass(struct Contact *pc, string Class)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._class==Class)
			return i;
	}
	//没找到
	return -1;
}
//通过电话查找
int SearchContactByTelephone(struct Contact *pc, string Telephone)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._telephone==Telephone)
			return i;
	}

	//没找到
	return -1;
}
//通过邮箱查找
int SearchContactByEmail(struct Contact *pc, string Email)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._email==Email)
			return i;
	}

	//没找到
	return -1;
}
//通过地址查找
int SearchContactByAddress(struct Contact *pc, string Address)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._address==Address)
			return i;
	}

	//没找到
	return -1;
}
//通过邮编查找
int SearchContactByPostcode(struct Contact *pc, string Postcode)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._postcode==Postcode)
			return i;
	}

	//没找到
	return -1;
}
//查找指定联系人
void SearchContact(struct Contact *pc)
{
	int n;
	int pos;
	string information;
	enum
	{
		Exit,
		Name,
		Department,
		Class,
		Telephone,
		Email,
		Address,
		Postcode
	};

	cout << "请选择您所要查找的联系人的依据的代号" << endl << endl << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************     1.名字     ********************* |" << endl;
	cout << "| ********************     2.院系     ********************* |" << endl;
	cout << "| ********************     3.班级     ********************* |" << endl;
	cout << "| ********************     4.电话     ********************* |" << endl;
	cout << "| ********************     5.邮件     ********************* |" << endl;
	cout << "| ********************     6.地址     ********************* |" << endl;
	cout << "| ********************     7.邮编     ********************* |" << endl;
	cout << "| ********************     0.退出     ********************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cin >> n;
	switch (n)
	{
	case Name:
		cout << "请输入姓名" << endl;
		cin >> information;
		pos=SearchContactByName(pc,information);
		break;
	case Department:
		cout << "请输入院系" << endl;
		cin >> information;
		pos=SearchContactByDepartment(pc, information);
		break;
	case Class:
		cout << "请输入班级" << endl;
		cin >> information;
		pos=SearchContactByClass(pc, information);
		break;
	case Email:
		cout << "请输入邮箱" << endl;
		cin >> information;
		pos=SearchContactByEmail(pc, information);
		break;
	case Address:
		cout << "请输入地址" << endl;
		cin >> information;
		pos=SearchContactByAddress(pc, information);
		break;
	case Postcode:
		cout << "请输入邮编" << endl;
		cin >> information;
		pos=SearchContactByPostcode(pc, information);
		break;
	default:
		cout << "您的选择有误，程序退出" << endl;
		break;
	}
	cout << "您查询的联系人的全部信息如下：" << endl << endl;
	cout << setw(20) << "姓名" << setw(20) << "院系"
		<< setw(20) << "班级" << setw(20) << "电话" <<
		setw(20) << "邮件" << setw(20) << "地址" << setw(20)
		<< "邮编" << endl << endl;
	cout
		<< setw(20) << pc->data[pos]._name
		<< setw(20) << pc->data[pos]._department
		<< setw(20) << pc->data[pos]._class
		<< setw(20) << pc->data[pos]._telephone
		<< setw(20) << pc->data[pos]._email
		<< setw(20) << pc->data[pos]._address
		<< setw(20) << pc->data[pos]._postcode
		<< endl << endl;
}


//通过姓名删除
void DelContactByName(struct Contact *pc, string Name)
{
	if (pc->sz == 0)//判断是否为空通讯录
	{
		cout << endl << endl;
		cout << "您的通讯录为空，没有可删除的联系人" << endl << endl;
	}
	else
	{
		//1.找到要删除的人
		int pos = SearchContactByName(pc, Name);//检查有没有这个人
		if (pos == -1)
		{
			cout << "抱歉，通讯录中不存在您要删除的联系人" << endl << endl;
		}
		else
		{
			//2.删除
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "已经成功删除" << endl << endl;

		}

	}
}
//通过院系删除
void DelContactByDepartment(struct Contact *pc, string Department)
{
	if (pc->sz == 0)//判断是否为空通讯录
	{
		cout << endl << endl;
		cout << "您的通讯录为空，没有可删除的联系人" << endl << endl;
	}
	else
	{
		//1.找到要删除的人
		int pos = SearchContactByName(pc, Department);//检查有没有这个人
		if (pos == -1)
		{
			cout << "抱歉，通讯录中不存在您要删除的联系人" << endl << endl;
		}
		else
		{
			//2.删除
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "已经成功删除" << endl << endl;

		}

	}
}
//通过班级删除
void DelContactByClass(struct Contact *pc, string Class)
{
	if (pc->sz == 0)//判断是否为空通讯录
	{
		cout << endl << endl;
		cout << "您的通讯录为空，没有可删除的联系人" << endl << endl;
	}
	else
	{
		//1.找到要删除的人
		int pos = SearchContactByName(pc, Class);//检查有没有这个人
		if (pos == -1)
		{
			cout << "抱歉，通讯录中不存在您要删除的联系人" << endl << endl;
		}
		else
		{
			//2.删除
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "已经成功删除" << endl << endl;

		}

	}
}
//通过电话删除
void DelContactByTelephone(struct Contact *pc, string Telephone)
{
	if (pc->sz == 0)//判断是否为空通讯录
	{
		cout << endl << endl;
		cout << "您的通讯录为空，没有可删除的联系人" << endl << endl;
	}
	else
	{
		//1.找到要删除的人
		int pos = SearchContactByName(pc, Telephone);//检查有没有这个人
		if (pos == -1)
		{
			cout << "抱歉，通讯录中不存在您要删除的联系人" << endl << endl;
		}
		else
		{
			//2.删除
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "已经成功删除" << endl << endl;

		}

	}
}
//通过邮箱删除
void  DelContactByEmail(struct Contact *pc, string Email)
{
	if (pc->sz == 0)//判断是否为空通讯录
	{
		cout << endl << endl;
		cout << "您的通讯录为空，没有可删除的联系人" << endl << endl;
	}
	else
	{
		//1.找到要删除的人
		int pos = SearchContactByName(pc, Email);//检查有没有这个人
		if (pos == -1)
		{
			cout << "抱歉，通讯录中不存在您要删除的联系人" << endl << endl;
		}
		else
		{
			//2.删除
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "已经成功删除" << endl << endl;

		}

	}
}
//通过地址删除
void  DelContactByAddress(struct Contact *pc, string Address)
{
	if (pc->sz == 0)//判断是否为空通讯录
	{
		cout << endl << endl;
		cout << "您的通讯录为空，没有可删除的联系人" << endl << endl;
	}
	else
	{
		//1.找到要删除的人
		int pos = SearchContactByName(pc, Address);//检查有没有这个人
		if (pos == -1)
		{
			cout << "抱歉，通讯录中不存在您要删除的联系人" << endl << endl;
		}
		else
		{
			//2.删除
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "已经成功删除" << endl << endl;

		}

	}
}
//通过邮编删除
void  DelContactByPostcode(struct Contact *pc, string Postcode)
{
	if (pc->sz == 0)//判断是否为空通讯录
	{
		cout << endl << endl;
		cout << "您的通讯录为空，没有可删除的联系人" << endl << endl;
	}
	else
	{
		//1.找到要删除的人
		int pos = SearchContactByName(pc, Postcode);//检查有没有这个人
		if (pos == -1)
		{
			cout << "抱歉，通讯录中不存在您要删除的联系人" << endl << endl;
		}
		else
		{
			//2.删除
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "已经成功删除" << endl << endl;

		}

	}
}
//删除一个人的信息
void DelContact(struct Contact *pc)
{
	if (pc->sz == 0)
	{
		cout << "抱歉，您当前通讯录无联系人可删除" << endl;
	}
	else
	{
		enum
		{
			Exit,
			Name,
			Department,
			Class,
			Telephone,
			Email,
			Address,
			Postcode
		};
		int n;
		string information;
		cout << "请选择您所要删除的联系人的依据的代号" << endl<<endl<<endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "| ********************************************************* |" << endl;
		cout << "| ********************************************************* |" << endl;
		cout << "| ********************     1.名字     ********************* |" << endl;
		cout << "| ********************     2.院系     ********************* |" << endl;
		cout << "| ********************     3.班级     ********************* |" << endl;
		cout << "| ********************     4.电话     ********************* |" << endl;
		cout << "| ********************     5.邮件     ********************* |" << endl;
		cout << "| ********************     6.地址     ********************* |" << endl;
		cout << "| ********************     7.邮编     ********************* |" << endl;
		cout << "| ********************     0.退出     ********************* |" << endl;
		cout << "| ********************************************************* |" << endl;
		cout << "| ********************************************************* |" << endl;
		cout << "| ********************************************************* |" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cin>> n;
		switch (n)
		{
		case Name:
			cout << "请输入您要删除的联系人的姓名" << endl;
			cin >> information;
			DelContactByName(pc,information);
			break;
		case Department:
			cout << "请输入您要删除的联系人的院系" << endl;
			cin >> information;
			DelContactByDepartment(pc, information);
			break;
		case Class:
			cout << "请输入您要删除的联系人的班级" << endl;
			cin >> information;
			DelContactByClass(pc, information);
			break;
		case Email:
			cout << "请输入您要删除的联系人的邮箱" << endl;
			cin >> information;
			DelContactByEmail(pc, information);
			break;
		case Address:
			cout << "请输入您要删除的联系人的地址" << endl;
			cin >> information;
			DelContactByAddress(pc, information);
			break;
		case Postcode:
			cout << "请输入您要删除的联系人的邮编" << endl;
			cin >> information;
			DelContactByPostcode(pc, information);
			break;
		default:
			cout << "您的选择有误，程序退出" << endl;
			break;
		}
	}
}



//修改信息
void ModifyContact(struct Contact *pc)
{
	int n;
	int m;
	int pos;
	string information;
	string _information;
	enum
	{
		Exit,
		Name,
		Department,
		Class,
		Telephone,
		Email,
		Address,
		Postcode
	};
	cout << "请输入你想要通过下列何种方式查找到想要修改信息的联系人" << endl<<endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************     1.名字     ********************* |" << endl;
	cout << "| ********************     2.院系     ********************* |" << endl;
	cout << "| ********************     3.班级     ********************* |" << endl;
	cout << "| ********************     4.电话     ********************* |" << endl;
	cout << "| ********************     5.邮件     ********************* |" << endl;
	cout << "| ********************     6.地址     ********************* |" << endl;
	cout << "| ********************     7.邮编     ********************* |" << endl;
	cout << "| ********************     0.退出     ********************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "-------------------------------------------------------------" << endl;

	cin >> n;
	switch (n)
	{
	case Name:
		cout << "请输入姓名" << endl;
		cin >> information;
		pos = SearchContactByName(pc, information);
		break;
	case Department:
		cout << "请输入院系" << endl;
		cin >> information;
		pos = SearchContactByDepartment(pc, information);
		break;
	case Class:
		cout << "请输入班级" << endl;
		cin >> information;
		pos = SearchContactByClass(pc, information);
		break;
	case Email:
		cout << "请输入邮箱" << endl;
		cin >> information;
		pos = SearchContactByEmail(pc, information);
		break;
	case Address:
		cout << "请输入地址" << endl;
		cin >> information;
		pos = SearchContactByAddress(pc, information);
		break;
	case Postcode:
		cout << "请输入邮编" << endl;
		cin >> information;
		pos = SearchContactByPostcode(pc, information);
		break;
	default:
		cout << "您的选择有误，程序退出" << endl;
		break;
	}
	if (pos == -1)
	{
		cout << "没有查询到您所要修改的联系人，请重新选择" << endl << endl;
	}
	else
	{

		cout << "您所要修改的联系人已经查询到，下面请您选择要修改的内容" << endl << endl;
		do
		{
			cout << "请输入您所要更改的信息" << endl << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "| ********************************************************* |" << endl;
			cout << "| ********************************************************* |" << endl;
			cout << "| ********************     1.名字     ********************* |" << endl;
			cout << "| ********************     2.院系     ********************* |" << endl;
			cout << "| ********************     3.班级     ********************* |" << endl;
			cout << "| ********************     4.电话     ********************* |" << endl;
			cout << "| ********************     5.邮件     ********************* |" << endl;
			cout << "| ********************     6.地址     ********************* |" << endl;
			cout << "| ********************     7.邮编     ********************* |" << endl;
			cout << "| ********************     0.退出     ********************* |" << endl;
			cout << "| ********************************************************* |" << endl;
			cout << "| ********************************************************* |" << endl;
			cout << "| ********************************************************* |" << endl;
			cout << "-------------------------------------------------------------" << endl;
			cin >> m;
			switch (m)
			{
			case Name:
				cout << "请输入修改后的姓名" << endl;
				cin >> _information;
				pc->data[pos]._name = _information;
				cout << "修改成功" << endl << endl;
				break;
			case Department:
				cout << "请输入修改后的院系" << endl;
				cin >> _information;
				pc->data[pos]._department = _information;
				cout << "修改成功" << endl << endl;
				break;
			case Class:
				cout << "请输入修改后班级" << endl;
				cin >> _information;
				pc->data[pos]._class = _information;
				cout << "修改成功" << endl << endl;
				break;
			case Email:
				cout << "请输入修改后的邮箱" << endl;
				cin >> _information;
				pc->data[pos]._email = _information;
				cout << "修改成功" << endl << endl;
				break;
			case Address:
				cout << "请输入修改后的地址" << endl;
				cin >> _information;
				pc->data[pos]._address = _information;
				cout << "修改成功" << endl << endl;
				break;
			case Postcode:
				cout << "请输入修改后的邮编" << endl;
				cin >> _information;
				pc->data[pos]._postcode = _information;
				cout << "修改成功" << endl << endl;
				break;
			default:
				cout << "您的选择有误，程序退出" << endl;
				break;
			}
		} while (m);
	}
	
}


//通过姓名排序
void SortContactByName(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//按照名字排序
	for (i = 0; i<pc->sz - 1; i++)   //趟数
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //比较次数
		{
			if (pc->data[j]._name.compare(pc->data[j + 1]._name)>0)  //前者大，才需要交换
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//通过院系排序
void SortContactByDepartment(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//按照名字排序
	for (i = 0; i<pc->sz - 1; i++)   //趟数
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //比较次数
		{
			if (pc->data[j]._department.compare(pc->data[j + 1]._department)>0)  //前者大，才需要交换
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//通过班级排序
void SortContactByClass(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//按照名字排序
	for (i = 0; i<pc->sz - 1; i++)   //趟数
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //比较次数
		{
			if (pc->data[j]._class.compare(pc->data[j + 1]._class)>0)  //前者大，才需要交换
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//通过电话排序
void SortContactByTelephone(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//按照名字排序
	for (i = 0; i<pc->sz - 1; i++)   //趟数
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //比较次数
		{
			if (pc->data[j]._telephone.compare(pc->data[j + 1]._telephone)>0)  //前者大，才需要交换
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//通过邮箱排序
void SortContactByEmail(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//按照名字排序
	for (i = 0; i<pc->sz - 1; i++)   //趟数
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //比较次数
		{
			if (pc->data[j]._email.compare(pc->data[j + 1]._email)>0)  //前者大，才需要交换
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//通过地址排序
void SortContactByAddress(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//按照名字排序
	for (i = 0; i<pc->sz - 1; i++)   //趟数
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //比较次数
		{
			if (pc->data[j]._address.compare(pc->data[j + 1]._address)>0)  //前者大，才需要交换
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//通过邮编排序
void SortContactByPostcode(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//按照名字排序
	for (i = 0; i<pc->sz - 1; i++)   //趟数
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //比较次数
		{
			if (pc->data[j]._postcode.compare(pc->data[j + 1]._postcode)>0)  //前者大，才需要交换
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}

//排序
void SortContact(struct Contact *pc)
{
	int n;
	enum
	{
		Exit,
		Name,
		Department,
		Class,
		Telephone,
		Email,
		Address,
		Postcode
	};
	cout << "请输入你想要的排序依据" << endl << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************     1.名字     ********************* |" << endl;
	cout << "| ********************     2.院系     ********************* |" << endl;
	cout << "| ********************     3.班级     ********************* |" << endl;
	cout << "| ********************     4.电话     ********************* |" << endl;
	cout << "| ********************     5.邮件     ********************* |" << endl;
	cout << "| ********************     6.地址     ********************* |" << endl;
	cout << "| ********************     7.邮编     ********************* |" << endl;
	cout << "| ********************     0.退出     ********************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cin >> n;
	switch (n)
	{
	case Name:
		SortContactByName(pc);
		break;
	case Department:
		SortContactByDepartment(pc);
		break;
	case Class:
		SortContactByClass(pc);
		break;
	case Email:
		SortContactByEmail(pc);
		break;
	case Address:
		SortContactByAddress(pc);
		break;
	case Postcode:
		SortContactByPostcode(pc);
		break;
	default:
		cout << "您的选择有误，程序退出" << endl;
		break;
	}
}


//清空
void EmptyContact(struct Contact *pc)
{
	assert(pc != NULL);
	pc->sz = 0;
	printf("Successfully empty\n");
}
