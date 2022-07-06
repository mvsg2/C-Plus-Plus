#include <iostream>
#include "windows.h"
using namespace std;

/* Our structure should consist of 5 quiz questions. Each of the questions should have multiple (three) options for answers to be chosen from.
So, our structure has a text (question) parameter and an array of options (for the answers) parameter.
*/

struct QuizApp
{
    string question;
    string options[3];                           // array of possible answers
};

int score;                             // a variable to keep track of the current score
int number_of_questions=5;

void display_1(QuizApp q1)
{
    cout << "Question1: " << q1.question << endl;
    cout << " 1. " << q1.options[0] << endl;
    cout << " 2. " << q1.options[1] << endl;
    cout << " 3. " << q1.options[2] << endl;

    int user_answer_1;
    cout << "Choose 1-3:" << " "; 
    cin >> user_answer_1;
    while(user_answer_1 < 1 || user_answer_1 > 3){
        cout << "Invalid! Please enter the option that's within the given range." << endl;
        cout << "Choose 1-3:" << " ";
        cin >> user_answer_1;
    }
    if(user_answer_1 != 3){
        cout << "Incorrect! The correct answer is Burj Khalifa - Dubai. " << endl;
        cout << "Current score: " << score << endl;
    } else{
        cout << "Hey, that's correct! Burj Khalifa (located in Dubai) is the tallest building in the world today with a height of around 830 meters from ground to the tip. " << endl;
        score++;
        cout << "Current score: " << score << endl;
    }

}

void display_2(QuizApp q2)
{
    cout << "Question2: " << q2.question << endl;
    cout << " 1. " << q2.options[0] << endl;
    cout << " 2. " << q2.options[1] << endl;
    cout << " 3. " << q2.options[2] << endl;

    int user_answer_2;
    cout << "Choose 1-3:" << " "; 
    cin >> user_answer_2;
    while(user_answer_2 < 1 || user_answer_2 > 3){
        cout << "Invalid! Please enter the option that's within the given range." << endl;
        cout << "Choose 1-3:" << " ";
        cin >> user_answer_2;
    }
    if(user_answer_2 != 1){
        cout << "Incorrect! The correct answer is Prairie. " << endl;
        cout << "Current Score: " << score << endl;
    } else{
        cout << "Hey, that's correct! North American grasslands are indeed called prairies. " << endl;
        score++;
        cout << "Current score: " << score << endl;
    }
}

void display_3(QuizApp q3)
{
   cout << "Question3: " << q3.question << endl;
    cout << " 1. " << q3.options[0] << endl;
    cout << " 2. " << q3.options[1] << endl;
    cout << " 3. " << q3.options[2] << endl;

    int user_answer_3;
    cout << "Choose 1-3:" << " "; 
    cin >> user_answer_3;
    while(user_answer_3 < 1 || user_answer_3 > 3){
        cout << "Invalid! Please enter the option that's within the given range." << endl;
        cout << "Choose 1-3:" << " ";
        cin >> user_answer_3;
    }
    if(user_answer_3 != 2){
        cout << "Incorrect! The correct answer is Mariana Trench. " << endl;
        cout << "Current score: " << score << endl;
    } else{
        cout << "Hey, that's correct! The Mariana Trench (located in the western Pacific Ocean) is the deepest oceanic trench in the world with a known depth of about 10,984 meters! " << endl;
        score++;
        cout << "Current score: " << score << endl;
    } 
}

void display_4(QuizApp q4)
{
    cout << "Question4: " << q4.question << endl;
    cout << " 1. " << q4.options[0] << endl;
    cout << " 2. " << q4.options[1] << endl;
    cout << " 3. " << q4.options[2] << endl;

    int user_answer_4;
    cout << "Choose 1-3:" << " "; 
    cin >> user_answer_4;
    while(user_answer_4 < 1 || user_answer_4 > 3){
        cout << "Invalid! Please enter the option that's within the given range." << endl;
        cout << "Choose 1-3:" << " ";
        cin >> user_answer_4;
    }
    if(user_answer_4 != 1){
        cout << "Incorrect! The correct answer is Peru. " << endl;
        cout << "Current score: " << score << endl;
    } else{
        cout << "Hey, that's correct! Machu-Pichu is a 15th century Inca (an ancient civilzation) citadel located in the Eastern Cordillera of southern Peru. " << endl;
        score++;
        cout << "Current score: " << score << endl;
    }
}

