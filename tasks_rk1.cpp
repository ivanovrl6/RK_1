#include <iostream>
#include <functional>
#include <map>
#include <cstring>
#include <cmath>
#include "tasks_rk1.h"
#include <list>
#include <fstream>
int Node::countNodes=0;
void WorkWithFile::prepareTestFile(const char *fileName) {
    FILE *flog= fopen(fileName,"w");
    fprintf(flog,"%s","skdggsjdgklshjjewsjoiwj3835649209803-ierojgkfghdlh;!@#$%%^*(((^%%(\n");
    fclose(flog);
}

void WorkWithFile::readFromFile(const char *fileName) {
    FILE *flog = fopen(fileName, "r");
    fscanf(flog, "%s", dataOfFile);
    fclose(flog);
}

WorkWithFile::WorkWithFile() {
    prepareTestFile("sourceFile_task1.txt");
    readFromFile("sourceFile_task1.txt");
}

void WorkWithFile::writeStatInfoToFile(const char *outFile) {
    std::map<char,int> result={{'0',0}, {'!',0},
                               {'"',0},{'#',0},
                               {'$',0},{'%',0},
                               {'&',0},{'\'',0},
                               {'(',0},{')',0},
                               {'*',0},{'+',0},
                               {',',0},{'-',0},
                               {'.',0},{'/',0},
                               {'0',0},{'1',0},
                               {'2',0},{'3',0},
                               {'4',0},{'5',0},
                               {'6',0},{'7',0},
                               {'8',0},{'9',0},
                               {':',0},{';',0},
                               {'<',0},{'\n',0},
                               {'>',0},{'?',0},
                               {'@',0},{'A',0},
                               {'B',0},{'C',0},
                               {'D',0},{'E',0},
                               {'F',0},{'G',0},
                               {'H',0},{'I',0},
                               {'J',0},{'K',0},
                               {'L',0},{'M',0},
                               {'N',0},{'O',0},
                               {'P',0},{'Q',0},
                               {'R',0},{'S',0},
                               {'T',0},{'U',0},
                               {'V',0},{'W',0},
                               {'X',0},{'Y',0},
                               {'Z',0},{'[',0},
                               {'\\',0},{']',0},
                               {'^',0},{'_',0},
                               {'`',0},{'a',0},
                               {'b',0},{'c',0},
                               {'d',0},{'e',0},
                               {'f',0},{'g',0},
                               {'h',0},{'i',0},
                               {'j',0},{'k',0},
                               {'l',0},{'m',0},
                               {'n',0},{'o',0},
                               {'p',0},{'q',0},
                               {'r',0},{'s',0},
                               {'t',0},{'u',0},
                               {'v',0},{'w',0},
                               {'x',0},{'y',0},
                               {'z',0},{'{',0},
                               {'|',0},{'}',0},
                               {'~',0},
    };
    for (auto iter = result.begin();iter!=result.end();iter++) {
        for (int i = 0;i< strlen(dataOfFile);i++) {
            if(dataOfFile[i]==iter->first) {
                iter->second++;
            }
        }
    }
    FILE* work=fopen(outFile,"a");
    for (auto iter=result.begin();iter!= result.end();iter++) {
        if(iter->second!=0) {
            fprintf(work, "%c\t%d\n", iter->first, iter->second);
        }
    }
}

WorkWithFile::~WorkWithFile() {
    delete [] dataOfFile;
}

