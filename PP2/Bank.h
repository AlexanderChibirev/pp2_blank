#pragma once
#include <iostream>
#include <vector>

#include "BankClient.h"

class CBank
{
public:
	CBank();
	CBankClient* CreateClient();
	void UpdateClientBalance(CBankClient& client, int value);

private:
	std::vector<CBankClient> m_clients;
	int m_totalBalance;

private:
	int GetTotalBalance();
	void SetTotalBalance(int value);
	void SomeLongOperations();
};