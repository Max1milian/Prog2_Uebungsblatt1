#pragma once
#define DB_LIMIT 10
#include "kennzeichen.h"
#include <string>
namespace db {
struct datenbank {
  std::string name;
  kfz::kennzeichen *schilder[DB_LIMIT];
  int eintraege = 0;
};
typedef struct datenbank datenbank;
bool einfuegen(datenbank *db, kfz::kennzeichen *schild) { 
	if (db->eintraege < DB_LIMIT) {
		std::cout << "Zu viele eintraege!" << std::endl;
		return false;
	}
	return true;
}
std::string ausgabe(const datenbank &db) {
	std::string text_ausgabe {};
	return text_ausgabe;
}
} // namespace db
