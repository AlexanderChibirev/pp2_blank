#pragma once
#include <iostream>
#include <vector>
#include <memory>

#include "BankClient.h"

enum PrimitiveSynchronize
{
		CriticalSection = 1
	,	Mutex
	,	Semaphore
	,	Event
};

class CBankClient;

class CBank
{
public:
	CBank(PrimitiveSynchronize type);

	CBankClient* CreateClient();
	void UpdateClientBalance(CBankClient& client, int value);
	void WaitThreads();
	void CreateThreads(size_t amountCpu);
private:
	std::vector<CBankClient> m_clients;
	std::vector<HANDLE> m_threads;
	int m_totalBalance;
	PrimitiveSynchronize m_primitiveSynchronizeType;
	
private:
	int GetTotalBalance();
	void SetTotalBalance(int value);
	void SomeLongOperations();
	unsigned int GetSleepDuration();

};