#include<iostream>
using namespace std;
#include"userVector.h"
int main(){
	int uvSize = 5, uvLong = 20;
	userVector<int> myuv(uvSize, uvLong);
	for (int i = 0; i<99; i++) myuv.push_back(i);
	cout<<"Ϊmyuv������ֵ0��99"<<endl;
	cout << "myuv�����ݶ���" << myuv.size() << "��" << endl;
	cout << "��myuvĩβ������һ��Ԫ��100" << endl;
	myuv.push_back(100);
	cout << "myuv�Ƿ�Ϊ��" << myuv.empty() << endl;
	cout << "myuv����������" << myuv.size() << "��" << endl;
	cout << "myuv�����ɵ���������" << myuv.capacity() << "��" << endl;
	cout<<"���myuv"<<endl;
	for (int i = 0; i<myuv.size(); i++) cout << myuv[i]<<" ";
	cout << endl;
	cout << "�������myuvһ��λ��" << myuv.at(rand() % 100) << endl;
	cout << "����myuv��һ��Ԫ��" << myuv.front() << endl;
	cout << "����myuv��βԪ��" << myuv.back() << endl;
	myuv.pop_back();
	myuv.pop_back();
	myuv.pop_back();//ɾ���������Ԫ��
	cout<<"ʹ��pop_back����ɾ��myuv�������Ԫ��"<<endl;
	cout << "myuv�����ݶ���" << myuv.size() << "��" << endl;
	cout << "ɾ���������Ԫ�غ����myuv�Ľ�βԪ��" << myuv.back() << endl;
	cout<<"���myuv"<<endl;
	for (int i = 0; i<myuv.size(); i++) cout << myuv[i] << " ";
	cout << endl;
	cout << "��myuv����һ��λ�ò���Ԫ��" << endl;
	int pos = 2;
	myuv.insert(pos, rand() % 100);//������һ��λ�ò���һ����Ԫ��
	cout<<"���myuv"<<endl;
	for(int i = 0; i<myuv.size(); i++) cout << myuv[i] << " ";
	cout<<endl;
	myuv.assign(1,myuv.begin(),myuv.end());
	cout<<"��assign����Ϊmyuv��ֵ"<<endl;
	for (int i = 0; i<myuv.size(); i++) cout << myuv[i]<<" ";
	cout<<endl;
	myuv.resize(myuv.size() + 1, 2);
	cout<<"��resize������myuv��β���Ԫ��2"<<endl;
	for (int i = 0; i<myuv.size(); i++) cout << myuv[i]<<" ";
	cout<<endl;
	/*myuv.erase(userVector<int>::iterator i = (myuv.begin()+rand()%100));
	cout<<"��erase��������ɾ��myuv��һ��Ԫ��"<<endl;
	cout<<"���myuv"<<endl;
	for(int i = 0; i<myuv.size(); i++) cout << myuv[i] << " ";*/
	userVector<int> myuv2(10, 11);
	/*cout<<"����һ���µ�myuv2������myuv��swap����"<<endl;
	myuv.swap(myuv2);
	cout<<"���myuv"<<endl;
	for (int i = 0; i<myuv.size(); i++) cout << myuv[i]<<" ";*/
	myuv.clear();//�Ƴ�myuv�����г�Ա����
	cout<<"���myuv������Ԫ��"<<endl;
	cout << "myuv�Ƿ�Ϊ��" << myuv.empty() << endl;
	cout << "����" << endl;

	//����iterator
	for (userVector<int>::iterator i = myuv.begin(); i != myuv.end(); i++){
		cout << *i << " ";
	}
	/*userVector<int> hisuv(myuv);
	for (iterator i = hisuv.rbegin; i != hisuv.rend; i--){
		cout << *i << " ";
	}*/

	system("pause");

};
