#pragma once
#include <vector>
#include <string>

class DuplicateFind
{	
	public:
		DuplicateFind(const char path[], int FindType);

		std::vector<std::string>* GetDuplicates() {
			return &DuplicateFiles;
		}

		std::vector<std::string>* GetAllFilenames() {
			return &AllFilenames;
		}

		std::string getDir() {
			return FileDir;
		}
	private:
		std::vector<std::string> DuplicateFiles;
		std::vector<std::string> AllFilenames;
		std::string FileDir;
};

