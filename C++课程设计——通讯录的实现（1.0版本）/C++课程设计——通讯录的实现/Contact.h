#include<iostream>
#include<string>
#include<assert.h>
#include<iomanip>

#define MAX 1000     //宏定义通讯录最大容量
using namespace std;



//存有一个联系人的信息的结构体
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


//通讯录信息的结构体
struct Contact
{
	//通讯录存放1000个人信息的空间
	struct PeoInfo data[MAX];
	//通讯录当前存放的人信息条数
	int sz;
};


//**********************************************************************
//*********************************************************************
//函数的声明

//初始化通讯录
void InitContact(struct Contact *pc);

//增加一个人的信息
void AddContact(struct Contact *pc);

//显示一个人的信息
void ShowContact(const struct Contact *pc);

//删除一个人的信息
void DelContact(struct Contact *pc);
       //通过姓名删除
        void DelContactByName(struct Contact *pc, string Name);
       //通过院系删除
        void DelContactByDepartment(struct Contact *pc, string Department);
       //通过班级删除
        void DelContactByClass(struct Contact *pc, string Class);
       //通过电话删除
        void DelContactByTelephone(struct Contact *pc, string Telephone);
       //通过邮箱删除
        void DelContactByEmail(struct Contact *pc, string Email);
       //通过地址删除
        void DelContactByAddress(struct Contact *pc, string Address);
       //通过邮编删除
        void DelContactByPostcode(struct Contact *pc, string Postcode);


//查找指定联系人
void SearchContact(struct Contact *pc);
      //通过姓名查找
      int SearchContactByName(struct Contact *pc,string Name);
      //通过院系查找
	  int SearchContactByDepartment(struct Contact *pc,string Department);
      //通过班级查找
	  int SearchContactByClass(struct Contact *pc, string Class);
      //通过电话查找
	  int SearchContactByTelephone(struct Contact *pc, string Telephone);
      //通过邮箱查找
	  int SearchContactByEmail(struct Contact *pc, string Email);
      //通过地址查找
	  int SearchContactByAddress(struct Contact *pc, string Address);
      //通过邮编查找
	  int SearchContactByPostcode(struct Contact *pc, string Postcode); 


//修改信息
void ModifyContact(struct Contact *pc);


//排序
void SortContact(struct Contact *pc);
      //通过姓名排序
      void SortContactByName(struct Contact *pc);
      //通过院系排序
      void SortContactByDepartment(struct Contact *pc);
      //通过班级排序
      void SortContactByClass(struct Contact *pc);
      //通过电话排序
      void SortContactByTelephone(struct Contact *pc);
      //通过邮箱排序
      void SortContactByEmail(struct Contact *pc);
      //通过地址排序
      void SortContactByAddress(struct Contact *pc);
       //通过邮编排序
      void SortContactByPostcode(struct Contact *pc);


//清空
void EmptyContact(struct Contact *pc);
