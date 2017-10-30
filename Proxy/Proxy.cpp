#include <iostream>

using namespace std;

class Subject
{
public:
	virtual void request()=0;
	virtual ~Subject(){};
};

class RealSubject:public Subject
{
public:
	void request()
	{
		cout <<"RealSubject.request()"<<endl;
	}
};

class Proxy:public Subject 
{
private:
	Subject * m_sub;
public:
	Proxy():m_sub(new RealSubject()){}
	~Proxy()
	{
		delete m_sub;
	}

	void request()
	{
		cout <<"client is calling a requst"<<endl;
		m_sub->request();
	}
};

int main()
{
	Proxy p;
	p.request();
}