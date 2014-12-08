#include "TradeSystem.h"

#pragma warning(disable: 4996)

//----------------------------------------------------------------------------------------------------
TradeSystem::TradeSystem()
:
m_userFile(USER_DATA),
m_goodsFile(GOODS_DATA),
m_users(),
m_goods(),
m_client(NULL)
{
	if (m_userFile.is_open())
	{
		m_userFile >> m_users;
	}
	if (m_goodsFile.is_open())
	{
		m_goodsFile >> m_goods;
	}
}

TradeSystem::~TradeSystem()
{

}

void TradeSystem::Run()
{
	while (!m_client)
	{
		int cmd = 0;
		while (cmd != 1 && cmd != 2)
		{
			cout << "1.Login" << endl;
			cout << "2.Register" << endl;
			cin >> cmd;
		}
		
		switch (cmd)
		{
		case 1:
		{
				  cout << "ÊäÈëÕËºÅÃÜÂë:" << endl;
				  string name;
				  cin >> name;
				  string passworld;
				  cin >> passworld;
				  Login(name, passworld);
		}
			break;
		case 2:
		{
				  cmd = 0;
				  while (cmd != 1 && cmd != 2)
				  {
					  cout << "1.Purchaser" << endl;
					  cout << "2.Purchaser" << endl;
					  cin >> cmd;
				  }
				  cout << "ÊäÈëÕËºÅÃÜÂë:" << endl;
				  string name;
				  cin >> name;
				  string passworld;
				  cin >> passworld;
				  Register(name, passworld, cmd);
		}
			break;

		default:
			cout << "Error" << endl;
			break;
		}
	}

	int cmd = 0;
	if (m_client->GetType() != UserType::USER_SELLER)
	{
		while (cmd != 5)
		{
			cout << "1.PrintUserInfo" << endl;
			cout << "2.PrintGoodsList" << endl;
			cout << "3.Recharge" << endl;
			cout << "4.BuyGoods" << endl;
			cout << "5.Quit" << endl;
			cin >> cmd;

			switch (cmd)
			{
			case 1:
				m_client->PrintUserInfo();
				break;
			case 2:
				PrintGoodsList();
				break;
			case 3:
			{
					  int money = 0;
					  cout << "Money:" << endl;
					  cin >> money;
					  ((Purchaser*)m_client)->Recharge(money);
			}
				break;
			case 4:
			{
					  int id = -1;
					  int number = 0;
					  cout << "Id and number:" << endl;
					  cin >> id;
					  cin >> number;
					  BuyGoods(id, number);
					  break;
			}
			case 5:
				break;
			default:
				break;
			}
		}
	}
	else
	{
		while (cmd != 5)
		{
			cout << "1.PrintUserInfo" << endl;
			cout << "2.PrintGoodsList" << endl;
			cout << "3.PrintMyGoodsList" << endl;
			cout << "4.AddGoods" << endl;
			cout << "5.Quit" << endl;
			cin >> cmd;

			switch (cmd)
			{
			case 1:
				m_client->PrintUserInfo();
				break;
			case 2:
				PrintGoodsList();
				break;
			case 3:
				PrintMyGoodsList();
				break;
			case 4:
			{
					  cout << "1.Food" << endl;
					  cout << "2.Electronics" << endl;
					  cout << "3.Supplies" << endl;
					  cin >> cmd;
					  switch (cmd)
					  {
					  case 1:
					  {
								string name;
								cin >> name;
								int amount;
								cin >> amount;
								float price;
								cin >> price;
								tm expiryDate;
								cin >> expiryDate.tm_year;
								expiryDate.tm_year -= 1900;
								cin >> expiryDate.tm_mon;
								expiryDate.tm_mon -= 1;
								cin >> expiryDate.tm_mday;
								tm productionDate;
								cin >> productionDate.tm_year;
								productionDate.tm_year -= 1900;
								cin >> productionDate.tm_mon;
								productionDate.tm_mon -= 1;
								cin >> productionDate.tm_mday;
								tm depreciateDate;
								cin >> depreciateDate.tm_year;
								depreciateDate.tm_year -= 1900;
								cin >> depreciateDate.tm_mon;
								depreciateDate.tm_mon -= 1;
								cin >> depreciateDate.tm_mday;
								float depreciateFactor;
								cin >> depreciateFactor;

								Food *food = new Food(name, amount, (int)(price * 10), m_client->GetUserName(), mktime(&expiryDate), mktime(&productionDate), mktime(&depreciateDate), (int)(depreciateFactor*100));
								AddGoods(food);
					  }
						  break;
					  case 2:
					  {
								string name;
								cin >> name;
								int amount;
								cin >> amount;
								float price;
								cin >> price;
								tm expiryDate;
								cin >> expiryDate.tm_year;
								expiryDate.tm_year -= 1900;
								cin >> expiryDate.tm_mon;
								expiryDate.tm_mon -= 1;
								cin >> expiryDate.tm_mday;
								tm productionDate;
								cin >> productionDate.tm_year;
								productionDate.tm_year -= 1900;
								cin >> productionDate.tm_mon;
								productionDate.tm_mon -= 1;
								cin >> productionDate.tm_mday;
								float depreciateFactor;
								cin >> depreciateFactor;

								Electronics *electronics = new Electronics(name, amount, (int)(price * 10), m_client->GetUserName(), mktime(&expiryDate), mktime(&productionDate), (int)(depreciateFactor * 100));
								AddGoods(electronics);
					  }
						  break;
					  case 3:
					  {
								string name;
								cin >> name;
								int amount;
								cin >> amount;
								float price;
								cin >> price;
								tm expiryDate;
								cin >> expiryDate.tm_year;
								expiryDate.tm_year -= 1900;
								cin >> expiryDate.tm_mon;
								expiryDate.tm_mon -= 1;
								cin >> expiryDate.tm_mday;

								Supplies *supplies = new Supplies(name, amount, (int)(price * 10), m_client->GetUserName(), mktime(&expiryDate));
								AddGoods(supplies);
					  }
						  break;
					  default:
						  break;
					  }
			}
				break;
			case 5:
				break;
			default:
				break;
			}
		}
	}
}

