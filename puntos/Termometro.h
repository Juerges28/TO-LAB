#ifndef TERMOMETRO_H
#define TERMOMETRO_H

class Termometro {
private:
    float temperature;

public:
    Termometro();
    float getTemperature() const;
    void setTemperature(float temp);
};

#endif // TERMOMETRO_H