#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"


void PrintHelp()
{
	std::cout << "Help" << std::endl;
	std::cout << "First parametr - amount clients" << std::endl;
	std::cout << "Second parametr - type primitive synchronization" << std::endl;
	std::cout << std::endl;
	std::cout << "Second parametr type:" << std::endl;
	std::cout << "1 - critical section" << std::endl;
	std::cout << "2 - mutex" << std::endl;
	std::cout << "3 - semaphore" << std::endl;
	std::cout << "4 - event" << std::endl;
}

int main(int argc, char * argv[])
{

	CBank* bank = new CBank();
	CBankClient* client1 = bank->CreateClient();
	CBankClient* client2 = bank->CreateClient();
	
    return 0;
}