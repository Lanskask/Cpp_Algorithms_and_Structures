

#ifndef TESTPROJ1_PLANET_H
#define TESTPROJ1_PLANET_H

#include <string>

class Planet {

private:
    int dencity;
    int size;
    std::string name;

public:
    Planet(int dencity, int size, const std::string &name);
    virtual ~Planet();

    int getSize() const;

    void setSize(int size);

    int getDencity() const;

    void setDencity(int dencity);

    [[nodiscard]] const std::string &getName() const;

    void setName(const std::string &name);
};

#endif // TESTPROJ1_PLANET_H
