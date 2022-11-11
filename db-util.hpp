#include <fstream>
#include <iostream>
#include <unordered_map>
#include <iterator>

class DbUtil
{
    public:
        std::unordered_map<int, Book> retrieveFromDatabase()
        {
            std::unordered_map<int, Book> resultList;
            std::ifstream file;
            file.open(FILE_NAME, std::ios::in);
            std::string fileText;
            
            int delimiterIndex = 0;
            while (std::getline(file, fileText))
            {
                //std::string test1 = fileText.substr(0, fileText.find(begin(0), fileText.length(), ","));

                std::string test2 = fileText.substr(fileText.find(",") + 1, fileText.find(","));
                std::string test3 = fileText.substr(fileText.find(",") + delimiterIndex, fileText.find(","));

                //std::cout << test1 << "\n";
                //std::cout << fileText;
            }
            file.close();

            return resultList;
        }

        void saveToDatabase(std::unordered_map<int, Book> bookList)
        {
            std::ofstream file;
            file.open(FILE_NAME, std::ios::out | std::ios::app);
            for (std::unordered_map<int, Book>::iterator it = bookList.begin(); it != bookList.end(); ++it)
            {
                int key = it->first;
                Book book = it->second;
                const std::string bookFormat = std::to_string(book.getISBN()) + "," + book.getTitle() + "," + book.getDescription();
                file << bookFormat + "\n";
            }
            file.close();
        }

    private:
    const std::string FILE_NAME = "db.csv";
};