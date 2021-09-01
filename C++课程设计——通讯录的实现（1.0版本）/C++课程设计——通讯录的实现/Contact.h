#include<iostream>
#include<string>
#include<assert.h>
#include<iomanip>

#define MAX 1000     //�궨��ͨѶ¼�������
using namespace std;



//����һ����ϵ�˵���Ϣ�Ľṹ��
struct PeoInfo
{
	string _name;
	string _department;
	string _class;
	string _telephone;
	string _email;
	string _address;
	string _postcode;
};


//ͨѶ¼��Ϣ�Ľṹ��
struct Contact
{
	//ͨѶ¼���1000������Ϣ�Ŀռ�
	struct PeoInfo data[MAX];
	//ͨѶ¼��ǰ��ŵ�����Ϣ����
	int sz;
};


//**********************************************************************
//*********************************************************************
//����������

//��ʼ��ͨѶ¼
void InitContact(struct Contact *pc);

//����һ���˵���Ϣ
void AddContact(struct Contact *pc);

//��ʾһ���˵���Ϣ
void ShowContact(const struct Contact *pc);

//ɾ��һ���˵���Ϣ
void DelContact(struct Contact *pc);
       //ͨ������ɾ��
        void DelContactByName(struct Contact *pc, string Name);
       //ͨ��Ժϵɾ��
        void DelContactByDepartment(struct Contact *pc, string Department);
       //ͨ���༶ɾ��
        void DelContactByClass(struct Contact *pc, string Class);
       //ͨ���绰ɾ��
        void DelContactByTelephone(struct Contact *pc, string Telephone);
       //ͨ������ɾ��
        void DelContactByEmail(struct Contact *pc, string Email);
       //ͨ����ַɾ��
        void DelContactByAddress(struct Contact *pc, string Address);
       //ͨ���ʱ�ɾ��
        void DelContactByPostcode(struct Contact *pc, string Postcode);


//����ָ����ϵ��
void SearchContact(struct Contact *pc);
      //ͨ����������
      int SearchContactByName(struct Contact *pc,string Name);
      //ͨ��Ժϵ����
	  int SearchContactByDepartment(struct Contact *pc,string Department);
      //ͨ���༶����
	  int SearchContactByClass(struct Contact *pc, string Class);
      //ͨ���绰����
	  int SearchContactByTelephone(struct Contact *pc, string Telephone);
      //ͨ���������
	  int SearchContactByEmail(struct Contact *pc, string Email);
      //ͨ����ַ����
	  int SearchContactByAddress(struct Contact *pc, string Address);
      //ͨ���ʱ����
	  int SearchContactByPostcode(struct Contact *pc, string Postcode); 


//�޸���Ϣ
void ModifyContact(struct Contact *pc);


//����
void SortContact(struct Contact *pc);
      //ͨ����������
      void SortContactByName(struct Contact *pc);
      //ͨ��Ժϵ����
      void SortContactByDepartment(struct Contact *pc);
      //ͨ���༶����
      void SortContactByClass(struct Contact *pc);
      //ͨ���绰����
      void SortContactByTelephone(struct Contact *pc);
      //ͨ����������
      void SortContactByEmail(struct Contact *pc);
      //ͨ����ַ����
      void SortContactByAddress(struct Contact *pc);
       //ͨ���ʱ�����
      void SortContactByPostcode(struct Contact *pc);


//���
void EmptyContact(struct Contact *pc);
