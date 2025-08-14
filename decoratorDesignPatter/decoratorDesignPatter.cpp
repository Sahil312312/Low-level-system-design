#include <bits/stdc++.h>
using namespace std;

class Character {
  public:
    virtual string getAbilities() = 0;
    virtual ~Character() {}
};

class Mario : public Character {
  public:
    string getAbilities() { return "Mario"; }
};

class CharacterDecorator : public Character {
  protected:
    Character *character;

  public:
    CharacterDecorator(Character *c) { this->character = c; }
};

class HiegthUp : public CharacterDecorator {
  public:
    HiegthUp(Character* c) : CharacterDecorator(c) {} 

    string getAbilities(){
        return character->getAbilities() + " Heigth Power has been added ";
    }
};

class StarAbility : public CharacterDecorator {
  public:
  StarAbility(Character* c) : CharacterDecorator(c) {}

    string getAbilities() { return character->getAbilities() + " Star Power has been added "; }
};

class GunUpPower : public CharacterDecorator {
    public:

    GunUpPower(Character* c) : CharacterDecorator(c) {}
    
      string getAbilities() { return character->getAbilities() + " Gun power has been added"; }
};

int main() {

    Character *mario = new Mario();
    cout<<"Character : "<<mario->getAbilities()<<endl;

    mario = new HiegthUp(mario);
    cout<<"Character : "<<mario->getAbilities()<<endl;

    mario = new StarAbility(mario);
    cout<<"Character : "<<mario->getAbilities()<<endl;


    return 0;
}