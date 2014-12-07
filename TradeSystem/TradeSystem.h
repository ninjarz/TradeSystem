#ifndef _TRADESYSTEM_H_
#define _TRADESYSTEM_H_

#include "User/Seller.h"
#include "User/Purchaser.h"
#include "Goods/Food.h"
#include "Goods/Electronics.h"
#include "Goods/Supplies.h"

#define USER_DATA "UserData.txt"
#define GOODS_DATA "GoodsData.txt"

//----------------------------------------------------------------------------------------------------
class TradeSystem
{
public:
	TradeSystem();
	~TradeSystem();

	void Run();
	bool Login(string _name, string _password);
	bool Register(string _name, string _password, int _type);
	void PrintGoodsList();
	void PrintMyGoodsList();
	User* FindUser(const string& _name);
	Goods* FindGoods(int _id);
	bool BuyGoods(int _id, int _num);
	bool AddGoods(Goods* _goods);

private:
	fstream m_userFile;
	fstream m_goodsFile;

	vector<User*> m_users;
	vector<Goods*> m_goods;

	User *m_client;
};

//----------------------------------------------------------------------------------------------------
template <class _Input>
_Input& operator>> (_Input& _input, UserType& _type);
template <class _Input>
_Input& operator>> (_Input& _input, User*& _user);
template <class _Input>
_Input& operator>> (_Input& _input, vector<User*>& _users);
template <class _Output>
_Output& operator<< (_Output& _output, UserType& _type);
template <class _Output>
_Output& operator<< (_Output& _output, User*& _user);
template <class _Output>
_Output& operator<< (_Output& _output, vector<User*>& _users);

template <class _Input>
_Input& operator>> (_Input& _input, GoodsType& _type);
template <class _Input>
_Input& operator>> (_Input& _input, Goods*& _goods);
template <class _Input>
_Input& operator>> (_Input& _input, vector<Goods*>& _goods);
template <class _Output>
_Output& operator<< (_Output& _output, GoodsType& _type);
template <class _Output>
_Output& operator<< (_Output& _output, Goods*& _goods);
template <class _Output>
_Output& operator<< (_Output& _output, vector<Goods*>& _goods);

#endif