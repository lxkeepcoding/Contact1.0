#define _CRT_SECURE_NO_WARNINGS   1
#include"Contact.h"

//��ʼ��ͨѶ¼
void InitContact(struct Contact *pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));//memset�����������ڴ��
}


//����
void Swap(struct PeoInfo *pc1, struct PeoInfo * pc2)
{
	struct PeoInfo tmp;
	tmp = *pc1;
	*pc1 = *pc2;
	*pc2 = tmp;

}
//����һ���˵���Ϣ
void AddContact(struct Contact *pc)
{
	if (pc->sz == 1000)
	{
		cout << "��Ǹ����ǰͨѶ¼������Ϣ���Ѵﵽ���ɴ洢������������������Ϣ" << endl;
	}
	else
	{
		cout << "����������" << endl;
		cin>>pc->data[pc->sz]._name;
		cout << "������Ժϵ" << endl;
		cin >> pc->data[pc->sz]._department;
		cout << "������༶" << endl;
		cin >> pc->data[pc->sz]._class;
		cout << "������绰" << endl;
		cin >> pc->data[pc->sz]._telephone;
		cout << "�������ʼ�" << endl;
		cin >> pc->data[pc->sz]._email;
		cout << "�������ַ" << endl;
		cin >> pc->data[pc->sz]._address;
		cout << "�������ʱ�" << endl;
		cin >> pc->data[pc->sz]._postcode;

		pc->sz++; 
		cout << "��ӳɹ�" << endl<<endl<<endl;
	}
}


//��ʾһ���˵���Ϣ
void ShowContact(const struct Contact *pc)
{
	if (pc->sz == 0)
	{
		cout << "����ͨѶ¼������ϵ�ˣ�" << endl<<endl<<endl;
	}
	else
	{
		int i = 0;
		cout << setw(20) << "����" << setw(20) << "Ժϵ"
			<< setw(20) << "�༶"<<setw(20) << "�绰"<< 
			setw(20) << "�ʼ�" <<setw(20) << "��ַ"<< setw(20)
			<< "�ʱ�"<<endl<<endl;
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


//ͨ����������
int SearchContactByName(struct Contact *pc, string Name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._name==Name)
			return i;
	}
	//û�ҵ�
	return -1;
}
//ͨ��Ժϵ����
int SearchContactByDepartment(struct Contact *pc, string Department)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[pc->sz]._department==Department)
			return i;
	}

	//û�ҵ�
	return -1;
}
//ͨ���༶����
int SearchContactByClass(struct Contact *pc, string Class)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._class==Class)
			return i;
	}
	//û�ҵ�
	return -1;
}
//ͨ���绰����
int SearchContactByTelephone(struct Contact *pc, string Telephone)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._telephone==Telephone)
			return i;
	}

	//û�ҵ�
	return -1;
}
//ͨ���������
int SearchContactByEmail(struct Contact *pc, string Email)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._email==Email)
			return i;
	}

	//û�ҵ�
	return -1;
}
//ͨ����ַ����
int SearchContactByAddress(struct Contact *pc, string Address)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._address==Address)
			return i;
	}

	//û�ҵ�
	return -1;
}
//ͨ���ʱ����
int SearchContactByPostcode(struct Contact *pc, string Postcode)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (pc->data[i]._postcode==Postcode)
			return i;
	}

	//û�ҵ�
	return -1;
}
//����ָ����ϵ��
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

	cout << "��ѡ������Ҫ���ҵ���ϵ�˵����ݵĴ���" << endl << endl << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************     1.����     ********************* |" << endl;
	cout << "| ********************     2.Ժϵ     ********************* |" << endl;
	cout << "| ********************     3.�༶     ********************* |" << endl;
	cout << "| ********************     4.�绰     ********************* |" << endl;
	cout << "| ********************     5.�ʼ�     ********************* |" << endl;
	cout << "| ********************     6.��ַ     ********************* |" << endl;
	cout << "| ********************     7.�ʱ�     ********************* |" << endl;
	cout << "| ********************     0.�˳�     ********************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cin >> n;
	switch (n)
	{
	case Name:
		cout << "����������" << endl;
		cin >> information;
		pos=SearchContactByName(pc,information);
		break;
	case Department:
		cout << "������Ժϵ" << endl;
		cin >> information;
		pos=SearchContactByDepartment(pc, information);
		break;
	case Class:
		cout << "������༶" << endl;
		cin >> information;
		pos=SearchContactByClass(pc, information);
		break;
	case Email:
		cout << "����������" << endl;
		cin >> information;
		pos=SearchContactByEmail(pc, information);
		break;
	case Address:
		cout << "�������ַ" << endl;
		cin >> information;
		pos=SearchContactByAddress(pc, information);
		break;
	case Postcode:
		cout << "�������ʱ�" << endl;
		cin >> information;
		pos=SearchContactByPostcode(pc, information);
		break;
	default:
		cout << "����ѡ�����󣬳����˳�" << endl;
		break;
	}
	cout << "����ѯ����ϵ�˵�ȫ����Ϣ���£�" << endl << endl;
	cout << setw(20) << "����" << setw(20) << "Ժϵ"
		<< setw(20) << "�༶" << setw(20) << "�绰" <<
		setw(20) << "�ʼ�" << setw(20) << "��ַ" << setw(20)
		<< "�ʱ�" << endl << endl;
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


