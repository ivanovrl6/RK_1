
#include "tasks_rk1.h"
int Node::countNodes=0;
int main(){
        buildTree(6);
        convertDecToBin(24);
        writeToFile("result_task2.txt",convertDecToBin(24));
        convertBinToHex("1001000110101111");
        writeToFile("result_task3.txt",1,"1001000110101111" ,convertBinToHex("1001000110101111"));
        float arr [10][20];
        std::vector<std::pair<int,float>> test = averStr2DArray(arr[0],10,20);
        WorkWithFile first;
        LinkedList test1;
        for (int i = 0; i < 8; ++i) {
            test1.push_back(i);
        }
        test1.insert(25,3);
        test1.insert(35,0);
        test1.writeToFileFromTail();
        test1.writeToFileFromHead();
        StudentInfo testS;
        testS.addSubj("Eng");
        testS.addSubj("Math");
        testS.addSubj("OPC++");
        testS.addMark("Eng",5,true);
        testS.addMark("Math",4,true);
        testS.addMark("OPC++",5,true);
        testS.getAverMark("Eng");
        testS.addMark("Eng",3,true);
        testS.getAverMark("Eng");
        testS.getAverMark("Math");
        testS.getAverMark("OPC++");
        testS.printInfoStudent(true);
        return 0;
}
//
// Created by User on 25.03.2023.
//
