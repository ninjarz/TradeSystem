#ifndef _GOODS_H_
#define _GOODS_H_

#include <string>
#include <ctime>

using namespace std;

//----------------------------------------------------------------------------------------------------
typedef enum
{
	GOODS_DEFAULT = 0,
	GOODS_FOOD,
	GOODS_ELECTRONICS,
	GOODS_SUPPLIES
} GoodsType;

class Goods
{
public:
	Goods();
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

protected:
	static int m_goodsCounter;

	GoodsType m_type;
	int m_identifier;
	string m_goodsName;
	int m_amount;
	int m_price;
	string m_owner;
};

//----------------------------------------------------------------------------------------------------
class Food : public Goods
{
public:
	Food();
	Food(const Food& _food);
	~Food();

private:
	int m_expiryDate;
	int m_productionDate;
	int m_depreciateDate;
	int m_depreciateFactor;

};

//----------------------------------------------------------------------------------------------------
class Electronics : public Goods
{
public:
	Electronics();
	Electronics(const Electronics& _electronics);
	~Electronics();

private:
	int m_expiryDate;
	int m_productionDate;
	int m_depreciateFactor;
};

//----------------------------------------------------------------------------------------------------
class Supplies : public Goods
{
public:
	Supplies();
	Supplies(const Supplies& _supplies);
	~Supplies();

private:
	int m_expiryDate;
};

#endif