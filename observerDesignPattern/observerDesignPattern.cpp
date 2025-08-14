#include <bits/stdc++.h>
using namespace std;

class IUser;

class IChannel {
  public:
    virtual void addSubscriber(IUser *user) = 0;
    virtual void removeSubscriber(IUser *user) = 0;
    virtual string getInformation() = 0;
    virtual void notify() = 0;
    virtual void updateInformation(string newData) = 0;
    string name;
    virtual ~IChannel() {}
};

class IUser {
  public:
    virtual void subscribe(IChannel *channel) = 0;
    virtual void unsubscribe(IChannel *channel) = 0;
    virtual void getInfo(string name) = 0;
    virtual ~IUser() {}
};

class youtubeChannel : public IChannel {
    vector<IUser *> subscribers;
    string information;

  public:
    youtubeChannel(string info, string name) : information(info) {
        this->name = name;
    }

    void addSubscriber(IUser *user) override { subscribers.push_back(user); }

    void removeSubscriber(IUser *user) override {
        subscribers.erase(remove(subscribers.begin(), subscribers.end(), user),
                          subscribers.end());
    }

    string getInformation() override { return information; }

    void notify() override {
        for (auto indUser : subscribers) {
            indUser->getInfo(name);
        }
    }

    void updateInformation(string newData) override {
        this->information = newData;
        this->notify();
    }
};

class WatchingUser : public IUser {
    vector<IChannel *> listOfSubscribedChannels;

  public:
    void subscribe(IChannel *channel) override {
        listOfSubscribedChannels.push_back(channel);
        channel->addSubscriber(this);
    }

    void unsubscribe(IChannel *channel) override {
        listOfSubscribedChannels.erase(remove(listOfSubscribedChannels.begin(),
                                              listOfSubscribedChannels.end(),
                                              channel),
                                       listOfSubscribedChannels.end());
        channel->removeSubscriber(this);
    }

    void getInfo(string name) override {
        for (auto indChannel : listOfSubscribedChannels) {
            if (indChannel->name == name)
                cout << "new info after change for channel: " << name << " -> "
                     << indChannel->getInformation() << endl;
        }
    }
};

int main() {
    // Creating objects dynamically
    IChannel *yt1 = new youtubeChannel("nahanaha", "codeWithSahil");
    IUser *user1 = new WatchingUser();
    IUser *user2 = new WatchingUser();

    user1->subscribe(yt1);
    user2->subscribe(yt1);

    yt1->updateInformation("hiiii");

    // Cleanup memory
    delete yt1;
    delete user1;
    delete user2;

    return 0;
}
