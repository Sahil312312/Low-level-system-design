#include <bits/stdc++.h>
using namespace std;

class DocumentElement
{
public:
    virtual string render() = 0;
    
    void test(){
        cout<<"try";
    }
};

class textElement : public DocumentElement
{
    string text;

public:
    textElement(string text)
    {
        this->text = text;
    }

    string render() override
    {
        return text;
    }
};

class imageElement : public DocumentElement
{
    string imagePath;

public:
    imageElement(string url)
    {
        this->imagePath = url;
    }

    string render() 
    {
        return "[Image : " + imagePath + " ] ";
    }
    // void test () {
    //     cout<<"Hi";
    // }
};

class newLine : public DocumentElement
{
public:
    string render() override
    {
        return "\n";
    }
};

class tabSpace : public DocumentElement
{
public:
    string render() override
    {
        return "\t";
    }
};

class client
{
public:
    string name;
    int maxCapicity;
    int currCapicity;

    client(string name)
    {
        this->name = name;
        this->maxCapicity = 5;
    }
};

class Document
{
private:
    string documentName;
    vector<DocumentElement *> elements;
    client *owner;

public:
    Document(string documentName, client *owner)
    {
        cout << "New Document " << documentName << " created" << endl;
        this->documentName = documentName;
        this->owner = owner;
    }

    void addElement(DocumentElement *elem)
    {
        elements.push_back(elem);
    }

    void renderDocument()
    {
        cout << "Start of document : " << documentName << endl;
        for (auto element : elements)
            cout << element->render() << endl;
        cout << "End document : " << documentName << endl;
    }
};

class DocumentEditor
{
private:
    vector<client *> clientArray;
    unordered_map<client *, set<Document *>> clientToDocumentMap;

public:
    DocumentEditor()
    {
        cout << "DocumentEditor started successfully 🧨" << endl;
    }

    void addUser(client *cl)
    {
        clientArray.push_back(cl);
    }

    void addDocumentToMap(client *cl, Document *doc)
    {
        clientToDocumentMap[cl].insert(doc);
    }

    set<Document *> getAllDocOfUser(client *cl)
    {
        return clientToDocumentMap[cl];
    }
};

int main()
{

    client *cl1 = new client("sahil");
    client *cl2 = new client("somya");

    DocumentEditor *documentEditor = new DocumentEditor();
    cout<<endl;
    documentEditor->addUser(cl1);
    documentEditor->addUser(cl2);

    Document *d1u1 = new Document("doc1", cl1);
    Document *d2u1 = new Document("doc2", cl2);

    cout<<endl;

    textElement *txt1 = new textElement("Hello I am Sahil");
    textElement *txt2 = new textElement("Bye");

    newLine *newl = new newLine();
    tabSpace *tbS = new tabSpace();
    imageElement *img1 = new imageElement("//IMG//");

    d1u1->addElement(txt1);
    d1u1->addElement(tbS);
    d1u1->addElement(img1);
    d1u1->addElement(newl);
    d1u1->addElement(txt2);

    // d1u1->renderDocument();
    img1->test();

    return 0;
}