//ͨ������ɾ��
void DelContactByName(struct Contact *pc, string Name)
{
	if (pc->sz == 0)//�ж��Ƿ�Ϊ��ͨѶ¼
	{
		cout << endl << endl;
		cout << "����ͨѶ¼Ϊ�գ�û�п�ɾ������ϵ��" << endl << endl;
	}
	else
	{
		//1.�ҵ�Ҫɾ������
		int pos = SearchContactByName(pc, Name);//�����û�������
		if (pos == -1)
		{
			cout << "��Ǹ��ͨѶ¼�в�������Ҫɾ������ϵ��" << endl << endl;
		}
		else
		{
			//2.ɾ��
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "�Ѿ��ɹ�ɾ��" << endl << endl;

		}

	}
}
//ͨ��Ժϵɾ��
void DelContactByDepartment(struct Contact *pc, string Department)
{
	if (pc->sz == 0)//�ж��Ƿ�Ϊ��ͨѶ¼
	{
		cout << endl << endl;
		cout << "����ͨѶ¼Ϊ�գ�û�п�ɾ������ϵ��" << endl << endl;
	}
	else
	{
		//1.�ҵ�Ҫɾ������
		int pos = SearchContactByName(pc, Department);//�����û�������
		if (pos == -1)
		{
			cout << "��Ǹ��ͨѶ¼�в�������Ҫɾ������ϵ��" << endl << endl;
		}
		else
		{
			//2.ɾ��
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "�Ѿ��ɹ�ɾ��" << endl << endl;

		}

	}
}
//ͨ���༶ɾ��
void DelContactByClass(struct Contact *pc, string Class)
{
	if (pc->sz == 0)//�ж��Ƿ�Ϊ��ͨѶ¼
	{
		cout << endl << endl;
		cout << "����ͨѶ¼Ϊ�գ�û�п�ɾ������ϵ��" << endl << endl;
	}
	else
	{
		//1.�ҵ�Ҫɾ������
		int pos = SearchContactByName(pc, Class);//�����û�������
		if (pos == -1)
		{
			cout << "��Ǹ��ͨѶ¼�в�������Ҫɾ������ϵ��" << endl << endl;
		}
		else
		{
			//2.ɾ��
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "�Ѿ��ɹ�ɾ��" << endl << endl;

		}

	}
}
//ͨ���绰ɾ��
void DelContactByTelephone(struct Contact *pc, string Telephone)
{
	if (pc->sz == 0)//�ж��Ƿ�Ϊ��ͨѶ¼
	{
		cout << endl << endl;
		cout << "����ͨѶ¼Ϊ�գ�û�п�ɾ������ϵ��" << endl << endl;
	}
	else
	{
		//1.�ҵ�Ҫɾ������
		int pos = SearchContactByName(pc, Telephone);//�����û�������
		if (pos == -1)
		{
			cout << "��Ǹ��ͨѶ¼�в�������Ҫɾ������ϵ��" << endl << endl;
		}
		else
		{
			//2.ɾ��
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "�Ѿ��ɹ�ɾ��" << endl << endl;

		}

	}
}
//ͨ������ɾ��
void  DelContactByEmail(struct Contact *pc, string Email)
{
	if (pc->sz == 0)//�ж��Ƿ�Ϊ��ͨѶ¼
	{
		cout << endl << endl;
		cout << "����ͨѶ¼Ϊ�գ�û�п�ɾ������ϵ��" << endl << endl;
	}
	else
	{
		//1.�ҵ�Ҫɾ������
		int pos = SearchContactByName(pc, Email);//�����û�������
		if (pos == -1)
		{
			cout << "��Ǹ��ͨѶ¼�в�������Ҫɾ������ϵ��" << endl << endl;
		}
		else
		{
			//2.ɾ��
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "�Ѿ��ɹ�ɾ��" << endl << endl;

		}

	}
}
//ͨ����ַɾ��
void  DelContactByAddress(struct Contact *pc, string Address)
{
	if (pc->sz == 0)//�ж��Ƿ�Ϊ��ͨѶ¼
	{
		cout << endl << endl;
		cout << "����ͨѶ¼Ϊ�գ�û�п�ɾ������ϵ��" << endl << endl;
	}
	else
	{
		//1.�ҵ�Ҫɾ������
		int pos = SearchContactByName(pc, Address);//�����û�������
		if (pos == -1)
		{
			cout << "��Ǹ��ͨѶ¼�в�������Ҫɾ������ϵ��" << endl << endl;
		}
		else
		{
			//2.ɾ��
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "�Ѿ��ɹ�ɾ��" << endl << endl;

		}

	}
}
//ͨ���ʱ�ɾ��
void  DelContactByPostcode(struct Contact *pc, string Postcode)
{
	if (pc->sz == 0)//�ж��Ƿ�Ϊ��ͨѶ¼
	{
		cout << endl << endl;
		cout << "����ͨѶ¼Ϊ�գ�û�п�ɾ������ϵ��" << endl << endl;
	}
	else
	{
		//1.�ҵ�Ҫɾ������
		int pos = SearchContactByName(pc, Postcode);//�����û�������
		if (pos == -1)
		{
			cout << "��Ǹ��ͨѶ¼�в�������Ҫɾ������ϵ��" << endl << endl;
		}
		else
		{
			//2.ɾ��
			int j;
			for (j = pos; j <pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;

			cout << "�Ѿ��ɹ�ɾ��" << endl << endl;

		}

	}
}
//ɾ��һ���˵���Ϣ
void DelContact(struct Contact *pc)
{
	if (pc->sz == 0)
	{
		cout << "��Ǹ������ǰͨѶ¼����ϵ�˿�ɾ��" << endl;
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
		cout << "��ѡ������Ҫɾ������ϵ�˵����ݵĴ���" << endl<<endl<<endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "| ********************************************************* |" << endl;
		cout << "| ********************************************************* |" << endl;
		cout << "| ********************     1.����     ********************* |" << endl;
		cout << "| ********************     2.Ժϵ     ********************* |" << endl;
		cout << "| ********************     3.�༶     ********************* |" << endl;
		cout << "| ********************     4.�绰     ********************* |" << endl;
		cout << "| ********************     5.�ʼ�     ********************* |" << endl;
		cout << "| ********************     6.��ַ     ********************* |" << endl;
		cout << "| ********************     7.�ʱ�     ********************* |" << endl;
		cout << "| ********************     0.�˳�     ********************* |" << endl;
		cout << "| ********************************************************* |" << endl;
		cout << "| ********************************************************* |" << endl;
		cout << "| ********************************************************* |" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cin>> n;
		switch (n)
		{
		case Name:
			cout << "��������Ҫɾ������ϵ�˵�����" << endl;
			cin >> information;
			DelContactByName(pc,information);
			break;
		case Department:
			cout << "��������Ҫɾ������ϵ�˵�Ժϵ" << endl;
			cin >> information;
			DelContactByDepartment(pc, information);
			break;
		case Class:
			cout << "��������Ҫɾ������ϵ�˵İ༶" << endl;
			cin >> information;
			DelContactByClass(pc, information);
			break;
		case Email:
			cout << "��������Ҫɾ������ϵ�˵�����" << endl;
			cin >> information;
			DelContactByEmail(pc, information);
			break;
		case Address:
			cout << "��������Ҫɾ������ϵ�˵ĵ�ַ" << endl;
			cin >> information;
			DelContactByAddress(pc, information);
			break;
		case Postcode:
			cout << "��������Ҫɾ������ϵ�˵��ʱ�" << endl;
			cin >> information;
			DelContactByPostcode(pc, information);
			break;
		default:
			cout << "����ѡ�����󣬳����˳�" << endl;
			break;
		}
	}
}



//�޸���Ϣ
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
	cout << "����������Ҫͨ�����к��ַ�ʽ���ҵ���Ҫ�޸���Ϣ����ϵ��" << endl<<endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************     1.����     ********************* |" << endl;
	cout << "| ********************     2.Ժϵ     ********************* |" << endl;
	cout << "| ********************     3.�༶     ********************* |" << endl;
	cout << "| ********************     4.�绰     ********************* |" << endl;
	cout << "| ********************     5.�ʼ�     ********************* |" << endl;
	cout << "| ********************     6.��ַ     ********************* |" << endl;
	cout << "| ********************     7.�ʱ�     ********************* |" << endl;
	cout << "| ********************     0.�˳�     ********************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "-------------------------------------------------------------" << endl;

	cin >> n;
	switch (n)
	{
	case Name:
		cout << "����������" << endl;
		cin >> information;
		pos = SearchContactByName(pc, information);
		break;
	case Department:
		cout << "������Ժϵ" << endl;
		cin >> information;
		pos = SearchContactByDepartment(pc, information);
		break;
	case Class:
		cout << "������༶" << endl;
		cin >> information;
		pos = SearchContactByClass(pc, information);
		break;
	case Email:
		cout << "����������" << endl;
		cin >> information;
		pos = SearchContactByEmail(pc, information);
		break;
	case Address:
		cout << "�������ַ" << endl;
		cin >> information;
		pos = SearchContactByAddress(pc, information);
		break;
	case Postcode:
		cout << "�������ʱ�" << endl;
		cin >> information;
		pos = SearchContactByPostcode(pc, information);
		break;
	default:
		cout << "����ѡ�����󣬳����˳�" << endl;
		break;
	}
	if (pos == -1)
	{
		cout << "û�в�ѯ������Ҫ�޸ĵ���ϵ�ˣ�������ѡ��" << endl << endl;
	}
	else
	{

		cout << "����Ҫ�޸ĵ���ϵ���Ѿ���ѯ������������ѡ��Ҫ�޸ĵ�����" << endl << endl;
		do
		{
			cout << "����������Ҫ���ĵ���Ϣ" << endl << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "| ********************************************************* |" << endl;
			cout << "| ********************************************************* |" << endl;
			cout << "| ********************     1.����     ********************* |" << endl;
			cout << "| ********************     2.Ժϵ     ********************* |" << endl;
			cout << "| ********************     3.�༶     ********************* |" << endl;
			cout << "| ********************     4.�绰     ********************* |" << endl;
			cout << "| ********************     5.�ʼ�     ********************* |" << endl;
			cout << "| ********************     6.��ַ     ********************* |" << endl;
			cout << "| ********************     7.�ʱ�     ********************* |" << endl;
			cout << "| ********************     0.�˳�     ********************* |" << endl;
			cout << "| ********************************************************* |" << endl;
			cout << "| ********************************************************* |" << endl;
			cout << "| ********************************************************* |" << endl;
			cout << "-------------------------------------------------------------" << endl;
			cin >> m;
			switch (m)
			{
			case Name:
				cout << "�������޸ĺ������" << endl;
				cin >> _information;
				pc->data[pos]._name = _information;
				cout << "�޸ĳɹ�" << endl << endl;
				break;
			case Department:
				cout << "�������޸ĺ��Ժϵ" << endl;
				cin >> _information;
				pc->data[pos]._department = _information;
				cout << "�޸ĳɹ�" << endl << endl;
				break;
			case Class:
				cout << "�������޸ĺ�༶" << endl;
				cin >> _information;
				pc->data[pos]._class = _information;
				cout << "�޸ĳɹ�" << endl << endl;
				break;
			case Email:
				cout << "�������޸ĺ������" << endl;
				cin >> _information;
				pc->data[pos]._email = _information;
				cout << "�޸ĳɹ�" << endl << endl;
				break;
			case Address:
				cout << "�������޸ĺ�ĵ�ַ" << endl;
				cin >> _information;
				pc->data[pos]._address = _information;
				cout << "�޸ĳɹ�" << endl << endl;
				break;
			case Postcode:
				cout << "�������޸ĺ���ʱ�" << endl;
				cin >> _information;
				pc->data[pos]._postcode = _information;
				cout << "�޸ĳɹ�" << endl << endl;
				break;
			default:
				cout << "����ѡ�����󣬳����˳�" << endl;
				break;
			}
		} while (m);
	}
	
}


