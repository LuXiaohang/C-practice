#ifndef USERVECTOR_H
#define USERVECTOR_H
template<typename T>
#define longint long
class userVector{
public:
	userVector() :addrData(NULL), addrsize(0), memberlong(0){ ; };//�޲ι��캯��
	userVector(longint addrsize, longint memberlong);//һ�㹹�캯��
	userVector(const userVector<T>& UV);//���ƹ��캯��
	~userVector();//��������
	struct iterator;
	struct reverse_iterator;
	longint size()const;
	longint capacity()const;
	bool empty();
	T& operator[](unsigned int index);
	iterator& begin();
	iterator& end();
	reverse_iterator& rbegin();
	reverse_iterator& rend();
	T& front();
	T& back();
	T& at(int index);
	void push_back(T insertnum);
	void assign(T a,iterator& begin, iterator& end);
	void pop_back();
	void resize(int a, T b);
	void insert(int x,T elem);
	void clear();
	void swap(userVector<T>& a);
	void erase(iterator seat);
private:
	T ** addrData;
	longint addrsize, memberlong;//addrsize���ȣ�memberlong
	longint intomember;//��vector�е�����
};

//iterator�Ķ���
template<typename T>
struct userVector<T>::iterator{
public:
	iterator(T** head,longint currentAddr, longint currentPos, longint len){
		this->currentAddr = currentAddr;
		this->currentPos = currentPos;
		this->head = head;
		this->lenth = len;
	};
	iterator(const iterator &f){
		this->currentAddr = f.currentAddr;
		this->currentPos = f.currentPos;
		this->lenth = f.lenth;
		this->head = f.head;
	};//���ƹ��캯��
	iterator& operator++(int n){//ǰ��
		if (currentPos  == (lenth - 1)){
			currentAddr++;
			currentPos = 0;
		}
		else//֤�����Ǳ߽�
		{
			currentPos++;
		}
		return *this;
	}
	iterator& operator--(int n){
		if (currentPos == 0){
			currentAddr--;
			currentPos =lenth - 1;
		}
		else//���Ǳ߽�
		{
			currentPos--;
		}
		return *this;
	}
	bool operator!=(const iterator &f){
		return !(currentAddr == f.currentAddr&&currentPos == f.currentPos);
	}
	T& operator*(){
		return *(*(head+currentAddr)+currentPos);
	}
	iterator& operator+(int n){
		int num1 = this->currentAddr+n /lenth;
		int num2 = this->currentPos+n%lenth;
		iterator *tmp = new iterator(head, num1, num2, lenth);
		return *tmp;
	}
	T** head;
	longint currentAddr;
	longint currentPos;
	longint lenth;
};
template<typename T>
struct userVector<T>::reverse_iterator{
public:
	reverse_iterator(T** head, longint currentAddr, longint currentPos, longint len){
		this->currentAddr = currentAddr;
		this->currentPos = currentPos;
		this->head = head;
		this->lenth = len;
	};
	reverse_iterator(const reverse_iterator &f){
		this->currentAddr = f.currentAddr;
		this->currentPos = f.currentPos;
		lenth = f.lenth;
		head = f.head;
	};//���ƹ��캯��
	reverse_iterator& operator--(int n){//ǰ��
		if (currentPos == (lenth - 1)){
			currentAddr++;
			currentPos = 0;
		}
		else//֤�����Ǳ߽�
		{
			currentPos++;
		}
		return *this;
	}
	iterator& operator++(int n){
		if (currentPos == 0){
			currentAddr--;
			currentPos = lenth - 1;
		}
		else//���Ǳ߽�
		{
			currentPos--;
		}
		return *this;
	}
	iterator& operator+(int n){
		for(int i = 0;i<n;i++) this++;
		return *this;
	}
	bool operator!=(const iterator &f){
		return !(currentAddr == f.currentAddr&&currentPos == f.currentPos);
	}
	T& operator*(){
		return *(*(head + currentAddr) + currentPos);
	}
	T** head;
	longint currentAddr;
	longint currentPos;
	longint lenth;
};

//���캯��
template<typename T>
userVector<T>::userVector(longint addrsize, longint memberlong){
	this->addrsize = addrsize;
	this->memberlong = memberlong;
	this->addrData = new T*[this->addrsize];
	for (int i = 0; i < addrsize;i++)
	this->addrData[i] = new T[this->memberlong];
	this->intomember = 0;
};//����
//���ƹ��캯��
template<typename T>
userVector<T>::userVector(const userVector<T>& UV){
	this->addrsize = UV.addrsize;
	this->memberlong = UV.memberlong;
	this->intomember = UV.intomember;
	this->addrData = new T*[this->addrsize];
	for (int i = 0; i < addrsize;i++)
	this->addrData[i] = new T[this->memberlong]
		for (iterator p = UV.begin(); p != UV.end(); p++) push_back(*(p.currentPos));
};
//��������
template<typename T>
userVector<T>::~userVector(){
	for (int i = 0; i<this->addrsize; i++) delete[] *(addrData+i);
	delete[] addrData;
	intomember = 0;
};

//capacity()
template<typename T>
longint userVector<T>::capacity()const{
	return (this->addrsize*this->memberlong);
};

//size()
template<typename T>
longint userVector<T>::size()const{
	return intomember;
};

