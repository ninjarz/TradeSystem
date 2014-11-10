#include "Seller.h"

//----------------------------------------------------------------------------------------------------
Seller::Seller()
{
	m_type = UserType::USER_SELLER;
}

Seller::Seller(int _identifier, const string& _userName, const string& _password, float _balance)
:
User(_identifier, _userName, _password, _balance)
{
	m_type = UserType::USER_SELLER;
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