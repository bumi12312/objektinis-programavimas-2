#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>

double vidurkis(const std::vector<int>& nd);
double mediana(std::vector<int> nd);

class Studentas {
private:

    std::string vardas_;
    std::string pavarde_;
    std::vector<int> nd_;
    int egz_;
    double galutinisVid_;
    double galutinisMed_;

public:
    // numatytasis konstruktorius - apsaugo nuo atsitiktiniu reiksmiu (undefined behavior)
    Studentas() : egz_(0), galutinisVid_(0.0), galutinisMed_(0.0) {}
    // konstruktorius is srauto - leidzia sukurti objekta tiesiai nuskaitant eilute
    Studentas(std::istream& is);
    // kopijavimo konstruktorius - iskvieciamas kopijuojant objekta (pvz., push_back)
    Studentas(const Studentas& kitas);
    // kopijavimo priskyrimo operatorius - iskvieciamas rasant a = b
    Studentas& operator=(const Studentas& kitas);
    // automatiskai isvalo objekto atminti jam sunykstant
    ~Studentas();

    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline int egz() const { return egz_; }
    inline const std::vector<int>& nd() const { return nd_; }
    inline double galutinisVid() const { return galutinisVid_; }
    inline double galutinisMed() const { return galutinisMed_; }

    double galBalas(double (*krit)(std::vector<int>) = mediana) const;
s
    std::istream& readStudent(std::istream& is);
    void setVardas(const std::string& v) { vardas_ = v; }
    void setPavarde(const std::string& p) { pavarde_ = p; }
    void setEgz(int e) { egz_ = e; }
    void pridetiNd(int balas) { nd_.push_back(balas); }
    void apskaiciuotiGalutini();
};

struct Kategorijos {
    std::vector<Studentas> vargsiukai;
    std::vector<Studentas> kietiakiai;
};

bool compare(const Studentas& a, const Studentas& b);
bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalGalutini(const Studentas& a, const Studentas& b);
bool comparePagalEgza(const Studentas& a, const Studentas& b);

#endif
