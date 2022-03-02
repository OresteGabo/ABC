#pragma once
#ifndef _MYALGO_OPT_
#define _MYALGO_OPT_
#include "OptUHA.h"
#include<cfloat>

class myAlgorithm : OptUHA
{
protected:
    // déclarer les paramètres de votre algorithme ici

    int NB_ABEILLES_EMPLOYE = pop_size / 2;
    int NB_ABEILLES_SPECTATEUR = pop_size / 2;
    int NB_FOOD_SOURCE = pop_size / 2;
    int LIMIT_TRIAL = NB_ABEILLES_EMPLOYE * dimension;

    vector<FoodSource> d_population;
    vector<double> d_probabilite;
    FoodSource d_bestFS;

public:
    double solve();
    myAlgorithm();
    ~myAlgorithm() = default;

    // Ajouter d'autres fonctions liées à votre algorithme ici

    void initializePopulation();
    double maxFitness() const;
    int indexOfSolutionWhereSuperiorOfLimit() const;
    void FindBestSolution();
    void calculeProbabilite();
    void employedBeePhase();
    void onLookerBeePhase();
    void scoutBeePhase();
};

#endif