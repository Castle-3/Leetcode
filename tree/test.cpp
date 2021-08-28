#include"iostream"

using namespace std;

typedef void (*func)(void);

void task1(){
    cout << "first" << endl;
}

void task2(){
    cout << "second" << endl;
}

void task3(){
    cout << "third" << endl;
}

int main(){
    func fff[] = {task1, task2, task3};

    func a = fff[0];
    a();
}