/* 2254298 信11 范潇 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
#include<string.h>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//定义文件名的最大长度
#define NoLength 5
#define codeLength 9
#define nameLength 32
#define roundLength 7
#define roundOneLength roundLength
#define roundTwoLength roundLength
#define seperatorLength (NoLength +codeLength +nameLength+roundOneLength+roundTwoLength)
#define seperator 	cout << setw(seperatorLength) << setfill('=')<<"=" << setfill(' ') << endl;
/* stu_metge 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_merge {
private:
	int  stu_no;					//学号
	char stu_name[MAX_NAME_LEN];  //姓名

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	friend  class stu_list;
	bool round1 = 0;
	bool round2 = 0;


public:
	//本类不允许定义任何的公有数据成员及成员函数
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//第一轮选课的学生名单（不排序、不去重）
	int list_num_1;						//第一轮选课的学生人数

	student list_round_2[MAX_STU_NUM];	//第二轮选课的学生名单（不排序、不去重）
	int list_num_2;						//第二轮选课的学生人数

	stu_merge list_merge[MAX_STU_NUM];	//合并后的学生名单（去重，按升序排列）
	int list_merge_num;					//合并后的学生人数（目前不打印，但可用于内部管理，如果不需要，也不要删除）

	/* 允许按需加入private数据成员和成员函数
	   注意，不允许加入array / set / map / vector等STL容器 */





public:
	stu_list();										//构造函数，按需完成初始化功能，如果不需要，保留空函数即可
	int read(const char* filename, const int round);	//从文件中读入选课信息，round为1/2，表示选课轮次
	void print(const char* prompt = NULL);				//打印最终的选课名单

	/* 允许按需加入其它public成员函数（提示：合并、去重、排序等）
	   不允许定义公有的数据成员
	   不允许在成员函数中使用array / set / map / vector等STL容器 */
	void merge();








};

/* --- 下面可以给出stu_merge/stu_list两个类的成员函数的体外实现 --- */

/***************************************************************************
  函数名称：
  功    能：从文件中读入选课信息，round为1/2，表示选课轮次
  输入参数：
  返 回 值：
  说    明：构造函数，按需完成初始化功能，如果不需要，保留空函数即可
***************************************************************************/
stu_list::stu_list()
{

}

void stu_list::merge()
{
	student* p1 = list_round_1;
	student* p2 = list_round_2;
	stu_merge* p = list_merge;
	stu_merge temp;
	temp.stu_no = p1->no;
	strcpy(temp.stu_name, p1->name);
	p->stu_no = p1->no;
	strcpy(p->stu_name, p1->name);
	p->round1 = 1;
	while (p1 - list_round_1 < list_num_1) {
		if (p1->no != temp.stu_no) {
			p->stu_no = temp.stu_no;
			strcpy(p->stu_name, temp.stu_name);
			p->round1 = 1;
			p++;
			temp.stu_no = p1->no;
			strcpy(temp.stu_name, p1->name);
		}
		p1++;
	}
	if ((p - 1)->stu_no != (p1 - 1)->no) {
		p->stu_no = temp.stu_no;
		strcpy(p->stu_name, temp.stu_name);
		p->round1 = 1;
		p++;
	}
	temp.stu_no = p2->no;
	strcpy(temp.stu_name, p2->name);
	p->stu_no = p2->no;
	strcpy(p->stu_name, p2->name);
	p->round2 = 1;
	//cout << p->stu_name << endl << endl;
	while (p2 - list_round_2 < list_num_2) {
		if (p2->no != temp.stu_no) {
			p->stu_no = temp.stu_no;
			strcpy(p->stu_name, temp.stu_name);
			p->round2 = 1;
			p++;
			temp.stu_no = p2->no;
			strcpy(temp.stu_name, p2->name);
		}
		p2++;
	}
	if ((p - 1)->stu_no != (p2 - 1)->no) {
		p->stu_no = temp.stu_no;
		strcpy(p->stu_name, temp.stu_name);
		p->round2 = 1;
		p++;
	}
//	cout << (p-1)->stu_name << endl << endl;
	//此时每一轮中无重复,但两轮中仍有重复
	list_merge_num = p - list_merge;
	int i, j, k;
	char nametemp[MAX_NAME_LEN];
	int notemp, roundtemp1, roundtemp2;
	for (i = 0; i < list_merge_num - 1; i++) {
		k = i;
		for (j = i + 1; j < list_merge_num; j++)
			if (list_merge[j].stu_no < list_merge[k].stu_no)
				k = j;
		notemp = list_merge[k].stu_no;
		list_merge[k].stu_no = list_merge[i].stu_no;
		list_merge[i].stu_no = notemp;
		strcpy(nametemp, list_merge[k].stu_name);
		strcpy(list_merge[k].stu_name, list_merge[i].stu_name);
		strcpy(list_merge[i].stu_name, nametemp);
		roundtemp1 = list_merge[k].round1;
		list_merge[k].round1 = list_merge[i].round1;
		list_merge[i].round1 = roundtemp1;
		roundtemp2 = list_merge[k].round2;
		list_merge[k].round2 = list_merge[i].round2;
		list_merge[i].round2 = roundtemp2;
	}
	//排序
	return;
}







