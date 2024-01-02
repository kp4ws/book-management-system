# book-management-system
## About
A command-line application to manage an inventory of books.  
- I developed this application as a project based approach to learn C++.

## Separation of concerns
While developing this application, I tried to separate the concerns into their own implementaton files.
- **App** class is the entry point to the application.
- **Server** class initiates the conversation with the InputHandler class.
- **InputHandler** class deals with user input.
- **DataHandler** class performs operations from the result of a user input.
- **DbUtil** class deals with database operations, which in this project uses a csv file to store and retrieve data.

## Future updates and application legacy
- While building this app, I wasn't very familiar with C++ syntax. Since then I've become very familiar with C++ through the various assignments I've completed for my school courses.
- I've tried to make the code for this application modular, with high cohesion and loose coupling. Future iterations could include integrating a GUI menu or perhaps using the code as a base for other projects, such as a movie management system.

## Sample Program Run
![image](https://github.com/kp4ws/book-management-system/assets/58745400/a1f0fa28-cd1b-4c49-a3cd-ef7b46c3cbca)  

---

![image](https://github.com/kp4ws/book-management-system/assets/58745400/4761bcb2-b710-4d70-acef-bd7f06bde718)
