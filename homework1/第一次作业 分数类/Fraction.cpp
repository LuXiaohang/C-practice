#include<iostream>
#include"Fraction.h"
#include<math.h>

using namespace std;

//����Fraction����ĺ���
int main()
{
	Fraction f1;      //�����޲ι��캯��     
	Fraction f2(2);   //���鵥ʵ�����캯�� ��ʵ��Ϊ����
	Fraction f3(3.3); //���鵥ʵ�����캯�� ��ʵ��ΪС��
	Fraction f4(4,5); //����˫�������캯��
	f1.print();
	f2.print();
	f3.print();
	f4.print();
	cout << f4++;     //�������
	Fraction f5 = f4;
	cout << f4;
	cout << ++f4;     //����ǰ��
	cout << f4+f5;    //���� ����+����
	cout << f4+2;     //���� ����+����
	cout << f4+0.4;   //���� ����+С��
	cout << 0.4+f4;   //���� С��+����
	cout << f4-f2;    //���� -
	cout << f3[f3] <<endl;  //����ȡ������
	f3 = 3.3;         //���� =
	f3.print();
	cout << (f3==f4) <<endl;
	cout << (f4==f4) <<endl;
	cout << (f3<f4) <<endl;
	cout << (f3>f4) <<endl;
	int I[3]={1,3,2}; //��������������
	SelectSort(I,3);
	int i;
	for(i=0;i<3;i++) cout << I[i] <<" ";
	cout << endl;
	Fraction f[3];    //�����������
	f[0]=f3;
	f[1]=f4;
	f[2]=f5;
	SelectSort(f,3);
	for(i=0;i<3;i++) cout << f[i];
	return 0;
}