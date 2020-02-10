//
// Created by Sergey Murtazin on 19/11/2019.
//

#ifndef TESTPROJ1_MONSTER_H
#define TESTPROJ1_MONSTER_H


#include <string>

class Monster {

private:
    int size;
    int power = 100;
    std::string name;

public:
    Monster(int siza, int power, const std::string &name);
    virtual ~Monster();

    int getSize() const;

    void setSize(int size);

    int getPower() const;

    void setPower(int power);

    const std::string &getName() const;

    void setName(const std::string &name);
};


#endif //TESTPROJ1_MONSTER_H