bool TradeSystem::Login(string _name, string _password)
{
	for (User* user : m_users)
	{
		if (user->GetUserName() == _name)
		{
			if (user->GetPassword() == _password)
			{
				m_client = user;
				m_client->Login();
				m_client->PrintUserInfo();
				return true;
			}
			else
				return false;   //password error
		}
	}

	return false;
}

bool TradeSystem::Register(string _name, string _password, int _type)
{
	for (User* user : m_users)
	{
		if (user->GetUserName() == _name)
		{
			return false;   //userName already exists
		}
	}

	switch (_type)
	{
	case 0:
	{
			  Purchaser *newUser = new Purchaser;
			  newUser->Register(_name, _password);
			  m_users.push_back(newUser);
	}
		break;
	case 1:
	{
			  Seller *newUser = new Seller;
			  newUser->Register(_name, _password);
			  m_users.push_back(newUser);
	}
		break;
	default:
		return false;
	}

	return true;
}

void TradeSystem::PrintGoodsList()
{
	for (Goods* goods : m_goods)
	{
		cout << goods->GetIdentifier() << endl;
		switch (goods->GetType())
		{
		case GoodsType::GOODS_FOOD:
			cout << "FOOD" << endl;
			break;
		case GoodsType::GOODS_ELECTRONICS:
			cout << "ELECTRONICS" << endl;
			break;
		case GoodsType::GOODS_SUPPLIES:
			cout << "SUPPLIES" << endl;
			break;
		default:
			break;
		}
		cout << goods->GetGoodsName() << endl;
		cout << goods->GetAmount() << endl;
		cout << (float)goods->CalculatePrice(1) / 10 << endl;
		cout << ctime(&goods->GetExpiryDate());
		cout << goods->GetOwner() << endl;
	}
}

void TradeSystem::PrintMyGoodsList()
{
	if (m_client)
	{
		if (m_client->GetType() == UserType::USER_SELLER)
		{
			for (Goods* goods : m_goods)
			{
				if (goods->GetOwner() == m_client->GetUserName())
				{
					cout << goods->GetIdentifier() << endl;
					switch (goods->GetType())
					{
					case GoodsType::GOODS_FOOD:
						cout << "FOOD" << endl;
						break;
					case GoodsType::GOODS_ELECTRONICS:
						cout << "ELECTRONICS" << endl;
						break;
					case GoodsType::GOODS_SUPPLIES:
						cout << "SUPPLIES" << endl;
						break;
					default:
						break;
					}
					cout << goods->GetGoodsName() << endl;
					cout << goods->GetAmount() << endl;
					cout << (float)goods->CalculatePrice(1) / 10 << endl;
					cout << ctime(&goods->GetExpiryDate());
				}
			}
		}
	}
}

User* TradeSystem::FindUser(const std::string& _name)
{
	for (User* user : m_users)
	{
		if (user->GetUserName() == _name)
			return user;
	}

	return NULL;
}

