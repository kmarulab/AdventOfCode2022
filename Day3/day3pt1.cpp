#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//points format
//a to z have 1 to 26
//A to Z have 27 to 52
//a subtract 96 from all lower case values
//subtract 38 from all upper case values
int freq(string test){
    int len=test.length();
    int half=len/2;
    char halfOne[half+1], halfTwo[half+1];
    for(int i=0; i<(half+1);i++){
        if(i==half){
            halfOne[i]='\0';
        }
        else{
        halfOne[i]=test[i];
        }
        //cout << "v1 right now is: " << halfOne[i] << endl;
    }
    for(int m=half, i=0; m<len+1; m++,i++){
         if(i==len){
            halfTwo[i]='\0';
        } else{       
            halfTwo[i]=test[m];
        }
    }
    //int currSum;
    int val=0;
    for(int k = 0; k < half; k++) {
        
        for(int j = 0; j < half+1; j++) {
            if(halfOne[k] == halfTwo[j]) {
                if(halfOne[k]<91){
                val=halfOne[k]-38;
                }
                else{
                    val=halfOne[k]-96;
                }
            }
            else{
                //cout<<"Not Found"<<endl;              
            }
        }
    }
    return val;
}
int main(){
   string rucksack;
    string line;
    ifstream input("in.txt");
    int currSum=0;

 while (getline(input, line)){
    currSum+=freq(line);
 }
 cout<<currSum<<endl;
}