void buildTree(int height){
    int count=height-1;
    for (int j = 1; j <=height ; ++j) {
        for (int i = count--; i> 0; i--) {
            std::cout << " ";
        }
        for (int i = 0; i < 2*j-1; ++i) {
            std::cout<< "*";
        }
        std::cout<<std::endl;
    }

}

 char* convertDecToBin(int number){
    char* string = new char [33];
     for (int i = 0; i < 33 ; ++i) {
            string[i]='0';                                                                                                                                           ;
     }
     string[32]='\0';
     if(number>=0) {
         for (int i = 32; i > 0; i--) {
             string[i] = number % 2 + '0';
             number /= 2;
         }
     }
     else {
         if (number < 0) {
             int chis = abs(number);
             for (int i = 32; i > 0; i--) {
                 string[i] = chis % 2 + '0';
                 chis /= 2;
             }
             for (int i = strlen(string); i >= 0; i--) {
                 if (string[i] == '1') {
                     string[i] = '0';
                 } else {
                     if (string[i] == '0') {
                         string[i] = '1';
                     }
                 }

             }
             for (int i = strlen(string) - 1; i >= 0; i--) {
                 if (string[i] == '1') {
                     string[i] = '0';
                 } else {
                     if (string[i] == '0') {
                         string[i] = '1';
                         break;
                     }
                 }
             }
         }
     }
     return string;
}

 void writeToFile(const char* fileName, const char* strNum){
     FILE* flog= fopen(fileName,"w");
     fprintf(flog,"%s",strNum);
     fclose(flog);
}

char* convertBinToHex(const char* binNum) {
    std::map<std::string, char> mp{{"0000", '0'},
                                   {"0001", '1'},
                                   {"0010", '2'},
                                   {"0011", '3'},
                                   {"0100", '4'},
                                   {"0101", '5'},
                                   {"0110", '6'},
                                   {"0111", '7'},
                                   {"1000", '8'},
                                   {"1001", '9'},
                                   {"1010", 'A'},
                                   {"1011", 'B'},
                                   {"1100", 'C'},
                                   {"1101", 'D'},
                                   {"1110", 'E'},
                                   {"1111", 'F'}};
    std::string res_arr;
    int y = strlen(binNum);
    while (y > 0) {
        std::string four;
        four = "0000";
        for (int w = y - 1, k = 3; w > y - 5 && w >= 0; w--, k--) {
            four[k] = binNum[w];
        }
        y = y - 4;
        res_arr = res_arr + mp.find(four)->second;
    }
    char* result=new char [res_arr.length()];
    for (int i=0, j=res_arr.length()-1; i<res_arr.length() ;j--,i++) {
          result[i]=res_arr[j];
    }
    result[res_arr.length()]='\0';
    return result;
}

void writeToFile(const char* fileName, int writeAppend, const char* hexNum, const char* binNum) {
    FILE* flog= fopen(fileName,"w");
    fprintf(flog,"%s\t%s",binNum,hexNum);
    fclose(flog);
}

void randFill(float* ar, int N){
    for (int i = 0; i < N; ++i) {
        ar[i]=(float)(rand()%20);
    }
}

std::vector<std::pair<int,float>> averStr2DArray(float* ar, int colCount, int rowCount){
    std::vector<std::pair<int,float>> result;
    for (int i = 0; i < rowCount; i++) {
        float aver = 0;
        float sum = 0;
        randFill(ar,colCount);
        for (int k = 0; k < colCount; ++k) {
            sum += ar[k];
        }
        aver = sum / (float)colCount;
        result.emplace_back(i+1,aver);
        ar=ar+colCount-1;
    }
    FILE *flog = fopen("result_task5.txt","w");
    for (auto &iter :result) {
        fprintf(flog, "%d\t%f\n",iter.first,iter.second);
    }
    fclose(flog);
    return result;
}

void LinkedList::push_back(int nameNode) {
    if(Head==nullptr){
        Head = new Node();
        Tail = new Node();
        Head->prev=nullptr;
        Head->next=Tail;
        Tail->prev=Head;
        Tail->next=nullptr;
        Head->nameNode=nameNode;
        Node::countNodes++;
        return;
    }
    Tail->next=new Node();
    Node* temp = Tail->next;
    Tail->nameNode=nameNode;
    temp->prev=Tail;
    temp->next=nullptr;
    Tail=temp;
    Node::countNodes++;
}

void LinkedList::writeToFileFromHead() {
    FILE* flog=fopen("result_task6H.txt","w");
    Node* temp=Head;
    for (int i = 0; temp!= nullptr; ++i) {
        fprintf(flog,"%d\t%d\n",i,temp->nameNode);
        temp=temp->next;
    }
    fclose(flog);
}

