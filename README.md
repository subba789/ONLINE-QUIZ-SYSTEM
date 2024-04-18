# ONLINE-QUIZ-SYSTEM
• Designed and developed a C++ quiz application with a dynamic menu-driven interface, offering a seamless user experience. • Implemented classes for questions and quizzes, incorporating file I/O for efficient data storage,retrieval, and management within the application.

 Project Description:

Objective: 
The Online Quiz System is designed to allow users to take quizzes on various topics. It provides functionalities for registering users, adding custom questions, shuffling questions, and displaying registered users.

Components:

1. Question Class:
   - This class represents a single quiz question and contains:
     - `questionText`: A string storing the text of the question.
     - `options`: A vector of strings storing the multiple-choice options.
     - `correctOption`: An integer representing the index of the correct option.

2. User Class:
   - This class represents a user participating in the quiz and contains:
     - `username`: A string storing the username of the user.

3. Quiz Class: 
   - This class manages the entire quiz system and contains:
     - `questions`: A vector of `Question` objects representing the quiz questions.
     - `totalScore`: An integer representing the total score achieved in the quiz.
     - `totalTime`: An integer representing the total time taken to complete the quiz.
     - `users`: A vector of `User` objects representing registered users.
     
4. Main Function:
   - The main function provides a menu-driven interface for users to interact with the quiz system.
   - Users can:
     - Start the quiz by providing their username.
     - Add custom questions to the quiz (requires a password for access).
     - Register as a new user.
     - Shuffle the quiz questions (requires a password for access).
     - Display registered users.
     - Exit the program.

Features:
- User Registration: Users can register themselves by providing a username.
- Quiz Taking: Users can start the quiz and answer multiple-choice questions.
- Custom Question Addition: The owner of the quiz system can add custom questions to the quiz.
- Question Shuffling: The owner can shuffle the questions to provide variety in each quiz session.
- Scoring: Users receive scores based on the accuracy and speed of their responses.
- User Display: Registered users can be displayed to track user participation.

Security Measures:
- Access to certain functionalities (adding custom questions and shuffling questions) requires a password for verification.

Note:
- The quiz system uses classes and vectors to manage questions and users efficiently.
- It incorporates time tracking to calculate the time taken for each question and overall quiz completion time.
- The scoring mechanism rewards faster responses with higher scores.
- Users are prompted to register before starting the quiz if they are not already registered.
