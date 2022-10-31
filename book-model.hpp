#include <string>

class BookModel
{
public:
    BookModel(int id, std::string name);
    ~BookModel() {}

    void setID(int newID)
    {
        id = newID;
    }

    void setName(std::string newName)
    {
        name = newName;
    }

    int getID() const;
    std::string getName() const;

private:
    int id;
    std::string name;
};