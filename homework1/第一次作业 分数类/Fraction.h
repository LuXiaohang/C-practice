#include<iostream>
#include<math.h>
using namespace std;

template<class T>                                        //ѡ������
void SelectSort(T *arr, int n){
	T temp;
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<=n-1;j++)
		{
			if(arr[j]<arr[k]) k=j;
		}
		if(k!=i)
		{
			temp=arr[i];
			arr[i]=arr[k];
			arr[k]=temp;
		}
	}
};


class Fraction
{
public:
	/* �����ǲ�ͬ���͵Ĺ��캯�� */
	Fraction()                                           //�޲ι��캯��
	{
		this->Up = 0;
		this->Down = 1;
	}
	Fraction(double U)                                  //��ʵ�����캯��,������λС��,��ΪС��λ���������岻��
	{
		int a =(int)U;
		int b = (int)((U-a)*1000);
		int c = GCD(a*1000+b,1000);
		this->Up = (a*1000+b)/c;
		this->Down = 1000/c;
	}
	Fraction(int U, int D)                             //˫�������캯��
	{
		this->Up = U;
		if(D != 0) this->Down = D;
		else 
		{
			cout << "��ĸΪ��������"<< endl;
			this->Down = 1;
		}
	}
	/* ���水��˳��ʵ��++��+��-��������=��==��<���� */
	Fraction& operator++()                            // ���ص�Ŀ�����++ ǰ��
	{
		this->Up = this->Up+this->Down;
		return *this;
	}
	Fraction operator++(int nothing)                  // ���ص�Ŀ�����++ ����
	{
		Fraction temp(this->Up,this->Down);
		this->Up = this->Up+this->Down;
		return temp;
	}
	friend Fraction operator+(Fraction L,Fraction R); // ����˫Ŀ����� +
	friend Fraction operator-(Fraction L,Fraction R); // ����˫Ŀ����� -
	int operator[](Fraction &temp)                    // ���ص�Ŀ���������ȡ��
	{
		double c = temp.Up/temp.Down;
		return ceil(c);
	}
	Fraction& operator=(double U)                     // ��������� = 
	{
		Fraction temp(U);
		*this = temp;
		return *this;
	}
	bool operator==(const Fraction &temp)             // ��������� ==
	{
		if(this->Up==temp.Up&&this->Down==temp.Down) return true;
		else return false;
	}
	bool operator<(const Fraction &temp)              // ��������� <
	{
		if(this->Up*temp.Down<this->Down*temp.Up) return true;
		else return false;
	}
	bool operator>(const Fraction &temp)              // ��������� >
	{
		if(this->Up*temp.Down>this->Down*temp.Up) return true;
		else return false;
	}
	friend ostream& operator<<(ostream &output,Fraction&temp);//���������������
	void print()
	{
		int numGCD = GCD(this->Up,this->Down);
		if(this->Down==0) cout << "����������" <<endl;
		else if (this->Up==0) cout << 0 <<endl;
		else cout << this->Up/numGCD << "/" << this->Down/numGCD <<endl;
	}
private:
	int Up;      //����
	int Down;    //��ĸ
	int GCD(int leftNum, int rightNum)               //շת����������Լ��
	{
		if(leftNum==0||rightNum==0) return 1;
		if(leftNum<rightNum) return GCD(rightNum,leftNum);
		if(leftNum%rightNum != 0) return GCD(rightNum,leftNum%rightNum);
		else return rightNum;
	}
};

Fraction operator+(Fraction L,Fraction R)
{
	Fraction temp;
	temp.Up = L.Up*R.Down+L.Down*R.Up;
	temp.Down = L.Down*R.Down;
	int c =L.GCD(temp.Up,temp.Down);
	temp.Up = temp.Up/c;
	temp.Down = temp.Down/c;
	return temp;
};
Fraction operator-(Fraction L,Fraction R)
{
	Fraction temp;
	temp.Up = L.Up*R.Down-L.Down*R.Up;
	temp.Down = L.Down*R.Down;
	int c = L.GCD(temp.Up,temp.Down);
	temp.Up = temp.Up/c;
	temp.Down = temp.Down/c;
	return temp;
};
ostream& operator<<(ostream &output,Fraction&temp)
{
	output << temp.Up << "/" << temp.Down <<endl;
	return output;
}