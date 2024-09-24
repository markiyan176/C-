#include <iostream> 
#include <string> 
 
using namespace std; 
 
int main() { 
    string text; 
    cout << "Введіть текст: "; 
    getline(cin, text); 
 
    string oldWord = "моє"; 
    string newWord = "наше"; 
 
    size_t pos = 0; 
    while ((pos = text.find(oldWord, pos)) != string::npos) { 
         
        bool isWordBoundary = (pos == 0 || text[pos - 1] == ' ') && 
                              (pos + oldWord.length() == text.length() || text[pos + oldWord.length()] == ' '); 
 
        if (isWordBoundary) { 
            text.replace(pos, oldWord.length(), newWord); 
            pos += newWord.length();  
        } else { 
            pos += oldWord.length();  
        } 
    } 
 
    cout << "Заміна 'моє' на 'наше':" << endl; 
    cout << text << endl; 
 
    return 0; 
}
