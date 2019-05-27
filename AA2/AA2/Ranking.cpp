#include "Ranking.h"


Ranking::Ranking()
{
	

	std::string nameAux;
	int pointaux;
	
	int counter = 0;
	std::ifstream inFile;
	inFile.open("ranking.txt");


	while (!inFile.eof()) {
		
		inFile >> nameAux >> pointaux;

		ranking.insert(std::pair<std::string, int>(nameAux, pointaux));

	}

	inFile.close();


}



void Ranking::addPS(int score)
{
	std::string name;
	std::ofstream outputFile("ranking.txt");
	
	std::cout << "Name: ";
	std::cin >> name;

	outputFile << name << std::endl;
	outputFile << score << std::endl;

	ranking.insert(std::pair<std::string, int>(name, score));

	for (std::map<std::string, int>::iterator it = ranking.begin(); it != ranking.end(); ++it) {
		
		outputFile << it->first << std::endl;
		outputFile << it->second << std::endl;

	}

	outputFile.close();
	
}

void Ranking::printRanking()
{
	HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);

	int counter = 1;

	std::map<std::string, int> mapAux = ranking;
	int biggerNum = 0;



	for (std::map<std::string, int>::iterator it; counter <= 5; counter++) {
		biggerNum = 0;

		for (std::map<std::string, int>::iterator it2 = mapAux.begin(); it2 != mapAux.end(); ++it2) {
			if (it2->second > biggerNum) {
				it = it2;
				biggerNum = it2->second;
			}
			
		}

		if (counter == 1) {
			SetConsoleTextAttribute(consolehwnd, 10);
			std::cout << counter << " - " << it->first << " -> " << it->second << std::endl; 
		}
		else if(counter == 5) {
			SetConsoleTextAttribute(consolehwnd, 4);
			std::cout << counter << " - " << it->first << " -> " << it->second << std::endl;
		}
		else {
			SetConsoleTextAttribute(consolehwnd, 3);
			std::cout << counter << " - " << it->first << " -> " << it->second << std::endl;
		}
		it->second = 0;
		
	}

}




