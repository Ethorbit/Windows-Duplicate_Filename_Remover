#pragma once
#include "DuplicateFind.h"
class AddressDuplicates
{
	public:
		AddressDuplicates(DuplicateFind &finder);

	private:
		void GetUserOption();
		void MoveFiles();
		void RemoveFiles();
};

