//
// Created by User on 25.03.2023.
//

#ifndef OP___TASKS_RK1_H
#define OP___TASKS_RK1_H
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>

void buildTree(int);
char* convertDecToBin(int);
char* convertBinToHex(const char*);
void writeToFile(const char*, const char*);
void writeToFile(const char*,int, const char*, const char*);
std::vector<std::pair<int, float >> averStr2DArray ( float* , int, int);
class WorkWithFile {
private :
        char* dataOfFile=new char [300];
        void readFromFile(const char* fileName);
        void prepareTestFile(const char* fileName);
public :
    WorkWithFile();
    ~WorkWithFile();
};
struct Node  {
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;
};
class LinkedList {
private :
    Node* Head= nullptr;
    Node* Tail= nullptr;
public :
    void push_back(int nameNode);
    void writeToFileFromTail();
    void writeToFileFromHead();
    void insert(int nameNode, int position);
    ~LinkedList();
};
class StudentInfo {
private :
    std::tuple<std::string , std::string , char* > infoStudent={"Ivanov","Egor","22L155\0"};

    std::map<std::string, std::pair<std::list<int> , float>> subjMark;
public :
    int addMark(const std::string& subjName, int mark, bool addSubj = false);
    int addSubj(const std::string& subjName);
    float getAverMark(const std::string& subjName);
    void printInfoStudent(bool writeFile = false);
    void writeAllInfoToFile();
};

#endif //OP___TASKS_RK1_H
