#include <Windows.h>
#include <iostream>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  int punkteHauptfach;
  int punkteHauptfachAusgleich1;
  int punkteHauptfachAusgleich2;

	std::cout << "Wie viele Punkte hast du in deinem Hauptfach?" << std::endl;
	std::cin >> punkteHauptfach;

	if (punkteHauptfach >= 5) 
	{
		std::cout << "Du musst dein Hauptfach nicht ausgleichen." << std::endl;
	} else {
		std::cout << "Du musst dein Hauptfach ausgleichen." << std::endl << "Wie viele Punkte hast du in deinem ersten Hauptfach zum ausgleichen?" << std::endl;
		std::cin >> punkteHauptfachAusgleich1;
		if (punkteHauptfachAusgleich1 >= 10)
		{
			std::cout << "Du kannst dein Hauptfach erfolgreich ausgleichen." << std::endl;
		} else {
			std::cout << "Wie viele Punkte hast du in deinem zweiten Hauptfach zum ausgleichen?" << std::endl;
			std::cin >> punkteHauptfachAusgleich2;
			if (punkteHauptfachAusgleich1 >= 7 && punkteHauptfachAusgleich2 >= 7)
			{
				std::cout << "Du kannst dein Hauptfach erfolgreich ausgleichen." << std::endl;
			} else {
				std::cout << "Du kannst dein Hauptfach nicht ausgleichen." << std::endl;
			}
		}
		
	}
	

  return 0;
}