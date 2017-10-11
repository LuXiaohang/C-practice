#include<iostream>
#include"Fraction.h"
#include<math.h>

using namespace std;

//检验Fraction里面的函数
int main()
{
	Fraction f1;      //检验无参构造函数     
	Fraction f2(2);   //检验单实数构造函数 单实数为整数
	Fraction f3(3.3); //检验单实数构造函数 单实数为小数
	Fraction f4(4,5); //检验双参数构造函数
	f1.print();
	f2.print();
	f3.print();
	f4.print();
	cout << f4++;     //检验后增
	Fraction f5 = f4;
	cout << f4;
	cout << ++f4;     //检验前增
	cout << f4+f5;    //检验 分数+分数
	cout << f4+2;     //检验 分数+整数
	cout << f4+0.4;   //检验 分数+小数
	cout << 0.4+f4;   //检验 小数+分数
	cout << f4-f2;    //检验 -
	cout << f3[f3] <<endl;  //检验取整【】
	f3 = 3.3;         //检验 =
	f3.print();
	cout << (f3==f4) <<endl;
	cout << (f4==f4) <<endl;
	cout << (f3<f4) <<endl;
	cout << (f3>f4) <<endl;
	int I[3]={1,3,2}; //检验正整数排序
	SelectSort(I,3);
	int i;
	for(i=0;i<3;i++) cout << I[i] <<" ";
	cout << endl;
	Fraction f[3];    //检验分数排序
	f[0]=f3;
	f[1]=f4;
	f[2]=f5;
	SelectSort(f,3);
	for(i=0;i<3;i++) cout << f[i];
	return 0;
}