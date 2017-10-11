#include<iostream>
#include<math.h>
using namespace std;

template<class T>                                        //选择排序
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
	/* 下面是不同类型的构造函数 */
	Fraction()                                           //无参构造函数
	{
		this->Up = 0;
		this->Down = 1;
	}
	Fraction(double U)                                  //单实数构造函数,保留三位小数,因为小数位数多了意义不大
	{
		int a =(int)U;
		int b = (int)((U-a)*1000);
		int c = GCD(a*1000+b,1000);
		this->Up = (a*1000+b)/c;
		this->Down = 1000/c;
	}
	Fraction(int U, int D)                             //双参数构造函数
	{
		this->Up = U;
		if(D != 0) this->Down = D;
		else 
		{
			cout << "分母为零请重输"<< endl;
			this->Down = 1;
		}
	}
	/* 下面按照顺序实现++、+、-、【】、=、==、<、《 */
	Fraction& operator++()                            // 重载单目运算符++ 前增
	{
		this->Up = this->Up+this->Down;
		return *this;
	}
	Fraction operator++(int nothing)                  // 重载单目运算符++ 后增
	{
		Fraction temp(this->Up,this->Down);
		this->Up = this->Up+this->Down;
		return temp;
	}
	friend Fraction operator+(Fraction L,Fraction R); // 重载双目运算符 +
	friend Fraction operator-(Fraction L,Fraction R); // 重载双目运算符 -
	int operator[](Fraction &temp)                    // 重载单目运算符【】取整
	{
		double c = temp.Up/temp.Down;
		return ceil(c);
	}
	Fraction& operator=(double U)                     // 重载运算符 = 
	{
		Fraction temp(U);
		*this = temp;
		return *this;
	}
	bool operator==(const Fraction &temp)             // 重载运算符 ==
	{
		if(this->Up==temp.Up&&this->Down==temp.Down) return true;
		else return false;
	}
	bool operator<(const Fraction &temp)              // 重载运算符 <
	{
		if(this->Up*temp.Down<this->Down*temp.Up) return true;
		else return false;
	}
	bool operator>(const Fraction &temp)              // 重载运算符 >
	{
		if(this->Up*temp.Down>this->Down*temp.Up) return true;
		else return false;
	}
	friend ostream& operator<<(ostream &output,Fraction&temp);//重载流插入运算符
	void print()
	{
		int numGCD = GCD(this->Up,this->Down);
		if(this->Down==0) cout << "分数无意义" <<endl;
		else if (this->Up==0) cout << 0 <<endl;
		else cout << this->Up/numGCD << "/" << this->Down/numGCD <<endl;
	}
private:
	int Up;      //分子
	int Down;    //分母
	int GCD(int leftNum, int rightNum)               //辗转相除法求最大公约数
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