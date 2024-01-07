#ifndef CONGE_H
#define CONGE_H
#include<string.h>

class Conge
{
    public:
        Conge();
        virtual ~Conge();
      static void calculateDifference(const char* date1, const char* date2);
    protected:

    private:
        int year;
    int month;
    int day;

    static int nbEmp;
     int nb;
};

#endif // CONGE_H
