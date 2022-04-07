#pragma once
#include <iostream>
#include <ostream>
#include <string>
/* IHR CODE */
namespace kfz {
struct kennzeichen {
  std::string ort;
  std::string buchstaben;
  short zahl;
};

typedef struct kennzeichen kennzeichen;

std::string einlesenOrt() {
  char Ort[10];
  std::cout
      << "bitte geben sie ihren Ort ein. Achtung nur maximal drei Buchstaben: ";
  std::cin >> Ort;

  if ((sizeof Ort / sizeof Ort[0]) <=
      3) { // da char[] kein .length() unterstüzt müssen wir die länge über
           // sizeof errechenen.
    std::cout << "Fehler! Eingabe überschreitet Stringlänge." << std::endl;
    einlesenOrt(); // rekursion, damit der Nutzer im Fehlerfall erneut
                   // aufgefordert wird seine Daten erneut einzugeben.
  }

  return Ort;
}

std::string einlesenBuchstaben() {
  std::string buchstaben{};
  std::cout << "Bitte geben sie die Abkürzung ihres Kennzeichens ein. Achtung, "
               "es werden nur maximal zwei Buchstaben "
               "akzeptiert"
            << std::endl;
  std::cin >> buchstaben;

  /* hier testen wir ob die maximiale länge von zwei buchstaben überschritten
   * wird. Die .lenght() medothe jedoch fängt nicht bei 0 sondern bei 1 an zu
   * zählen. Deswegen müssen wir buchstaben.length() - 1 andwenden damit wir
   * keine Index out of bounds fehlermeldung bekommen*/
  if ((buchstaben.length() - 1) >= 2) {
    std::cout << "Fehler! Eingabe überschreitet Stringlänge" << std::endl;
    einlesenBuchstaben();
  }
  return buchstaben;
}

unsigned short einlesenZahl() {
  unsigned short zahl{}; // wir benutzen unsigned da wir lediglich mit
                         // positiven zahlen hantieren werden und somit der
                         // negative Bereich weggelassen werden kann.
  std::cout << "bitte geben sie ihre Wunschziffer ein. Achtung es werden nur "
               "positive Zahlen von 1 bis 9999 akzeptiert: ";
  std::cin >> zahl;
  if (zahl < 1 || zahl > 9999) { // hier überprüfen wir ob die Zahl entweder
                                 // kleiner als 1 oder größer als 9999 ist.
    std::cout << "Fehler! Eingabe überschreitet Zahlenlänge" << std::endl;
    einlesenZahl();
  }
  return zahl;
}

kennzeichen *einlesen() {
  kennzeichen *h_kennzeichen =
      new kennzeichen; // erzeugt die variable auf dem heap. deswegen die
                       // Kennzeichnung mit h_
  h_kennzeichen->buchstaben = einlesenBuchstaben();

  h_kennzeichen->ort = einlesenOrt();
  h_kennzeichen->zahl = einlesenZahl();
  return h_kennzeichen;
}

bool istSchnapszahl(const kennzeichen *pKennzeichen) {
  /*die Logik hinter diesem Statement ist, dass wenn die Zahl kleiner ist als
   * 9999 muss die Zahl noch entweder durch 11, 111 oder 1111 teilbar sein um
   * eine schnapszahl zu sein*/
  if (pKennzeichen->zahl <= 9999 &&
      (pKennzeichen->zahl % 11 == 0 || pKennzeichen->zahl % 111 == 0 ||
       pKennzeichen->zahl % 1111 == 0)) {
    std::cout << "die Zahl ist einen schapszahl" << std::endl;
    return true;
  }

  else {
    std::cout << "Die Zahl ist keine Schnapszahl" << std::endl;
    return false;
  }
}

bool istZehner(const kennzeichen *pKennzeichen) {
  if (pKennzeichen->zahl < 100 && pKennzeichen->zahl % 10 == 0) {
    std::cout << "Die Zahl " << pKennzeichen->zahl << " ist eine Zehnerzahl"
              << std::endl;
    return true;
  } else {
    std::cout << "Die Zahl " << pKennzeichen->zahl << " ist keine Zehnerzahl"
              << std::endl;
    return false;
  }
}

bool istHunderter(const kennzeichen *rKennzeichen) {
  // ist die Zahl kleiner als 1000 und bei einer teilung mit 100 kein rest
  // rauskommen soll. Diese schreibweise hat den Vorteil, dass wir uns if
  // statements sparen und der Code deutlich lesbarer wird.
  if (rKennzeichen->zahl < 1000 && rKennzeichen->zahl % 100 == 0) {
    std::cout << "Die Zahl " << rKennzeichen->zahl
              << " ist eine eine Hunderterzahl" << std::endl;
    return true;
  } else {
    std::cout << "die Zahl " << rKennzeichen->zahl << " ist keine Hunderterzahl"
              << std::endl;
    return false;
  }
}

bool istTausender(const kennzeichen *pKennzeichen) {
  if (pKennzeichen->zahl < 10000 && pKennzeichen->zahl % 1000 == 0) {
    std::cout << "Die Zahl " << pKennzeichen->zahl
              << " ist eine Tausenderzahl! " << std::endl;
    return true;
  } else {
    std::cout << "Die Zahl " << pKennzeichen->zahl
              << " ist keine Tausenderzahl!" << std::endl;
    return false;
  }
}

void schildTest(kennzeichen *schild) {
  if (istSchnapszahl(schild)) {
    std::cout << "Eine Schnapszahl! Gute Wahl!" << std::endl;
  }
  if (istZehner(schild)) {
    std::cout << "Eine Zehnerzahl" << std::endl;
  }

  if (istHunderter(schild)) {
    std::cout << "Eine Hunderterzahl" << std::endl;
  }
  if (istTausender(schild)) {
    std::cout << "Eine Tausenderzahl" << std::endl;
  }
}

std::string ausgabe(const kennzeichen *rKennzeichen) {
  std::string kennzeichen_ausgabe =
      rKennzeichen->ort + "--" + rKennzeichen->buchstaben + "--" +
      std::to_string(
          rKennzeichen->zahl); // hier müssen wir eine konvertierung vornehmen,
                               // da string kein short unterstützt
  return kennzeichen_ausgabe;
}

} // namespace kfz
