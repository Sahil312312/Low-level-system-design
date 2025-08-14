#include <bits/stdc++.h>
using namespace std;

class ICommand {
  public:
    virtual void execute() = 0;
    // virtual void undo() = 0;
    virtual ~ICommand() {}
};

class Light {
    bool isOn;

  public:
    Light() {
        isOn = false;
        cout << "New light is created." << endl;
    }

    void changeState() {
        if (isOn) {
            isOn = false;
            cout << "Light is turned Off" << endl;
        } else {
            isOn = true;
            cout << "Light is turned On" << endl;
        }
    }
};

class Fan {
    bool isOn;

  public:
    Fan() {
        isOn = false;
        cout << "New fan is created." << endl;
    }

    void changeState() {
        if (isOn) {
            isOn = false;
            cout << "Fan is turned Off" << endl;
        } else {
            isOn = true;
            cout << "Fan is turned On" << endl;
        }
    }
};

class FanCommand : public ICommand {
    Fan *fan;

  public:
    FanCommand(Fan *f) { this->fan = f; }

    void execute() { fan->changeState(); }
};

class LightCommand : public ICommand {
    Light *light;

  public:
    LightCommand(Light *l) { this->light = l; }

    void execute() { light->changeState(); }
};

class RemoteController {
    static const int numButtons = 4;
    ICommand *buttons[numButtons];

  public:
    RemoteController() {
        for (int i = 0; i < numButtons; i++)
            buttons[i] = nullptr;
    }

    void setCommand(int idx, ICommand *cmd) {
        if (idx >= 0 && idx < numButtons) {
            if (buttons[idx] != nullptr)
                delete buttons[idx];
            buttons[idx] = cmd;
        }
    }

    void pressButton(int idx) {
        if (idx >= 0 && idx < numButtons && buttons[idx] != nullptr) {
            buttons[idx]->execute();
        } else {
            cout << "Error while assigning button!" << endl;
        }
    }
};

int main() {
    Light *livingRoomLight = new Light();
    Fan *ceilingFan = new Fan();

    RemoteController *remote = new RemoteController();

    remote->setCommand(0, new LightCommand(livingRoomLight));
    remote->setCommand(1, new FanCommand(ceilingFan));

    remote->pressButton(0);
    remote->pressButton(0);

    remote->pressButton(1);
    remote->pressButton(1);

    remote->pressButton(2);

    delete remote;
    delete livingRoomLight;
    delete ceilingFan;

    return 0;
}