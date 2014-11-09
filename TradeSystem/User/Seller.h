#ifndef _SELLER_H_
#define _SELLER_H_

#include "User.h"

//----------------------------------------------------------------------------------------------------
class Seller : public User
{
public:
	Seller();
	Seller(const Seller& _seller);
	~Seller();

	bool Register(const string& _userName, const string& _password);
};

#endif