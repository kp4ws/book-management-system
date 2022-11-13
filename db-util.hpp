#include <fstream>
#include <iostream>
#include <unordered_map>

class DbUtil
{
public:
    std::unordered_map<int, Book> retrieveFromDatabase()
    {
        std::unordered_map<int, Book> resultList;
        std::string fileText;
        std::ifstream file;

        file.open(FILE_NAME, std::ios::in);
        while (std::getline(file, fileText))
        {
            int isbn = stoi(fileText.substr(0, fileText.find_first_of(',')));
            std::string title = fileText.substr(fileText.find_first_of(',') + 1, fileText.find_last_of(',') - fileText.find_first_of(',') - 1);
            std::string description = fileText.substr(fileText.find_last_of(',') + 1, fileText.length());

            Book book(isbn, title, description);
            resultList.insert({isbn, book});
        }
        file.close();

        return resultList;
    }

    void saveToDatabase(Book book)
    {
        std::ofstream file;
        const std::string bookFormat = std::to_string(book.getISBN()) + "," + book.getTitle() + "," + book.getDescription();
        file.open(FILE_NAME, std::ios::out | std::ios::app);
        file << bookFormat + "\n";
        file.close();

        // THIS CODE IS USED TO REPLACE ENTIRE FILE
        //  for (std::unordered_map<int, Book>::iterator it = bookList.begin(); it != bookList.end(); ++it)
        //  {
        //      int key = it->first;
        //      Book book = it->second;
        //      const std::string bookFormat = std::to_string(book.getISBN()) + "," + book.getTitle() + "," + book.getDescription();
        //      file << bookFormat + "\n";
        //  }
    }

private:
    const std::string FILE_NAME = "db.csv";
};