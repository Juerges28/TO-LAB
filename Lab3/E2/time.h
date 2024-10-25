#ifndef TIME_H
#define TIME_H

#include <memory>

class Time
{
    private:
        std::unique_ptr<int> hour;
        std::unique_ptr<int> minute;
        std::unique_ptr<int> second;
    
    public:
        // Constructor con valores por defecto
        Time(const int h = 0, const int m = 0, const int s = 0);

        // Destructor
        ~Time();

        // Setter
        void setTime(const int h, const int m, const int s);

        // Imprime la descripción del objeto en formato "hh:mm:ss"
        void print() const; // readonly

        // Compara 2 objetos Time
        bool equals(const Time&);
};

#endif