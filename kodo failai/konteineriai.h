#ifndef KONTEINERIAI_H
#define KONTEINERIAI_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <list>
#include <string>
#include <vector>
#include "studentas.h"

template <typename C>
bool skaitytiKonteineri(const std::string& failoPav, C& s) {
    std::ifstream failas(failoPav);
    if (!failas.is_open()) return false;
    std::string eilute;
    std::getline(failas, eilute);

    Studentas stud;
    while (stud.readStudent(failas)) {
        s.push_back(stud);
    }
    return true;
}
template <typename C>
void dalintiKonteineri(C& s, C& vargsiukai, C& kietiakiai) {
    for (const auto& stud : s) {
        if (stud.galutinisVid() < 5.0)
            vargsiukai.push_back(stud);
        else
            kietiakiai.push_back(stud);
    }
}
inline void rusiuotiKonteineri(std::vector<Studentas>& v) {
    std::sort(v.begin(), v.end(), comparePagalGalutini);
}

inline void rusiuotiKonteineri(std::list<Studentas>& l) {
    l.sort(comparePagalGalutini);
}
template <typename C>
void rasytiKonteineri(const C& v, const std::string& pavadinimas) {
    std::ofstream out(pavadinimas);
    out << std::fixed << std::setprecision(2);
    out << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde"
        << "Galutinis (Vid.)\n";
    for (const auto& stud : v) {
        out << std::left << std::setw(20) << stud.vardas() << std::setw(20) << stud.pavarde()
            << stud.galutinisVid() << "\n";
    }
}
template <typename C>
void ivestiRankiniuSuAdresais(C& s) {
    using namespace std;
    int studSk;
    cout << "Studentu skaicius: ";
    cin >> studSk;
    cin.ignore();
    for (int i = 0; i < studSk; i++) {
        Studentas stud;
        string vardas, pavarde;
        int egz;
        cout << "\n" << (i + 1) << "-as studentas\n";
        cout << "Vardas: ";
        cin >> vardas;
        stud.setVardas(vardas);
        cout << "Pavarde: ";
        cin >> pavarde;
        stud.setPavarde(pavarde);
        cin.ignore();
        cout << "Namu darbu balai (palikti tuscia, kad baigti):\n";
        while (true) {
            string eilute;
            getline(cin, eilute);
            if (eilute.empty()) break;
            try {
                stud.pridetiNd(stoi(eilute));
            } catch (const exception&) {
                cout << "Neteisinga reiksme, bandykite dar karta.\n";
            }
        }
        cout << "Egzamino rezultatas: ";
        cin >> egz;
        cin.ignore();
        stud.setEgz(egz);
        stud.apskaiciuotiGalutini();
        s.push_back(stud);
        cout << "Objekto adresas atmintyje: " << static_cast<const void*>(&s.back()) << "\n";
    }
}
template <typename C>
void rodytiSuAdresais(const C& s) {
    using namespace std;
    cout << "\n" << left << setw(16) << "Vardas" << setw(16) << "Pavarde"
         << setw(12) << "Galutinis" << "Adresas\n";
    cout << string(60, '-') << "\n" << fixed << setprecision(2);
    for (const auto& stud : s) {
        cout << left << setw(16) << stud.vardas() << setw(16) << stud.pavarde()
             << setw(12) << stud.galutinisVid()
             << static_cast<const void*>(&stud) << "\n";
    }
}

#endif
