#pragma once
#define DB_LIMIT 10
#include <string>

#include "kennzeichen.h"
namespace db {
struct datenbank {
  std::string name;
  kfz::kennzeichen *schilder[DB_LIMIT];
  int eintraege = 0;
};
typedef struct datenbank datenbank;
bool einfuegen(datenbank *db, kfz::kennzeichen *schild) {
  db->schilder[db->eintraege] = schild; // da eintrage gleich 0 ist können wir
                                        // diese als Variable gleich benutzen
  db->eintraege++; // bei erfolgreichem einfügen erhöhen wir gleichzeitig diese
                   // Variable

  if (db->eintraege >=
      DB_LIMIT) { // dies hat den Vorteil, dass wir ohne Hilfsvariablen gleich
                  // sehen können ob wir in den Limiter laufen oder nicht
    std::cout << "Eintragslimit erreicht. breche ab!" << std::endl;
    return false;
  }
  return true;
}
std::string ausgabe(const datenbank &db) {
  std::string repraesentation {}; 
  /*repraesentation += "Name der Datenbank: " + db.name + "\n";
  repraesentation += "------------------------------\n";
  for (int i = 0; i <= db.eintraege; i++)
  {
    repraesentation += db.schilder[i] + "\n";
  }*/
  return repraesentation;
}
} // namespace db
