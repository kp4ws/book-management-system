#include <string>

class BookModel
{
public:
    BookModel(int newISBN, std::string newTitle, std::string newDescription)
    {
        //uid = generateUID();
        isbn = newISBN;
        title = newTitle;
        description = newDescription;
    }
    ~BookModel() {}

    // setters
    void setISBN(int newISBN) { isbn = newISBN; }
    void setTitle(std::string newTitle) { title = newTitle; }
    void setDescription(std::string newDescription) { description = newDescription; }

    // getters
    int getISBN() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getDescription() const { return description; }

private:
    int uid;
    int isbn;
    std::string title;
    std::string description;
};