void display_5(QuizApp q5)
{
    cout << "Question5: " << q5.question << endl;
    cout << " 1. " << q5.options[0] << endl;
    cout << " 2. " << q5.options[1] << endl;
    cout << " 3. " << q5.options[2] << endl;

    int user_answer_5;
    cout << "Choose 1-3:" << " "; 
    cin >> user_answer_5;
    while(user_answer_5 < 1 || user_answer_5 > 3){
        cout << "Invalid! Please enter the option that's within the given range." << endl;
        cout << "Choose 1-3:" << " ";
        cin >> user_answer_5;
    }
    if(user_answer_5 != 2){
        cout << "Incorrect! The correct answer is Mars (Mt. Olympus Mons). " << endl;
        cout << "Current score: " << score << endl;
    } else{
        cout << "Hey, that's correct! Mt. Olympus Mons is the tallest and widest/largest mountain (volcano) in the entire solar system with a height of over 21.9 kms. " << endl;
        score++;
        cout << "Current score: " << score << endl;
    }
}

int main()
{
    QuizApp Q_A_1;
    string question_1 = "What is the tallest building in the world?";
    string options_array_1[3] = {"Twin Towers - Kuala Lumpur", "Empire State Building - New York", "Burj Khalifa - Dubai"};
    Q_A_1.question = question_1;
    for (int i = 0; i < (sizeof(options_array_1)/sizeof(options_array_1[0])); i++)
        Q_A_1.options[i] = options_array_1[i];
    
    display_1(Q_A_1);
    
    Sleep(2000);  // The argument is in milliseconds.

    QuizApp Q_A_2;
    string question_2 = "What are the grasslands of North America called?";
    string options_array_2[3] = {"Prairie", "Savannah", "Downs"};
    Q_A_2.question = question_2;
    for (int i=0; i < (sizeof(options_array_2)/sizeof(options_array_2[0])); i++)
        Q_A_2.options[i] = options_array_2[i];

    display_2(Q_A_2); 

    Sleep(2000);

    QuizApp Q_A_3;
    string question_3 = "What is the deepest oceanic trench in the world?";
    string options_array_3[3] = {"Great Barrier Reef - Australia", "Mariana Trench - Pacific Ocean", "Tonga Trench - Pacific Ocean"};
    Q_A_3.question = question_3;
    for (int i=0; i < (sizeof(options_array_3)/sizeof(options_array_3[0])); i++)
        Q_A_3.options[i] = options_array_3[i];

    display_3(Q_A_3); 

    Sleep(2000);

    QuizApp Q_A_4;
    string question_4 = "Where is Machu-Pichu located?";
    string options_array_4[3] = {"Peru", "Venezuela", "Chile"};
    Q_A_4.question =question_4;
    for (int i=0; i < (sizeof(options_array_4)/sizeof(options_array_4[0])); i++)
        Q_A_4.options[i] = options_array_4[i];

    display_4(Q_A_4);  

    Sleep(2000);

    QuizApp Q_A_5;
    string question_5 = "Where is the tallest mountain in our entire solar system located?";
    string options_array_5[3] = {"Earth (Mt.Everest)", "Mars (Mt. Olympus Mons)", "Venus (Mt. Maxwell Montes)"};
    Q_A_5.question = question_5;
    for (int i=0; i < (sizeof(options_array_5)/sizeof(options_array_5[0])); i++)
        Q_A_5.options[i] = options_array_5[i];

    display_5(Q_A_5);

    Sleep(2000);

    if (score == 5){
        cout << "Hey, you answered all the questions correctly! You got a perfect score..." << endl;
        Sleep(100);
        cout << "GREAT JOB!" << endl;
    }else{
        cout << "You answered " << score << " questions correctly and " << number_of_questions-score << " question(s) incorrectly." << endl;
        cout << "It's okay, learn from the incorrect ones and give it a try again!" << endl;
    }

    Sleep(1000);

    cout << "\nThat's it! Exciting, wasn't it? Thank you for taking this quiz!\n" << endl;
    
    return 0;
}
