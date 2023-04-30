
#include "tasks_rk1.h"

void task_1(){
    WorkWithFile first;
    first.writeStatInfoToFile("sourcefile_task1.txt");
}
void task_2(){
    convertDecToBin(-89);
    writeToFile("result_task2.txt",convertDecToBin(-89));
}
void task_3(){
    convertBinToHex("1001000110101111");
    writeToFile("result_task3.txt",1,"1001000110101111" ,convertBinToHex("1001000110101111"));
}
void task_4(){
    buildTree(6);
}
void task_5(){
    float arr [10][20];
    std::vector<std::pair<int,float>> test = averStr2DArray(arr[0],10,20);
}
void task_6(){
    LinkedList test1;
    for (int i = 0; i < 8; ++i) {
        test1.push_back(i);
    }
}
void task_7(){
    LinkedList test2;
    test2.insert(0,0);
    test2.insert(1,1);
    test2.writeToFileFromTail();
    test2.writeToFileFromHead();
}
void task_8(){
    StudentInfo testS;
    testS.addSubj("Eng");
    testS.addSubj("Math");
    testS.addSubj("EngGraphics");
    testS.addMark("Eng",5,true);
    testS.addMark("Math",4,true);
    testS.addMark("EngGraphics",5,true);
    testS.getAverMark("Eng");
    testS.addMark("Eng",3,true);
    testS.getAverMark("Eng");
    testS.getAverMark("Math");
    testS.getAverMark("EngGraphics");
    testS.printInfoStudent(true);
}
int main(){
        task_1();
        task_2();
        task_3();
        task_4();
        task_5();
        task_6();
        task_7();
        task_8();
        return 0;
}
//
// Created by User on 25.03.2023.
//