void LinkedList::writeToFileFromTail() {
    FILE* flog=fopen("result_task6T.txt","w");
    Node* temp=Tail;
    int i=0;
    while (temp!= nullptr) {
        fprintf(flog,"%d\t%d\n",i,temp->nameNode);
        temp=temp->prev;
        i++;
    }
}

void LinkedList::insert(int nameNode, int position) {
    if(position>0) {
       Node* temp =new Node();
       Node* sec_temp=Head;
        for (int i = 0; i < position-1; ++i) {
            sec_temp=sec_temp->next;
        }
        temp->next=sec_temp->next;
        temp->prev=sec_temp;
        sec_temp->nameNode=nameNode;
        sec_temp->next=temp;
        Node* count=Head;
        while (count->next!= nullptr){
            count=count->next;
        }
        Tail=count;
    }
    else {
        if (position == 0) {
            Node *temp = new Node();
            Node *buff=Head;
            temp->nameNode = nameNode;
            temp->next = Head;
            Head = temp;
            temp->prev=buff;
            Head->prev = nullptr;
            Node::countNodes++;
            Node* count=Head;
            while (count->next!= nullptr){
                count=count->next;
            }
            Tail=count;

        }
    }
}
LinkedList::~LinkedList() {

    for (int i = 0; Head!= nullptr; ++i) {
        Node*temp=Head;
        Head=Head->next;
        delete temp;
    }
}

int StudentInfo::addMark(const std::string &subjName, int mark, bool addSubj) {
    if(addSubj==true) {
        for (auto iter = subjMark.begin(); iter != subjMark.end(); iter++) {
            if (subjName == iter->first) {
                iter->second.first.emplace_back(mark);
                return 0;
            }
        }
    }
    if(addSubj==false) {
        StudentInfo::addSubj(subjName);
        return 2;
    }
}
int StudentInfo::addSubj(const std::string &subjName) {
    std::list<int> marks;
    for (auto iter=subjMark.begin();iter!=subjMark.end();iter++) {
        if(strcmp(subjName.c_str(),iter->first.c_str())==0){
            return 1;
        }
    }
    subjMark.insert(std::pair<std::string,std::pair<std::list<int>,float>>{subjName,{marks,0}});
    return 0;
}
float StudentInfo::getAverMark(const std::string& subjName){
    int sum=0;
    int i=0;
    float result;
    for (auto iter=subjMark.begin();iter!=subjMark.end();iter++) {
        if(strcmp(iter->first.c_str(),subjName.c_str())==0){
            for(auto iterL=iter->second.first.begin();iterL!=iter->second.first.end();iterL++){
                sum+=*(iterL);
                i++;
            }
            result=(float)sum/(float)i;
            iter->second.second=result;
        }
    }
    return result;
}
void StudentInfo::printInfoStudent(bool writeFile) {
    if (writeFile == true) {//файл
        std::ofstream flog("result_task7.txt", std::ios::out);
        flog << std::get<0>(infoStudent) << " " << std::get<1>(infoStudent) << std::get<2>(infoStudent) << std::endl;
        for (auto iter = subjMark.begin(); iter != subjMark.end(); iter++) {
            flog << "\t" << iter->first << " ";
            for (auto iterLL = iter->second.first.begin(); iterLL != iter->second.first.end(); iterLL++) {
                flog << *iterLL << ",";
            }
            flog<<iter->second.second;
            flog << std::endl;
        }
        flog.close();
    }
    if (writeFile == false) {
        std::cout << std::get<0>(infoStudent) << " " << std::get<1>(infoStudent) << std::get<2>(infoStudent)
                  << std::endl;
        for (auto iter = subjMark.begin(); iter != subjMark.end(); iter++) {
            std::cout << "\t" << iter->first << " ";
            for (auto iterLL = iter->second.first.begin(); iterLL != iter->second.first.end(); iterLL++) {
                std::cout << *(iterLL) << ",";
            }
            std::cout<<iter->second.second;
            std::cout << std::endl;
        }
    }
}
void StudentInfo::writeAllInfoToFile(){}