//front()����
template<typename T>
T& userVector<T>::front(){
	return *(*addrData);
};
//empty()����
template<typename T>
bool userVector<T>::empty(){
	return (this->intomember == 0);
};
//back()����
template<typename T>
T& userVector<T>::back(){
	if (this->intomember == 0){};
	int num1= this->intomember / (this->memberlong);
	int num2 = this->intomember % (this->memberlong)-1;
	if (num2< 0)//�����10������a=0,b=9;
	{
		num1--;
		num2 += this->memberlong;
	};
	return *(*(this->addrData +num1) + num2);
};
//���������
template<typename T>
T& userVector<T>::operator[](unsigned int index){
	int a = index / (this->memberlong);
	int b = index % (this->memberlong);
	return *(*(this->addrData + a) + b);//�ٸ����ӣ�����ǡ�2��������Ϊ10����ôa=0;b=2
};
//at()����
template<typename T>
T& userVector<T>::at(int index){
	return (*this)[index];
};
//rend()����
template<typename T>
typename userVector<T>::reverse_iterator& userVector<T>::rend(){
	return *(new userVector<T>::reverse_iterator(addrData, 0, 0, this->memberlong));
};
//rbegin()����
template<typename T>
typename userVector<T>::reverse_iterator&  userVector<T>::rbegin(){//���Ϊ10����
	int a = intomember / memberlong;
	int b = intomember%memberlong;
	//cout << "(" << a << "," << b << ")" << endl;
	return *(new  userVector<T>::reverse_iterator(addrData, a, b, this->memberlong));
};
//begin()����
template<typename T>
typename userVector<T>::iterator& userVector<T>::begin(){
	return *(new userVector<T>::iterator(addrData, 0, 0, this->memberlong));
};
//end()����
template<typename T>
typename userVector<T>::iterator& userVector<T>::end(){//���Ϊ10����,��10������֮���λ��
	int a = intomember / memberlong;
	int b = intomember%memberlong;
	//cout << "(" << a << "," << b << ")" << endl;
	return *(new  userVector<T>::iterator(addrData, a, b, this->memberlong));
};


//resize()����
template<typename T>
void userVector<T>::resize(int a, T b=0){
	if (a <this->intomember)
	{
		intomember = a;
	}
	else{
		if (a>=(this->capacity()))//��������ܹ����ɻ���
		{
			userVector<T>::iterator tmp1 = this->end();
			intomember = a;
			userVector<T>::iterator tmp2 = this->end();
			this->addrsize *= 2;
			T** tmp;
			tmp= this->addrData;
			this->addrData = new T*[addrsize];
			for (int i = 0; i < addrsize / 2; i++){
				*(this->addrData + i) = *(tmp + i);
			};
			for (int i = addrsize / 2; i < addrsize ; i++){
				*(this->addrData + i)= new T[this->memberlong];
			}
			delete[]tmp;
			tmp1.head = addrData;
			tmp2.head = addrData;
			this->assign(b,tmp1,tmp2);
	
		}
		else
		{
			userVector<T>::iterator tmp1 = this->end();
			intomember = a;
			userVector<T>::iterator tmp2 = this->end();
			//if (this->end() != tmp1)
				//cout << "�������" << endl;
			this->assign(b, tmp1, tmp2);
		
		}
	}
};
//swap����
template<typename T>
void userVector<T>::swap(userVector<T>& a){
	T** tmp1 = this->addrData;
	this->addrData=a.addrData;
	a.addrData = tmp1;
	longint  tmp2 =this-> addrsize;
	longint tmp3 = this->memberlong;
	longint tmp4 = this->intomember;
	this->addrsize = a.addrsize;
	this->memberlong = a.memberlong;
	this->intomember = a.intomember;
	a.addrsize = tmp2;
	a.memberlong = tmp3;
	a.intomember=tmp4;
}
//assign()����
template<typename T>
typename void userVector<T>::assign(T a, iterator& begin, iterator& end){
	for (userVector<T>::iterator i = begin; i != end; i++){
		*i = a;
		//cout << *i << endl;
	}
}
template<typename T>//���������ˣ������Ḳ�Ǻ����ֵ��...
typename void userVector<T>::clear(){
	intomember = 0;
};
template<typename T>
typename void userVector<T>::insert(int index, T elem){//����ֱ�ӱ�ʾΪ[index]��
	int num1 = index / memberlong;
	int num2 = index%memberlong;
	userVector<T>::iterator my = this->begin()+index;
	this->push_back(elem);
	userVector<T>::iterator i = (this->end()--) ;
	i--;
	userVector<T>::iterator my1 = begin() + index;
	for (;i != my1; i--){
		*(i+1)= *i;
	}
	*(i + 1) = *i;
	*my1 = elem;
}
//pushback()����
template<typename T>
void userVector<T>::push_back(T insertnum){
	resize(size() + 1, insertnum);
};
//popback()����
template<typename T>
void userVector<T>::pop_back(){
	if(this->intomember == 0) cout<<"û�п�ɾ��������"<<endl;
	else this->intomember -= 1;
};
//erase()����
template<typename T>
void userVector<T>::erase(iterator seat){
	for(iterator i=seat;i!=--this->end();i++){
		*i=*(i+1);
	}
}

#endif