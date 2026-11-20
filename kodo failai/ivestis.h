#ifndef IVESTIS_H
#define IVESTIS_H

#include <string>
#include <vector>
#include "studentas.h"

void ivestiRankiniu(std::vector<Studentas>& s);
bool nuskaitytiFaila(const std::string& failoPav, std::vector<Studentas>& s);
void nuskaitytiIsFailo(std::vector<Studentas>& s);
void generuotiAtsitiktinai(std::vector<Studentas>& s);

#endif
