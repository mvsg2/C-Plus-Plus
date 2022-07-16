#include <iostream>
#include <queue>
#include "windows.h"
using namespace std;

struct dailyTasks{
    int duration;
    string task;
    dailyTasks(string task_name, float task_duration){
        task = task_name;
        duration = task_duration;
    }
   /* void showTasks(){
        cout << "Task is " << task << endl;
        cout << "Duration is " << duration << " mins." << endl;   
    } */
};

ostream& operator<<(ostream& COUT, dailyTasks& dT){
    COUT << "Task: " << dT.task << endl;
    COUT << "Duration: " << dT.duration << " mins." << endl;
    return COUT;
}

void printTasks(queue <dailyTasks> myTasks){
    cout << "Good morning!\n"; Sleep(1300);
    cout << "Hope you've had a good night's sleep." << endl;
    Sleep(1500);
    cout << "Here are your tasks for today:-  \n"; Sleep(1500);
    cout << endl;
    while(!myTasks.empty()){
        cout << myTasks.front() << endl; Sleep(1900);
        myTasks.pop();
    }
    /*Sleep(1500);
    cout << "That's all! No pressure..." << endl;
    cout << "Have a good day!"; */
    cout << endl;
}

int main()
{
    dailyTasks task1 = dailyTasks("Jogging at 6:00 AM", 60);
    dailyTasks task2 = dailyTasks("Breakfast at 7:05 AM", 20);
    dailyTasks task3 = dailyTasks("Meeting with delegates at 10:00 AM", 45);
    dailyTasks task4 = dailyTasks("Lunch with sister at Poirot's at 12:15 PM", 100);
    dailyTasks task5 = dailyTasks("Playtime! (at 3:00 PM)", 42.5);
    dailyTasks task6 = dailyTasks("Work (from home today) at 4:10 PM", 70);
    dailyTasks task7 = dailyTasks("Hanging out with buddies for snacks at 5:30 PM", 40);
    dailyTasks task8 = dailyTasks("Playing some games at 6:15 PM", 60);
    dailyTasks task9 = dailyTasks("Dinner with mom and dad at 7:30 PM", 100);

    queue<dailyTasks> tasks;
    tasks.push(task1);
    tasks.push(task2);
    tasks.push(task3);
    tasks.push(task4);
    tasks.push(task5);
    tasks.push(task6);
    tasks.push(task7);
    tasks.push(task8);
    tasks.push(task9);

    //cout << task1;

    printTasks(tasks);

    cout << "Doing the tasks as the day progresses..." << endl; Sleep(4800);

    cout << endl;
    cout << "\nHey, you've finished all your tasks!" << endl;
    cout << endl;
    
    return 0;
}
