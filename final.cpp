#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include<random>
using namespace std;

class Question {
private:
    string questionText;
    vector<string> options;
    int correctOption;

public:
   Question(string text, vector<string> opts, int correct)
         {
              questionText=text;
              options=opts;
               correctOption=correct;
        }

    void display() const {
        cout << questionText << endl;
        for (int i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool isCorrect(int response) const {
        return response == correctOption;
    }

    int answer()const{
        return correctOption;
    }
};

class User {
private:
    string username;

public:
    User(const string& name){
        username=name;
    }

    const string& getUsername() const {
        return username;
    }
};

class Quiz {
public:
    vector<Question> questions;
    int totalScore;
    int totalTime;
    vector<User>users;

public:
    Quiz(){
        totalScore=0;
        totalTime=0;
    }

    void addCustomQuestion() {
        string questionText;
        vector<string> options;
        int correctOption;

        cin.ignore(); // Clear the newline character from the buffer
        cout << "Enter the question: ";
        getline(cin, questionText);

        cout << "Enter the options (separated by commas): ";
        string optionsInput;
        getline(cin, optionsInput);

        // Tokenize optionsInput
        int pos = 0;
        string token;
        while ((pos = optionsInput.find(',')) != string::npos) {
            token = optionsInput.substr(0, pos);
            options.push_back(token);
            optionsInput.erase(0, pos + 1);
        }
        options.push_back(optionsInput);

        cout << "Enter the correct option number: ";
        cin >> correctOption;
        cin.ignore();

        questions.push_back(Question(questionText, options, correctOption));
        cout << "Custom question added!\n";
    }

    void registerUser() {
        string username;
        cout << "Enter your username: ";
        cin.ignore();
        getline(cin,username);

        users.push_back(User(username));
        cout << "User registered: " << username << endl;
    }


    void shuffleQuestions() {
        random_device rd;
        default_random_engine g(rd());
        shuffle(questions.begin(), questions.end(),g);
        cout << "Questions shuffled for variety!\n";
    }

    void displayMenu() const {
        cout << "\nMenu:\n";
        cout << "1. Start Quiz\n";
        cout << "2. Add Custom Question\n";
        cout << "3. Register User\n";
        cout << "4. Shuffle Questions\n";
        cout << "5. Display Users\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
    }

    void startQuiz(const User& user) {
        for (const Question& q : questions) {
            q.display();

            clock_t start = clock();

            int response;
            cout << "Your answer: ";
            cin >> response;

            clock_t end = clock();
            double elapsed = double(end - start) / CLOCKS_PER_SEC;
            totalTime += static_cast<int>(elapsed);

            if (q.isCorrect(response)) {
                int score = calculateScore(elapsed);
                cout << "Correct! Score: " << score << " points\n";
                totalScore += score;
            } else {
                cout << "Incorrect. The correct answer was: " << q.answer() << endl;
            }

            cout << "Time taken: " << elapsed << " seconds\n";
        }

        cout << user.getUsername() << ", Quiz completed. Your total score: " << totalScore << " points\n";
        cout << "Total time taken: " << totalTime << " seconds\n";
        totalScore = 0; // Reset the total score and total time for potential future quizzes
        totalTime = 0;
    }

    void displayUsers() const {
        cout << "\nRegistered Users:\n";
        for (const User& user : users) {
            cout << "Username: " << user.getUsername() << endl;
        }
    }

    int calculateScore(double timeTaken) const {
        // The faster the response, the higher the score
        const int baseScore = 100;
        const double maxTime = 10.0; // Maximum time to get full base score (in seconds)
        double normalizedTime = min(timeTaken, maxTime) / maxTime;
        return static_cast<int>(baseScore * (1-normalizedTime));
    }
};

int main() {
    cout<<"             WELCOME TO THE ONLINE QUIZ SYSTEM           \n\n";
    int choice,password=5432,pass;
    Quiz quiz;
 
    do {
        quiz.displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                {
                    string username;
                    cout << "Enter your username: ";
                    cin.ignore();
                    getline(cin,username);

               vector<User>::iterator user = find_if(quiz.users.begin(), quiz.users.end(),
    [username](User& u) { return u.getUsername() == username; });


                    if (user != quiz.users.end()) {
                        quiz.startQuiz(*user);
                    } else {
                        cout << "User not found. Please register first.\n";
                    }
                }
                break;
            case 2:
                cout<<"\nEnter the password!!!As it can be accessible only by the owner..";
                cin>>pass;
                if(pass==password)
                {
                    cout<<"Password is correct!!!\n";
                quiz.addCustomQuestion();}
                else
                cout<<"Password is incorrect!!! please try again\n";
                break;
            case 3:
                quiz.registerUser();
                break;
            case 4:
                cout<<"\nEnter the password!!!As it can be accessible only by the owner..";
                cin>>pass;
                if(pass==password)
                {
                    cout<<"Password is correct!!!\n";
                quiz.shuffleQuestions();
                }
                else
                cout<<"Password is incorrect!!! please try again\n";
                break;
            case 5:
                quiz.displayUsers();
                break;
            case 6:
                    cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

