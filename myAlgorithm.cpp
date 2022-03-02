#include "myAlgorithm.h"

myAlgorithm::myAlgorithm() :
        d_population{}
{
    initializePopulation();
    calculeProbabilite();
    FindBestSolution();
}

void myAlgorithm::initializePopulation() {
    d_population.resize(pop_size);
    for (int i = 0; i < pop_size; ++i) {
        d_population[i] = create_new_individual();
    }
}

double myAlgorithm::maxFitness() const {
    double max = d_population[0].getFitnessValue();
    for (int i = 0; i < d_population.size(); ++i) {
        if (max <= d_population[i].getFitnessValue()) {
            max = d_population[i].getFitnessValue();
        }
    }
    return max;
}

int myAlgorithm::indexOfSolutionWhereSuperiorOfLimit() const {
    int index = 0;
    double max = maxFitness();
    for (int i = 0; i < d_population.size(); ++i) {
        if (d_population[i].getFitnessValue() == max)
            index = i;
    }
    return index;
}

void myAlgorithm::FindBestSolution() {
    d_bestFS = d_population[indexOfSolutionWhereSuperiorOfLimit()];
}

void myAlgorithm::calculeProbabilite() {
    d_probabilite.resize(d_population.size());
    double maxfitness = maxFitness();
    for (int i = 0; i < d_probabilite.size(); ++i) {
        double fit = d_population[i].getFitnessValue();
        d_probabilite[i] = 0.9 * (fit / maxfitness) + 0.1;
    }
}

void myAlgorithm::employedBeePhase() {
    for (int i = 0; i < NB_ABEILLES_EMPLOYE; ++i) {
        FoodSource tmpFS = d_population[i];

        int variableAChanger = generate_random_int(0,dimension-1);
        int partenaire = generate_random_int(0, pop_size - 1);

        while (partenaire == i)
            partenaire = generate_random_int(0, pop_size - 1);

        double Xi = tmpFS.getCoordAt(variableAChanger);
        double XPartner = d_population[partenaire].getCoordAt(variableAChanger);

        double phi = generate_random_double(-1, 1);
        double Xnew = newCoords(Xi, XPartner);

        verifLimit(Xnew);

        tmpFS.setCoordAt(variableAChanger, Xnew);

        auto coords = tmpFS.getCoords();

        tmpFS.setObjectifValue(fct_obj(coords));
        tmpFS.setFitnessValue(fitness(tmpFS.getObjectifValue()));

        if (greedySelection(d_population[i].getFitnessValue(), tmpFS.getFitnessValue())) {
            tmpFS.resetTrial();
            d_population[i] = tmpFS;
        }
        else {
            d_population[i].incrementeTrial();
        }
    }
}

void myAlgorithm::onLookerBeePhase() {
    calculeProbabilite();
    int foodSource = 0, onLookerBee = 0;
    while (onLookerBee <= NB_ABEILLES_SPECTATEUR) {
        double r = generate_random_double(0, 1);
        if (r < d_probabilite[foodSource]) {
            employedBeePhase();
            onLookerBee = onLookerBee + 1;
        }
        foodSource = foodSource + 1;
        if (foodSource >= d_population.size()) {
            foodSource = 0;
        }
    }
}

void myAlgorithm::scoutBeePhase() {
    auto index = indexOfSolutionWhereSuperiorOfLimit();

    FoodSource FS = create_new_individual();

    if (FS.getObjectifValue() < d_bestFS.getObjectifValue()) {
        d_population[index] = FS;
    }
}

double myAlgorithm::solve() {
    double meilleur = DBL_MAX;


    // GENERATION
    for (int iter = 0; iter < total_func_evals; ++iter) {

        // EMPLOYES BEES PHASE
        employedBeePhase();

        // ONLOOKER BEES PHASE
        onLookerBeePhase();

        // SCOUT BEES PHASE
        FindBestSolution();
        scoutBeePhase();

        if (meilleur > d_bestFS.getObjectifValue()) {
            meilleur = d_bestFS.getObjectifValue();
        }
    }

    std::cout << " - Meilleur : " << meilleur << endl;
    return meilleur;
}