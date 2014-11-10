#ifndef _FOOD_H_
#define _FOOD_H_

#include "Goods.h"

//----------------------------------------------------------------------------------------------------
class Food : public Goods
{
public:
	Food();
	Food(int _identifier, const string& _goodsName, int _amount, int _price, const string& _owner, time_t _expiryDate, time_t _productionDate, time_t _depreciateDate, int _depreciateFactor);
	Food(const Food& _food);
	~Food();

	void SetExpiryDate(time_t _expiryDate);
	void SetProductionDate(time_t _productionDate);
	void SetDepreciateDate(time_t _depreciateDate);
	void SetDepreciateFactor(time_t _depreciateFactor);

	time_t GetExpiryDate();
	time_t GetProductionDate();
	time_t GetDepreciateDate();
	int GetDepreciateFactor();

private:
	time_t m_expiryDate;
	time_t m_productionDate;
	time_t m_depreciateDate;
	int m_depreciateFactor;
};

#endif