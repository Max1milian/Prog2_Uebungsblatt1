#pragma once
#define DB_LIMIT 10
#include <string>

#include "kennzeichen.h"
namespace db {
struct datenbank
{
  std::string name;
  kfz::kennzeichen* schilder[DB_LIMIT];
  int eintraege = 0;
};
typedef struct datenbank datenbank;
bool
einfuegen(datenbank* db, kfz::kennzeichen* schild)
{
  db->schilder[db->eintraege] = schild; //da eintrage gleich 0 ist können wir diese als Variable gleich benutzen
  db->eintraege++; //bei erfolgreichem einfügen erhöhen wir gleichzeitig diese Variable

  if (db->eintraege >= DB_LIMIT) { //dies hat den Vorteil, dass wir ohne Hilfsvariablen gleich sehen können ob wir in den Limiter laufen oder nicht
    std::cout << "Datenlimit erreicht. breche ab!" << std::endl;
    return false;
  }
  return true;
}
std::string
ausgabe(const datenbank& db)
{
  std::string r_datenbank = db.name;
  r_datenbank += "\n";
  return r_datenbank;
}
} // namespace db
