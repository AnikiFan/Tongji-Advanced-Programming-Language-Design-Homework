/* 2254298 ��11 ���� */
#include<iostream>//TODO:������Ҫ�����ͣ���������������͵Ĵ���
#include<cmath>
using namespace std;//TODO:�겻�������ͷ�Χ���κκ������;���Ϊ��ȷ�������������������ֻ�ж��Ƿ�����
int main()
{
	int year, month, day;
	cout << "�������꣬�£���" << endl;//TODO:����Ϊ����ȫ��
	cin >> year >> month >> day;
	if (month > 0 && month <= 12) {//�ж��·��Ƿ�Ϸ�
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {//���������
			if (month == 2 && !(1 <= day && day <= 29) ||
				month == 1 && !(1 <= day && day <= 31) ||
				month == 3 && !(1 <= day && day <= 31) ||
				month == 5 && !(1 <= day && day <= 31) ||
				month == 7 && !(1 <= day && day <= 31) ||
				month == 8 && !(1 <= day && day <= 31) ||
				month == 10 && !(1 <= day && day <= 31) ||
				month == 12 && !(1 <= day && day <= 31) ||
				month == 4 && !(1 <= day && day <= 30) ||
				month == 6 && !(1 <= day && day <= 30) ||
				month == 9 && !(1 <= day && day <= 30) ||
				month == 11 && !(1 <= day && day <= 30))

				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			else
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�"
				<< month / 2 * 31 + (month - 1) / 2 * 30 - int(month >= 3) * 1 + int(month >= 9) * 1 - int(month >= 10) * 1 + int(month >= 11) * 1 - int(month >= 12) * 1 + int(month >= 13) * 1 + day
				<< "��" << endl;//TODO:�м��޿ո�,-ΪӢ�İ��
		}
		else {//��������
			if (month == 2 && !(1 <= day && day <= 28) ||
				month == 1 && !(1 <= day && day <= 31) ||
				month == 3 && !(1 <= day && day <= 31) ||
				month == 5 && !(1 <= day && day <= 31) ||
				month == 7 && !(1 <= day && day <= 31) ||
				month == 8 && !(1 <= day && day <= 31) ||
				month == 10 && !(1 <= day && day <= 31) ||
				month == 12 && !(1 <= day && day <= 31) ||
				month == 4 && !(1 <= day && day <= 30) ||
				month == 6 && !(1 <= day && day <= 30) ||
				month == 9 && !(1 <= day && day <= 30) ||
				month == 11 && !(1 <= day && day <= 30))
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			else
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�"
				<< month / 2 * 31 + (month - 1) / 2 * 30 - int(month >= 3) * 2 + int(month >= 9) * 1 - int(month >= 10) * 1 + int(month >= 11) * 1 - int(month >= 12) * 1 + int(month >= 13) * 1 + day
				<< "��" << endl;//TODO:�м��޿ո�,-ΪӢ�İ��
		}
	}
	else
		cout << "�������-�·ݲ���ȷ" << endl;//TODO:�������ͬʱ�������ж��£�����˾�
	return 0;
}