#include "FoodSource.h"

FoodSource::FoodSource() : d_coords{}, d_objectifValue{ 0 }, d_fitnessValue{ 0 }, d_trial{ 0 } {}

FoodSource::FoodSource(vector<double> coords, double objectifValue, double fitnessValue, int trial) :
        d_coords{ coords }, d_objectifValue{ objectifValue }, d_fitnessValue{ fitnessValue }, d_trial{ trial }
{}


double FoodSource::getCoordAt(int i) const {
    return d_coords[i];
}


vector<double> FoodSource::getCoords() const {
    return d_coords;
}


double FoodSource::getObjectifValue() const {
    return d_objectifValue;
}


double FoodSource::getFitnessValue() const {
    return d_fitnessValue;
}


int FoodSource::getTrial() const {
    return d_trial;
}

void FoodSource::setCoordAt(int i, double valeur) {
    d_coords[i] = valeur;
}


void FoodSource::setObjectifValue(double objectifValue) {
    d_objectifValue = objectifValue;
}


void FoodSource::setFitnessValue(double fitnessValue) {
    d_fitnessValue = fitnessValue;
}


void FoodSource::incrementeTrial() {
    d_trial++;
}


void FoodSource::resetTrial() {
    d_trial = 0;
}


void FoodSource::printFoodSource() const {
    std::cout << "Objectif Value : " << d_objectifValue << std::endl;
    std::cout << "Fitness Value : " << d_fitnessValue << std::endl;
}