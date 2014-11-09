#include "Seller.h"

//----------------------------------------------------------------------------------------------------
Seller::Seller()
{

}

Seller::Seller(const Seller& _seller)
:
User(_seller)
{

}

Seller::~Seller()
{

}

bool Seller::Register(const string& _userName, const string& _password)
{
	++s_userCounter;

	m_identifier = s_userCounter;
	m_userName = _userName;
	m_password = _password;

	return true;
}