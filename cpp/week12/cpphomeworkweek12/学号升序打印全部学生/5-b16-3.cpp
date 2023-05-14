/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
#define studentNum 10
void input(string studentCode[], string studentName[], int studentScore[], int i)
{
	cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
	cin >> studentCode[i] >> studentName[i] >> studentScore[i];
	return;
}
void selectSort(int studentScore[], string studentCode[], string studentName[])
{
	int i, j, k, t;
	string temp;
	for (i = 0; i < studentNum - 1; i++) {
		k = i;
		for (j = i + 1; j < studentNum; j++)
			if (studentCode[j] < studentCode[k])
				k = j;
		t = studentScore[k];
		studentScore[k] = studentScore[i];
		studentScore[i] = t;
		temp = studentCode[k];
		studentCode[k] = studentCode[i];
		studentCode[i] = temp;
		temp = studentName[k];
		studentName[k] = studentName[i];
		studentName[i] = temp;
	}
	return;
}
void output(int studentScore[], string studentCode[], string studentName[])
{
	int i;
	cout << endl;
	cout << "全部学生(学号升序):"<<endl;
	for (i = 0; i < studentNum; i++)
			cout << studentName[i] << " " << studentCode[i] << " " << studentScore[i] << endl;
	return;
}
int main()
{
	int i, studentScore[studentNum];
	string studentCode[studentNum], studentName[studentNum];
	for (i = 0; i < studentNum; i++)
		input(studentCode, studentName, studentScore, i);

	selectSort(studentScore, studentCode, studentName);
	//冒泡法会使得相同成绩的同学顺序改变
	output(studentScore, studentCode, studentName);
	return 0;
}