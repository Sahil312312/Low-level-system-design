#include <bits/stdc++.h>
using namespace std;

// Design a system for payment through various methods eg UPIPayment,CardPayment, netBankingPayment

// abstract strategy class

class Client;
unordered_map<string, Client *> clientToObj;

class PaymentMethods
{
public:
    unordered_map<string, bool> paymentToStatusMap;

    virtual string pay(string senderId, int amount, string reciverId) = 0;
    virtual bool paymentStatus(string orderId) = 0;
};

// Concrete strategy class
class UPIPayment : public PaymentMethods
{
public:
    string pay(string senderId, int amount, string reciverId)
    {
        string orderId = senderId + to_string(amount) + reciverId + "UPI";
        paymentToStatusMap[orderId] = true;
        cout << "Payment is done" << endl;
        return orderId;
    }

    bool paymentStatus(string orderId)
    {
        if (paymentToStatusMap.find(orderId) != paymentToStatusMap.end())
            return paymentToStatusMap[orderId];
        return false;
    }
};

class CardPayment : public PaymentMethods
{
    string pay(string senderId, int amount, string reciverId)
    {
        string orderId = senderId + to_string(amount) + reciverId + "Card";
        paymentToStatusMap[orderId] = true;
        cout << "Payment is done" << endl;
        return orderId;
    }

    bool paymentStatus(string orderId)
    {
        if (paymentToStatusMap.find(orderId) != paymentToStatusMap.end())
            return paymentToStatusMap[orderId];
        return false;
    }
};

class NetBankingPayment : public PaymentMethods
{
public:
    string pay(string senderId, int amount, string reciverId)
    {
        string orderId = senderId + to_string(amount) + reciverId + "NetBanking";
        paymentToStatusMap[orderId] = true;
        cout << "Payment is done" << endl;
        return orderId;
    }

    bool paymentStatus(string orderId)
    {
        if (paymentToStatusMap.find(orderId) != paymentToStatusMap.end())
            return paymentToStatusMap[orderId];
        return false;
    }
};

// Context Class
class Payment
{
public:
    PaymentMethods *paymentMode;

public:
    Payment(PaymentMethods *mode) : paymentMode(mode) {};

    void updatePaymentMode(PaymentMethods *mode) { paymentMode = mode; }

    string processPayment(string senderId, string recieverId, int amount)
    {
        return paymentMode->pay(senderId, amount, recieverId);
    }

    bool paymentStatus(string orderId)
    {
        return paymentMode->paymentStatus(orderId);
    }
};

// client
class Client
{
    string clientId;
    int balance;

public:
    Client(string userId, int bal) : clientId(userId), balance(bal) {};

    bool pay(string recieverId, int amount, Payment *payment)
    {
        if (balance <= amount)
        {
            cout << "Insufficent balance" << endl;
            return false;
        }

        balance -= amount;
        deductAmount(recieverId, amount);

        string orderId = payment->processPayment(clientId, recieverId, amount);
        return true;
    }

    void deductAmount(string recieverId, int amount)
    {
        clientToObj[recieverId]->balance += amount;
    }

    void showCurrentBalance()
    {
        cout << "Current balance of user : " << balance;
    }
};



int main()
{

    Client *client1 = new Client("ID1", 5000);
    Client *client2 = new Client("ID2", 1000);
    Client *client3 = new Client("ID3", 3000);

    clientToObj["ID1"] = client1;
    clientToObj["ID2"] = client2;
    clientToObj["ID3"] = client3;

    unordered_map<string, Payment *> paymentModesProcessers;

    paymentModesProcessers["UPI"] = new Payment(new UPIPayment());
    paymentModesProcessers["Card"] = new Payment(new CardPayment());
    paymentModesProcessers["NetBanking"] = new Payment(new NetBankingPayment);

    client1->pay("ID2", 1000, paymentModesProcessers["UPI"]);
    client2->pay("ID3", 8000, paymentModesProcessers["NetBanking"]);

    client1->showCurrentBalance();
    cout<<endl;
    client2->showCurrentBalance();

    return 0;
}