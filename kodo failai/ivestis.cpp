#include "ivestis.h"
#include "timer.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void ivestiRankiniu(vector<Studentas>& s) {
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
            stud.pridetiNd(stoi(eilute));
        }
        cout << "Egzamino rezultatas: ";
        cin >> egz;
        cin.ignore();
        stud.setEgz(egz);
        stud.apskaiciuotiGalutini();
        s.push_back(stud);
    }
}

bool nuskaitytiFaila(const string& failoPav, vector<Studentas>& s) {
    ifstream failas(failoPav);
    if (!failas.is_open()) return false;
    string antraste;
    getline(failas, antraste);
    Studentas stud;
    while (stud.readStudent(failas)) {
        s.push_back(stud);
    }
    failas.close();
    return true;
}
void nuskaitytiIsFailo(vector<Studentas>& s) {
    string failoPav;
    cout << "Iveskite failo pavadinima: ";
    cin >> failoPav;
    cin.ignore();
    Timer t;
    if (!nuskaitytiFaila(failoPav, s)) {
        cout << "Nepavyko atidaryti failo\n";
        return;
    }
    cout << "Duomenys is failo nuskaityti (" << s.size() << " studentu) per "
         << t.elapsed() << " s.\n";
}
void generuotiAtsitiktinai(vector<Studentas>& s) {
    int studSk;
    cout << "Studentu skaicius: ";
    cin >> studSk;
    cin.ignore();
    for (int i = 0; i < studSk; i++) {
        Studentas stud;
        string vardas, pavarde;
        cout << "\n" << (i + 1) << "-as studentas\n";
        cout << "Vardas: ";
        cin >> vardas;
        stud.setVardas(vardas);
        cout << "Pavarde: ";
        cin >> pavarde;
        stud.setPavarde(pavarde);
        cin.ignore();
        int nDarbu = rand() % 5 + 3;
        for (int j = 0; j < nDarbu; j++) {
            stud.pridetiNd(rand() % 10 + 1);
        }
        stud.setEgz(rand() % 10 + 1);
        cout << "Sugeneruoti namu darbu balai: ";
        for (int balas : stud.nd()) cout << balas << " ";
        cout << "\nSugeneruotas egzamino balas: " << stud.egz() << "\n";
        stud.apskaiciuotiGalutini();
        s.push_back(stud);
    }
}
