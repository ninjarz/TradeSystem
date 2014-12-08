#ifndef _GOODS_H_
#define _GOODS_H_

#include <string>
#include <ctime>

using namespace std;

//----------------------------------------------------------------------------------------------------
enum class GoodsType
{
	GOODS_DEFAULT = 0,
	GOODS_FOOD,
	GOODS_ELECTRONICS,
	GOODS_SUPPLIES
};

class Goods
{
public:
	Goods();
	Goods(const string& _goodsName, int _amount, int _price, const string& _owner);
	Goods(int _identifier, const string& _goodsName, int _amount, int _price, const string& _owner);
	Goods(const Goods& _goods);
	~Goods();

	virtual int CalculatePrice(int _num);

	void SetType(GoodsType _type);
	void SetIdentifier(int _identifier);
	void SetGoodsName(const string& _name);
	void SetAmount(int _amount);
	void SetPrice(int _price);
	void SetOwner(const string& _owner);

	GoodsType GetType();
	int GetIdentifier();
	string GetGoodsName();
	int GetAmount();
	int GetPrice();
	string GetOwner();
	virtual time_t& GetExpiryDate() = 0;

protected:
	static int s_goodsCounter;

	GoodsType m_type;
	int m_identifier;
	string m_goodsName;
	int m_amount;
	int m_price;
	string m_owner;
};

#endif