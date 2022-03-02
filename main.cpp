#include <iostream>
#include <vector>
#include "myAlgorithm.h"
#include "OptUHA.h"
#include <vector>

const int max_exec = 30;


//
// MUHIRWA GABO Oreste & GEILLER Valentin
//


void launch(){

    srand(time(NULL));
    double moyenne = 0;
    vector<double> meilleur;
    vector<double> resultat;

    for (int nbexec = 0; nbexec < max_exec; ++nbexec) {

        cout << "Execution " << nbexec;

        myAlgorithm algo{};

        meilleur.push_back(algo.solve());

        moyenne += meilleur[nbexec] / max_exec;
        resultat.push_back(meilleur[nbexec]);
    }

    double MeilleurDesMeilleurs = meilleur[0];
    for (int i = 0; i < meilleur.size(); ++i) {
        if (MeilleurDesMeilleurs > meilleur[i]) {
            MeilleurDesMeilleurs = meilleur[i];
        }
    }

    double ecartype = 0;
    double somme = 0;
    for (int i = 0; i < resultat.size(); ++i)
    {
        somme += pow(abs(resultat[i] - moyenne), 2);
    }
    ecartype = sqrt(somme / resultat.size());

    cout << endl;
    cout << "Moyenne = " << moyenne << endl;
    cout << "Ecart Type = " << ecartype << endl;
    cout << "Meilleur Solution = " << MeilleurDesMeilleurs << endl;
}


int main() {
    launch();
    return 0;
}