/***************************************************************************
  函数名称：
  功    能：演示静态链接库的使用，本函数中调用静态链接库中的预置函数
  输入参数：
  返 回 值：
  说    明：本函数不需要修改
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* 读取第1/2轮的选课名单并打印 */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("第一轮选课名单：", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("第二轮选课名单：", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：打印最终的选课名单
***************************************************************************/
void stu_list::print(const char* prompt)
{
	int sum = 1;
	cout << prompt << endl;
	seperator
		cout << setw(NoLength) << setiosflags(ios::left) << "序号"
		<< setw(codeLength) << "学号"
		<< setw(nameLength) << "姓名"
		<< setw(roundOneLength) << "第一轮"
		<< setw(roundTwoLength) << "第二轮" << endl;
	seperator
		stu_merge* p = list_merge;
	//cout << p->stu_name << endl << endl;
	for (; p - list_merge < list_merge_num; p++) {
		if (p->stu_no == 0) {
			seperator
				return;
		}
		else if (p - list_merge == list_merge_num - 1) {
			cout << setw(NoLength) << sum << setw(codeLength) << p->stu_no << setw(nameLength) << p->stu_name;
			if (p->round1)
				cout << setw(roundOneLength) << "Y" << setw(roundTwoLength) << "退课" << endl;
			else
				cout << setw(roundTwoLength) << "/" << setw(roundTwoLength) << "补选" << endl;
			seperator
				return;
		}
		else {
			if (p->round1 == 0 && ((p + 1)->stu_no != p->stu_no))
				cout << setw(NoLength) << sum << setw(codeLength) << p->stu_no << setw(nameLength) << p->stu_name << setw(roundTwoLength) << "/" << setw(roundTwoLength) << "补选" << endl;
			else if ((p + 1)->stu_no == p->stu_no) {
				cout << setw(NoLength) << sum << setw(codeLength) << p->stu_no << setw(nameLength) << p->stu_name << setw(roundTwoLength) << "Y" << setw(roundTwoLength) << "Y" << endl;
				p++;
			}
			else
				cout << setw(NoLength) << sum << setw(codeLength) << p->stu_no << setw(nameLength) << p->stu_name << setw(roundTwoLength) << "Y" << setw(roundTwoLength) << "退课" << endl;
			sum++;
		}
	}
	seperator
		return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1); //cin不能读有空格的文件

	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2);

	stu_list list;

	/* 读入数据 */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* 处理数据 */

	list.merge();

	/* 打印 */
	list.print("最终选课名单");

	return 0;
}

