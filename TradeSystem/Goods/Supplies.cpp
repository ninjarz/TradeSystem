#include "Supplies.h"

//----------------------------------------------------------------------------------------------------
Supplies::Supplies()
:
m_expiryDate(0)
{

}

Supplies::Supplies(const Supplies& _supplies)
:
Goods(_supplies),
m_expiryDate(_supplies.m_expiryDate)
{

}

Supplies::~Supplies()
{

}