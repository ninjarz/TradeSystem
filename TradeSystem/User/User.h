#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "../Goods/Goods.h"

using namespace std;

//----------------------------------------------------------------------------------------------------
enum class UserType
{
	USER_DEFAULT = 0,
	USER_PURCHASER,
	USER_SUPERPURCHASER,
	USER_SELLER
};

class User
{
public:
	User();
	User(int _identifier, const string& _userName, const string& _password, float _balance);
	User(const User& _user);
	virtual ~User();

	virtual bool Register(const string& _userName, const string& _password) = NULL;
	virtual bool Login();
	void Logout();
	virtual void PrintUserInfo();

	void SetType(UserType _type);
	void SetIdentifier(int _identifier);
	void SetUserName(const string& _userName);
	void SetPassword(const string& _password);
	void SetBalance(float _balance);

	UserType GetType();
	int GetIdentifier();
	string GetUserName();
	string GetPassword(); //may be I should erase it
	float GetBalance();

protected:
	static int s_userCounter;

	bool m_isLogin;
	UserType m_type;
	int m_identifier;
	string m_userName;
	string m_password;
	float m_balance;
};

#endif