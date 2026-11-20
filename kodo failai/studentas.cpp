#include "studentas.h"
#include <algorithm>
#include <sstream>

using namespace std;

double vidurkis(const vector<int>& nd) {
    if (nd.empty()) return 0.0;
    int sum = 0;
    for (int balas : nd) {
        sum += balas;
    }
    return (double)sum / nd.size();
}

double mediana(vector<int> nd) {
    if (nd.empty()) return 0.0;
    sort(nd.begin(), nd.end());
    int n = nd.size();
    if (n % 2 == 1) {
        return nd[n / 2];
    }
    return (nd[n / 2 - 1] + nd[n / 2]) / 2.0;
}

Studentas::Studentas(istream& is) : egz_(0), galutinisVid_(0.0), galutinisMed_(0.0) {
    readStudent(is);
}

Studentas::Studentas(const Studentas& kitas) {
    vardas_ = kitas.vardas_;
    pavarde_ = kitas.pavarde_;
    nd_ = kitas.nd_;
    egz_ = kitas.egz_;
    galutinisVid_ = kitas.galutinisVid_;
    galutinisMed_ = kitas.galutinisMed_;
}

Studentas& Studentas::operator=(const Studentas& kitas) {
    if (this != &kitas) {
        vardas_ = kitas.vardas_;
        pavarde_ = kitas.pavarde_;
        nd_ = kitas.nd_;
        egz_ = kitas.egz_;
        galutinisVid_ = kitas.galutinisVid_;
        galutinisMed_ = kitas.galutinisMed_;
    }
    return *this;
}

Studentas::~Studentas() {
    nd_.clear();
}

void Studentas::apskaiciuotiGalutini() {
    galutinisVid_ = 0.4 * vidurkis(nd_) + 0.6 * egz_;
    galutinisMed_ = 0.4 * mediana(nd_) + 0.6 * egz_;
}

double Studentas::galBalas(double (*krit)(vector<int>)) const {
    return 0.4 * krit(nd_) + 0.6 * egz_;
}

istream& Studentas::readStudent(istream& is) {
    vardas_.clear();
    pavarde_.clear();
    nd_.clear();
    egz_ = 0;

    string eilute;
    while (getline(is, eilute)) {
        if (!eilute.empty() && eilute != "\r") break;
    }
    if (eilute.empty()) return is;

    istringstream iss(eilute);
    iss >> vardas_ >> pavarde_;
    int balas;
    while (iss >> balas) {
        nd_.push_back(balas);
    }
    if (!nd_.empty()) {
        egz_ = nd_.back();
        nd_.pop_back();
    }
    apskaiciuotiGalutini();
    return is;
}
bool compare(const Studentas& a, const Studentas& b) {
    if (a.pavarde() == b.pavarde()) {
        return a.vardas() < b.vardas();
    }
    return a.pavarde() < b.pavarde();
}
bool comparePagalPavarde(const Studentas& a, const Studentas& b) {
    return a.pavarde() < b.pavarde();
}
bool comparePagalGalutini(const Studentas& a, const Studentas& b) {
    return a.galutinisVid() < b.galutinisVid();
}
bool comparePagalEgza(const Studentas& a, const Studentas& b) {
    return a.egz() < b.egz();
}
