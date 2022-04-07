#include <iostream>

#include "datenbank.h"
#include "kennzeichen.h"
void schnapszahlTest() {
  kfz::kennzeichen k;
  k.ort = 'N';
  k.buchstaben = "Nu";
  k.zahl = 333;

  kfz::kennzeichen *kptr;
  kptr = &k;

  std::cout << "Ergbenis, des Schnapszahltest" << kfz::istSchnapszahl(kptr)
            << std::endl;
}
void einlesenTest() {
  kfz::kennzeichen *kennzeichen_zeiger;
  kennzeichen_zeiger->buchstaben = kfz::einlesenBuchstaben();
  kennzeichen_zeiger->ort = kfz::einlesenOrt();
  kennzeichen_zeiger->zahl = kfz::einlesenZahl();

  kfz::ausgabe(kennzeichen_zeiger);
  kfz::schildTest(kennzeichen_zeiger);
}
void datenbankTest() {
  db::datenbank DB {};
  DB.name = "Augsburg";
  std::cout << "DB Eintraege: " << DB.eintraege << "\n" << "DB Name: " << DB.name << "\n" << "DB Schilder: " << DB.schilder << std::endl;
}
int main() { 
  datenbankTest();
  return 0; 
  }

