 #include "Product.hpp"
#ifndef FACTORY_H_
#define FACTORY_H_

class Factory{
public:
	virtual Laptop* produceLaptop(){}
	virtual MobilePhone* produceMobilePhone(){}
	virtual ~Factory(){}
};

class AppleFactory : public Factory{
private:
	Laptop* mac;
	MobilePhone* iphone;
public:
	AppleFactory(){
		mac = new Laptop(0);
		iphone = new MobilePhone(0);
	}
	Laptop* produceLaptop(){
		return mac;
	}
	MobilePhone* produceMobilePhone(){
		return iphone;
	}
	~AppleFactory(){}
};

class XiaomiFactory : public Factory{
private:
	Laptop* mini;
	MobilePhone* miphone;
public:
	XiaomiFactory(){
		mini = new Laptop(1);
		miphone = new MobilePhone(1);
	}
	Laptop* produceLaptop(){
		return mini;
	}
	MobilePhone* produceMobilePhone(){
		return miphone;
	}
	~XiaomiFactory(){}
};
#endif