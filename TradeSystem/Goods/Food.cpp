#include "Food.h"

//----------------------------------------------------------------------------------------------------
Food::Food()
:
m_expiryDate(0),
m_productionDate(0),
m_depreciateDate(0),
m_depreciateFactor(0)
{
	m_type = GoodsType::GOODS_FOOD;
}

Food::Food(const string& _goodsName, int _amount, int _price, const string& _owner, time_t _expiryDate, time_t _productionDate, time_t _depreciateDate, int _depreciateFactor)
:
Goods(_goodsName, _amount, _price, _owner),
m_expiryDate(_expiryDate),
m_productionDate(_productionDate),
m_depreciateDate(_depreciateDate),
m_depreciateFactor(_depreciateFactor)
{
	m_type = GoodsType::GOODS_FOOD;
}


Food::Food(int _identifier, const string& _goodsName, int _amount, int _price, const string& _owner, time_t _expiryDate, time_t _productionDate, time_t _depreciateDate, int _depreciateFactor)
:
Goods(_identifier, _goodsName, _amount, _price, _owner),
m_expiryDate(_expiryDate),
m_productionDate(_productionDate),
m_depreciateDate(_depreciateDate),
m_depreciateFactor(_depreciateFactor)
{
	m_type = GoodsType::GOODS_FOOD;
}

Food::Food(const Food& _food)
:
Goods(_food),
m_expiryDate(_food.m_expiryDate),
m_productionDate(_food.m_productionDate),
m_depreciateDate(_food.m_depreciateDate),
m_depreciateFactor(_food.m_depreciateFactor)
{

}

Food::~Food()
{

}

int Food::CalculatePrice(int _num)
{
	time_t currTime = time(NULL);
	if (currTime < m_depreciateDate)
		return m_price * _num;
	else if (currTime < m_expiryDate)
		return m_price * (float)m_depreciateFactor / 100 * _num;
	else
		return -1;
}

void Food::SetExpiryDate(time_t _expiryDate)
{
	m_expiryDate = _expiryDate;
}

void Food::SetProductionDate(time_t _productionDate)
{
	m_productionDate = _productionDate;
}

void Food::SetDepreciateDate(time_t _depreciateDate)
{
	m_depreciateDate = _depreciateDate;
}

void Food::SetDepreciateFactor(int _depreciateFactor)
{
	m_depreciateFactor = _depreciateFactor;
}

time_t& Food::GetExpiryDate()
{
	return m_expiryDate;
}

time_t& Food::GetProductionDate()
{
	return m_productionDate;
}

time_t& Food::GetDepreciateDate()
{
	return m_depreciateDate;
}

int Food::GetDepreciateFactor()
{
	return m_depreciateFactor;
}