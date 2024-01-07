#include "Conge.h"
#include "HR.h"
#include<cstdlib>
#include <iomanip>
#include <chrono>
#include <ctime>
#include<iostream>
#include <sstream>

using namespace std;
Conge::Conge()
{

}

Conge::~Conge()
{

}
 void Conge::calculateDifference(const char* date1, const char* date2)
{
    HR conge;

    // Convertir les chaînes de caractères en objets std::tm
    tm time1 = {};
    istringstream iss1(date1);
    iss1 >> get_time(&time1, "%d-%m-%Y");

    tm time2 = {};
    istringstream iss2(date2);
    iss2 >> get_time(&time2, "%d-%m-%Y");

    // Calculer la différence en secondes entre les deux dates
    time_t time1Seconds = mktime(&time1);
    time_t time2Seconds = mktime(&time2);
    double differenceSeconds = difftime(time2Seconds, time1Seconds);

    // Calculer la différence en jours
    int differenceDays = static_cast<int>(differenceSeconds / (60 * 60 * 24));

    conge.confermerConge(differenceDays);
}