//ͨ����������
void SortContactByName(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//������������
	for (i = 0; i<pc->sz - 1; i++)   //����
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //�Ƚϴ���
		{
			if (pc->data[j]._name.compare(pc->data[j + 1]._name)>0)  //ǰ�ߴ󣬲���Ҫ����
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//ͨ��Ժϵ����
void SortContactByDepartment(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//������������
	for (i = 0; i<pc->sz - 1; i++)   //����
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //�Ƚϴ���
		{
			if (pc->data[j]._department.compare(pc->data[j + 1]._department)>0)  //ǰ�ߴ󣬲���Ҫ����
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//ͨ���༶����
void SortContactByClass(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//������������
	for (i = 0; i<pc->sz - 1; i++)   //����
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //�Ƚϴ���
		{
			if (pc->data[j]._class.compare(pc->data[j + 1]._class)>0)  //ǰ�ߴ󣬲���Ҫ����
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//ͨ���绰����
void SortContactByTelephone(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//������������
	for (i = 0; i<pc->sz - 1; i++)   //����
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //�Ƚϴ���
		{
			if (pc->data[j]._telephone.compare(pc->data[j + 1]._telephone)>0)  //ǰ�ߴ󣬲���Ҫ����
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//ͨ����������
void SortContactByEmail(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//������������
	for (i = 0; i<pc->sz - 1; i++)   //����
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //�Ƚϴ���
		{
			if (pc->data[j]._email.compare(pc->data[j + 1]._email)>0)  //ǰ�ߴ󣬲���Ҫ����
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//ͨ����ַ����
void SortContactByAddress(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//������������
	for (i = 0; i<pc->sz - 1; i++)   //����
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //�Ƚϴ���
		{
			if (pc->data[j]._address.compare(pc->data[j + 1]._address)>0)  //ǰ�ߴ󣬲���Ҫ����
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}
//ͨ���ʱ�����
void SortContactByPostcode(struct Contact *pc)
{
	int i = 0;
	int j = 0;

	assert(pc != NULL);
	//������������
	for (i = 0; i<pc->sz - 1; i++)   //����
	{
		for (j = 0; j<pc->sz - i - 1; j++)  //�Ƚϴ���
		{
			if (pc->data[j]._postcode.compare(pc->data[j + 1]._postcode)>0)  //ǰ�ߴ󣬲���Ҫ����
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
			}
		}
	}
	ShowContact(pc);
}

//����
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
	cout << "����������Ҫ����������" << endl << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************************************************* |" << endl;
	cout << "| ********************     1.����     ********************* |" << endl;
	cout << "| ********************     2.Ժϵ     ********************* |" << endl;
	cout << "| ********************     3.�༶     ********************* |" << endl;
	cout << "| ********************     4.�绰     ********************* |" << endl;
	cout << "| ********************     5.�ʼ�     ********************* |" << endl;
	cout << "| ********************     6.��ַ     ********************* |" << endl;
	cout << "| ********************     7.�ʱ�     ********************* |" << endl;
	cout << "| ********************     0.�˳�     ********************* |" << endl;
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
		cout << "����ѡ�����󣬳����˳�" << endl;
		break;
	}
}


//���
void EmptyContact(struct Contact *pc)
{
	assert(pc != NULL);
	pc->sz = 0;
	printf("Successfully empty\n");
}
