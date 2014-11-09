#ifndef _PURCHASER_H_
#define _PURCHASER_H_

#include "User.h"

//----------------------------------------------------------------------------------------------------
class Purchaser : public User
{
public:
	Purchaser();
	Purchaser(const Purchaser& _purchaser);
	~Purchaser();

	bool Register(const string& _userName, const string& _password);
	bool Recharge(int _value);

protected:

};


//----------------------------------------------------------------------------------------------------
#define EXCHANGE_RATE 1
#define DISCOUNT_VIP1 0.9
#define DISCOUNT_VIP2 0.85
#define DISCOUNT_VIP3 0.8
#define DISCOUNT_VIP4 0.75

class SuperPurchaser : public Purchaser
{
public:
	SuperPurchaser();
	SuperPurchaser(const SuperPurchaser& _superPurchaser);
	~SuperPurchaser();

	bool Register(const string& _userName, const string& _password);
	void PrintUserInfo();
	bool TokenToBalance(int _token);

	void SetLevel(int _level);
	void SetToken(int _token);

	int GetLevel();
	int GetToken();

protected:
	int m_level;
	int m_token;
};


#endif