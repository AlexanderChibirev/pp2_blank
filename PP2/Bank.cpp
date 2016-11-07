#include "Bank.h"

CBank::CBank()
{
	m_clients = std::vector<CBankClient>();
	m_totalBalance = 0;
}


CBankClient* CBank::CreateClient()
{
	unsigned clientId = unsigned(m_clients.size());
	m_clients.push_back(CBankClient(this, clientId));
	return &m_clients.back();
}


void CBank::UpdateClientBalance(CBankClient &client, int value)
{
	int totalBalance = GetTotalBalance();
	std::cout << "Client " << client.GetId() << " initiates reading total balance. Total = " << totalBalance << "." << std::endl;
	
	SomeLongOperations();
	totalBalance += value;

	std::cout
		<< "Client " << client.GetId() << " updates his balance with " << value
		<< " and initiates setting total balance to " << totalBalance
		<< ". Must be: " << GetTotalBalance() + value << "." << std::endl;

	//+Check correctness of transaction through actual total balance
	if (totalBalance < 0)
	{
		std::cout << std::endl << std::endl;
		std::cout << "ERROR in operation" << std::endl;
		std::cout << "Total balance = " << GetTotalBalance() << std::endl;
		std::cout << "Value = " << value << std::endl;
		std::cout << "Set Value = " << totalBalance << std::endl;
		std::cout << "Balance not must be less zero!!!" << std::endl;
		return;
	}
	SetTotalBalance(totalBalance);
}


int CBank::GetTotalBalance()
{
	return m_totalBalance;
}


void CBank::SetTotalBalance(int value)
{
	m_totalBalance = value;
}

void CBank::SomeLongOperations()
{
	Sleep(GetSleepDuration());
}

unsigned int CBank::GetSleepDuration()
{
	return rand() % 100;
}