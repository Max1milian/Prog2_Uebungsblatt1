#include <iostream>
#include "kennzeichen.h"
#include "datenbank.h"
void schnapszahlTest() { 
	kfz::kennzeichen k;
	k.ort = 'N';
	k.buchstaben = "Nu";
	k.zahl = 333;

	kfz::kennzeichen* kptr;
	kptr = &k;

	std::cout << "Ergbenis, des Schnapszahltest" << kfz::istSchnapszahl(kptr) << std::endl;

}
void einlesenTest() { /* IHR CODE */ }
void datenbankTest() { /* IHR CODE */ }
int main()
{
/* IHR CODE */
return 0;
}
