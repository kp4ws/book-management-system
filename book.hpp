#include <string>

class Book
{
public:
    Book(int newISBN, std::string newTitle, std::string newDescription)
    {
        isbn = newISBN;
        title = newTitle;
        description = newDescription;
    }
    ~Book() {}

    // setters
    void setISBN(int newISBN) { isbn = newISBN; }
    void setTitle(std::string newTitle) { title = newTitle; }
    void setDescription(std::string newDescription) { description = newDescription; }

    // getters
    int getISBN() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getDescription() const { return description; }
    
    void display() {std::cout << isbn << "," << title << "," << description << std::endl;}

private:
    int uid;
    int isbn;
    std::string title;
    std::string description;
};