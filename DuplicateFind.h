#pragma once
#include <string>

class DuplicateFind
{	
	public:
		DuplicateFind(const char path[]);
		
		std::string DuplicateFiles() {
			return DuplicateNames;
		}

		int DuplicateAmount() {
			return duplicateFiles;
		}
	private:
		void GetUserOption();
		void MoveFiles();
		void RemoveFiles();
		std::string DuplicateNames;
		std::string AllFilenames;
		int duplicateFiles = 0;
};

