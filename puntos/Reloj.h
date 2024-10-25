#ifndef RELOJ_H
#define RELOJ_H

#include <string>

class Reloj {
private:
    std::string time;

public:
    Reloj();
    std::string getTime() const;
    void setTime(const std::string& time);
};

#endif // RELOJ_H