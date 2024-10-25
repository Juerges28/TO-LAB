#ifndef SMARTWATCH_H
#define SMARTWATCH_H

#include "Termometro.h"
#include "Reloj.h"
#include "MP3.h"

class Smartwatch : public Termometro, public Reloj, public MP3 {
public:
    Smartwatch();
    Smartwatch(float temperature, const std::string& time, const std::vector<std::string>& songList);
};

#endif // SMARTWATCH_H