Goods* TradeSystem::FindGoods(int _id)
{
	for (Goods* goods : m_goods)
	{
		if (goods->GetIdentifier() == _id)
			return goods;
	}

	return NULL;
}

bool TradeSystem::BuyGoods(int _id, int _num)
{
	if (m_client)
	{
		if (m_client->GetType() != UserType::USER_SELLER)
		{
			Goods* goods = FindGoods(_id);
			if (goods)
			{
				if (goods->GetAmount() >= _num && m_client->GetBalance() >= goods->CalculatePrice(_num))
				{
					m_client->SetBalance(m_client->GetBalance() - goods->CalculatePrice(_num));
					User* seller = FindUser(goods->GetOwner());
					seller->SetBalance(seller->GetBalance() + goods->CalculatePrice(_num));
					goods->SetAmount(goods->GetAmount() - _num);

					return true;
				}
			}
		}
	}

	return false;
}

bool TradeSystem::AddGoods(Goods* _goods)
{
	if (_goods)
	{
		m_goods.push_back(_goods);
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------------------------------
template <class _Input>
_Input& operator>> (_Input& _input, UserType& _type)
{
	char type;
	_input >> type;
	switch (type)
	{
	case 'P':
		_type = UserType::USER_PURCHASER;
		break;

	case 'V':
		_type = UserType::USER_SUPERPURCHASER;
		break;

	case 'S':
		_type = UserType::USER_SELLER;
		break;

	default:
		//ERROR
		break;
	}

	return _input;
}

template <class _Input>
_Input& operator>> (_Input& _input, User*& _user)
{
	if (_user)
	{
		delete _user;
		_user = NULL;
	}

	UserType type;
	_input >> type;
	int identifier;
	_input >> identifier;
	string name;
	_input >> name;
	string password;
	_input >> password;
	float balance;
	_input >> balance;
	switch (type)
	{
	case UserType::USER_PURCHASER:
		if (_input.fail())
		{
			_input.clear(ios::failbit);
			_input.ignore(255, ' ');
			//_input.sync();
			return _input;
		}
		_user = new Purchaser(identifier, name, password, balance);
		break;

	case UserType::USER_SUPERPURCHASER:
	{
										  int level;
										  _input >> level;
										  int token;
										  _input >> token;
										  if (_input.fail())
										  {
											  _input.clear(ios::failbit);
											  _input.ignore(255, ' ');
											  //_input.sync();
											  return _input;
										  }
										  _user = new SuperPurchaser(identifier, name, password, balance, level, token);
	}
		break;

	case UserType::USER_SELLER:
		if (_input.fail())
		{
			_input.clear(ios::failbit);
			_input.ignore(255, ' ');
			//_input.sync();
			return _input;
		}
		_user = new Seller(identifier, name, password, balance);
		break;

	default:
		//ERROR
		break;
	}

	return _input;
}

template <class _Input>
_Input& operator>> (_Input& _input, vector<User*>& _users)
{
	while (!_input.eof())
	{
		User *user = NULL;
		_input >> user;
		if (user)
			_users.push_back(user);
		else
			break;
	}
	_input.clear();

	return _input;
}

template <class _Output>
_Output& operator<< (_Output& _output, UserType&& _type)
{
	switch (_type)
	{
	case UserType::USER_PURCHASER:
		_output << "P";
		break;

	case UserType::USER_SUPERPURCHASER:
		_output << "V";
		break;

	case UserType::USER_SELLER:
		_output << "S";
		break;

	default:
		//ERROR
		break;
	}

	return _output;
}

template <class _Output>
_Output& operator<< (_Output& _output, User*& _user)
{
	_output << _user->GetType() << " ";
	_output << _user->GetIdentifier() << " ";
	_output << _user->GetUserName() << " ";
	_output << _user->GetPassword() << " ";
	_output << _user->GetBalance() << " ";
	switch (_user->GetType())
	{
	case UserType::USER_PURCHASER:
		_output << "\n";
		break;

	case UserType::USER_SUPERPURCHASER:
		_output << ((SuperPurchaser*)_user)->GetLevel() << " ";
		_output << ((SuperPurchaser*)_user)->GetToken() << "\n";
		break;

	case UserType::USER_SELLER:
		_output << "\n";
		break;

	default:
		//ERROR
		break;
	}

	return _output;
}

template <class _Output>
_Output& operator<< (_Output& _output, vector<User*>& _users)
{
	for (User* user : _users)
	{
		_output << user;
	}

	return _output;
}

template <class _Input>
_Input& operator>> (_Input& _input, GoodsType& _type)
{
	char type;
	_input >> type;
	switch (type)
	{
	case 'F':
		_type = GoodsType::GOODS_FOOD;
		break;

	case 'E':
		_type = GoodsType::GOODS_ELECTRONICS;
		break;

	case 'S':
		_type = GoodsType::GOODS_SUPPLIES;
		break;

	default:
		//ERROR
		break;
	}

	return _input;
}

template <class _Input>
_Input& operator>> (_Input& _input, Goods*& _goods)
{
	if (_goods)
	{
		delete _goods;
		_goods = NULL;
	}

	GoodsType type;
	_input >> type;
	int identifier;
	_input >> identifier;
	string name;
	_input >> name;
	int amount;
	_input >> amount;
	int price;
	_input >> price;
	string owner;
	_input >> owner;
	switch (type)
	{
	case GoodsType::GOODS_FOOD:
	{
								  time_t expiryDate;
								  _input >> expiryDate;
								  time_t productionDate;
								  _input >> productionDate;
								  time_t depreciateDate;
								  _input >> depreciateDate;
								  int depreciateFactor;
								  _input >> depreciateFactor;
								  if (_input.fail())
								  {
									  _input.clear(ios::failbit);
									  _input.ignore(255, ' ');
									  //_input.sync();
									  return _input;
								  }
								  _goods = new Food(identifier, name, amount, price, owner, expiryDate, productionDate, depreciateDate, depreciateFactor);
	}
		break;

	case GoodsType::GOODS_ELECTRONICS:
	{
										 time_t expiryDate;
										 _input >> expiryDate;
										 time_t productionDate;
										 _input >> productionDate;
										 int depreciateFactor;
										 _input >> depreciateFactor;
										  if (_input.fail())
										  {
											  _input.clear(ios::failbit);
											  _input.ignore(255, ' ');
											  //_input.sync();
											  return _input;
										  }
										  _goods = new Electronics(identifier, name, amount, price, owner, expiryDate, productionDate, depreciateFactor);
	}
		break;

	case GoodsType::GOODS_SUPPLIES:
	{
									  time_t expiryDate;
									  _input >> expiryDate;
									  if (_input.fail())
									  {
										  _input.clear(ios::failbit);
										  _input.ignore(255, ' ');
										  //_input.sync();
										  return _input;
									  }
									  _goods = new Supplies(identifier, name, amount, price, owner, expiryDate);
	}
		break;

	default:
		//ERROR
		break;
	}

	return _input;
}

template <class _Input>
_Input& operator>> (_Input& _input, vector<Goods*>& _goods)
{
	while (!_input.eof())
	{
		Goods *goods = NULL;
		_input >> goods;
		if (goods)
			_goods.push_back(goods);
		else
			break;
	}
	_input.clear();

	return _input;
}

template <class _Output>
_Output& operator<< (_Output& _output, GoodsType&& _type)
{
	switch (_type)
	{
	case GoodsType::GOODS_FOOD:
		_output << "F";
		break;

	case GoodsType::GOODS_ELECTRONICS:
		_output << "E";
		break;

	case GoodsType::GOODS_SUPPLIES:
		_output << "S";
		break;

	default:
		//ERROR
		break;
	}

	return _output;
}

template <class _Output>
_Output& operator<< (_Output& _output, Goods*& _goods)
{
	_output << _goods->GetType() << " ";
	_output << _goods->GetIdentifier() << " ";
	_output << _goods->GetGoodsName() << " ";
	_output << _goods->GetAmount() << " ";
	_output << _goods->GetPrice() << " ";
	_output << _goods->GetOwner() << " ";
	switch (_goods->GetType())
	{
	case GoodsType::GOODS_FOOD:
		_output << ((Food*)_goods)->GetExpiryDate() << " ";
		_output << ((Food*)_goods)->GetProductionDate()<< " ";
		_output << ((Food*)_goods)->GetDepreciateDate() << " ";
		_output << ((Food*)_goods)->GetDepreciateFactor() << "\n";
		break;

	case GoodsType::GOODS_ELECTRONICS:
		_output << ((Electronics*)_goods)->GetExpiryDate() << " ";
		_output << ((Electronics*)_goods)->GetProductionDate() << " ";
		_output << ((Electronics*)_goods)->GetDepreciateFactor() << "\n";
		break;

	case GoodsType::GOODS_SUPPLIES:
		_output << ((Supplies*)_goods)->GetExpiryDate() << "\n";
		break;

	default:
		//ERROR
		break;
	}

	return _output;
}

template <class _Output>
_Output& operator<< (_Output& _output, vector<Goods*>& _goods)
{
	for (Goods* goods : _goods)
	{
		_output << goods;
	}

	return _output;
}