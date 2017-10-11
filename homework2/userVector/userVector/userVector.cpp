#include<iostream>
using namespace std;
#include"userVector.h"
int main(){
	int uvSize = 5, uvLong = 20;
	userVector<int> myuv(uvSize, uvLong);
	for (int i = 0; i<99; i++) myuv.push_back(i);
	cout<<"为myuv函数赋值0至99"<<endl;
	cout << "myuv的数据段有" << myuv.size() << "个" << endl;
	cout << "在myuv末尾插入了一个元素100" << endl;
	myuv.push_back(100);
	cout << "myuv是否为空" << myuv.empty() << endl;
	cout << "myuv的数据量有" << myuv.size() << "个" << endl;
	cout << "myuv可容纳的数据量有" << myuv.capacity() << "个" << endl;
	cout<<"输出myuv"<<endl;
	for (int i = 0; i<myuv.size(); i++) cout << myuv[i]<<" ";
	cout << endl;
	cout << "随意访问myuv一个位置" << myuv.at(rand() % 100) << endl;
	cout << "访问myuv第一个元素" << myuv.front() << endl;
	cout << "访问myuv结尾元素" << myuv.back() << endl;
	myuv.pop_back();
	myuv.pop_back();
	myuv.pop_back();//删除最后三个元素
	cout<<"使用pop_back函数删除myuv最后三个元素"<<endl;
	cout << "myuv的数据段有" << myuv.size() << "个" << endl;
	cout << "删除最后三个元素后访问myuv的结尾元素" << myuv.back() << endl;
	cout<<"输出myuv"<<endl;
	for (int i = 0; i<myuv.size(); i++) cout << myuv[i] << " ";
	cout << endl;
	cout << "在myuv随意一个位置插入元素" << endl;
	int pos = 2;
	myuv.insert(pos, rand() % 100);//在随意一个位置插入一个新元素
	cout<<"输出myuv"<<endl;
	for(int i = 0; i<myuv.size(); i++) cout << myuv[i] << " ";
	cout<<endl;
	myuv.assign(1,myuv.begin(),myuv.end());
	cout<<"用assign函数为myuv赋值"<<endl;
	for (int i = 0; i<myuv.size(); i++) cout << myuv[i]<<" ";
	cout<<endl;
	myuv.resize(myuv.size() + 1, 2);
	cout<<"用resize函数在myuv结尾添加元素2"<<endl;
	for (int i = 0; i<myuv.size(); i++) cout << myuv[i]<<" ";
	cout<<endl;
	/*myuv.erase(userVector<int>::iterator i = (myuv.begin()+rand()%100));
	cout<<"用erase函数随意删除myuv的一个元素"<<endl;
	cout<<"输出myuv"<<endl;
	for(int i = 0; i<myuv.size(); i++) cout << myuv[i] << " ";*/
	userVector<int> myuv2(10, 11);
	/*cout<<"定义一个新的myuv2，调用myuv的swap函数"<<endl;
	myuv.swap(myuv2);
	cout<<"输出myuv"<<endl;
	for (int i = 0; i<myuv.size(); i++) cout << myuv[i]<<" ";*/
	myuv.clear();//移除myuv中所有成员数据
	cout<<"清除myuv中所有元素"<<endl;
	cout << "myuv是否为空" << myuv.empty() << endl;
	cout << "结束" << endl;

	//检验iterator
	for (userVector<int>::iterator i = myuv.begin(); i != myuv.end(); i++){
		cout << *i << " ";
	}
	/*userVector<int> hisuv(myuv);
	for (iterator i = hisuv.rbegin; i != hisuv.rend; i--){
		cout << *i << " ";
	}*/

	system("pause");

};
