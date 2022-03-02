#pragma once
#ifndef _OPTUHA_
#define _OPTUHA_
#include <vector>
#include <random>
#include "iostream"
#include "FoodSource.h"
using namespace std;

class OptUHA
{
protected:
    int	pop_size = 100;

    // taille de la population
    int	dimension = 30;									// dimension du problème
    int	total_func_evals = 50;
public:
    int getTotalFuncEvals() const;

    void setTotalFuncEvals(int totalFuncEvals);

protected:
    // nombre total d'évaluation
    int	max_func_eval = total_func_evals * pop_size;	// nombre total d'appel de la fonction objectif

    double LOWER_LIMIT = -600;
    double UPPER_LIMIT = 600;

protected :
    double fct_obj(vector<double>& coords) const;

    double Sphere(const vector<double>& coords) const;
    double Rosenbrock(const vector<double>& S) const;
    double Rastrigin(const vector<double>& S) const;
    double Griewank(const vector<double>& S) const;

    double fitness(double objectifValue) const;

    vector<FoodSource> GenerateRandomPop();
    double generate_random_double();
    double generate_random_double(double lower, double upper);
    int generate_random_int(int from, int to);
    double newCoords(double X, double XPartner);
    FoodSource create_new_individual();
    void print_solution(const FoodSource& FS) const;
    void verifLimit(double& Xnew);
    bool greedySelection(double oldFit, double newFit);

    OptUHA() = default;
    ~OptUHA() = default;

    public:
            int getPopSize() const;

    void setPopSize(int popSize);

    int getDimension() const;

    void setDimension(int dimension);

    double getLowerLimit() const;

    void setLowerLimit(double lowerLimit);

    double getUpperLimit() const;

    void setUpperLimit(double upperLimit);
};

#endif