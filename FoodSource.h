#ifndef FOODSOURCE_H
#define FOODSOURCE_H

#include <vector>
#include <iostream>

using std::vector;

class FoodSource {
public:
    FoodSource();
    FoodSource(vector<double> coords, double objectifValue, double fitnessValue, int trial = 0);

    double getCoordAt(int i) const;
    vector<double> getCoords() const;
    double getObjectifValue() const;
    double getFitnessValue() const;
    int getTrial() const;

    void setCoordAt(int i, double valeur);
    void setObjectifValue(double objectifValue);
    void setFitnessValue(double fitnessValue);

    void incrementeTrial();
    void resetTrial();
    void printFoodSource() const;
private:
    vector<double> d_coords;
    double d_objectifValue;
    double d_fitnessValue;
    int d_trial;
};

#endif // !FOODSOURCE_H