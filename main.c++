#include <iostream>
using namespace std;

class String{
    /// Initializing private variables so that it can't be accessed directly
private:
    char* data; /// data is to store the string int the char array
    int size; /// to keep track of the size of the string
public:
    /// @brief Initailizing new String
    String(){
        data = new char[0]; /// When the Empty String is intialised new create empty char array
        size = 0; /// Assign the size 0 when new empty string is created
    }
    /// @brief Assigning new String
    String(const char* str){
        size = 0;
        while(str[size] != '\0'){
            size++;
        }
        data = new char[size+1];
        for(int i = 0; i < size; i++){
            data[i] = str[i];
        }
        data[size] = '\0';
    }
    /// @brief Appending or Adding new String to the existing String 
    void append(const char* new_str){
        int new_len = 0;
        while(new_str[new_len] != '\0'){
            new_len++;
        }
        char* new_arr = new char[size + new_len];
        for(int i = 0; i < size; i++){
            new_arr[i] = data[i];
        }
        for(int i = 0; i < new_len; i++){
            new_arr[i+size] = new_str[i];
        }
        delete[] data;
        data = new_arr;
        size += new_len;
    }
    /// @brief Display the string
    void print(){
        for(int i = 0; i < size; i++){
            cout << data[i];
        }
        //if(size != 0)cout << "\n";
    }
    /// @brief To get the length of the string
    int length(){
        return size;
    }

    /// @brief To Convert the String(all the characters of the data) to Upper Case letters
    void toupper(){
        for(int i = 0; i < size; i++){
            /// Convert only the lowercase to uppercase if it was alredy uppercase or other character ignore it
            if(data[i] >= 'a' && data[i] <= 'z') data[i] = data[i]-32;
        }
    }
    /// @brief To Convert the String(all the characters of the data) to Lower Case letters
    void tolower(){
        for(int i = 0; i < size; i++){
            /// Convert only the uppercase to lowercase if it was alredy lowercase or other character ignore it
            if(data[i] >= 'A' && data[i] <= 'Z') data[i] = data[i]+32;
        }
    }

    /// @brief Reverse the String
    void reverse(){
        for(int l = 0, r = size -1; l < r; l++, r--){
            /// Swap the characters using two pointers approach to reverse the String
            char tmp = data[l];
            data[l] = data[r];
            data[r] = tmp;
        }
    }
    /// @brief To get the Substring from index (start) to index (end)
    char* substring(int l, int r){
        char* sub_str = new char[r-l];
        for(int i = l; i < r; i++){
            sub_str[i-l] = data[i];
        }
        sub_str[r-l] ='\0';
        return sub_str;
    }
    /// @brief Delete the complete String
    void clear(){
        delete[] data;
        size = 0;
    }
    /// @brief Remove specific character from the String
    void remove(char c){
        int index = indexOf(c);
        char* new_str = new char[size-1];
        for(int i = 0; i < index; i++){
            new_str[i] = data[i];
        }
        for(int i = index+1; i < size; i++){
            new_str[i] = data[i];
        }
        size--;
        delete[] data;
        data = new_str;
    }

    /// @brief Over Writing the << operator so that we can display the string using << operator
    /// @param out This was the output stream in which we store out string to display in output
    /// @param s this was our String
    /// @return we will return the out after storing the complete string in the out
    friend ostream& operator<<(ostream& out, const String& s){
        for(int i = 0; i < s.size; i++){
            /// Storing the String to out it's like 
            out << s.data[i]; /// out = out + s.data[i];
        }
        return out;
    }
    /// @brief To Assign the String Directly using = operator
    String& operator=(const String& other){
        if(this == &other) return *this;
        delete[] data;
        int len = other.size;
        data = new char[len + 1];
        for(int i = 0; i < len; i++){
            data[i] = other.data[i];
        }
        size = len;
        data[size] = '\0';
        return *this;
    }

    /// @brief To Append the String with new String using += operator
    String& operator+=(const char* new_str){
        append(new_str);
        return *this;
    }
    /// @brief  To get the character at specific index position
    char at(int index){
        return data[index];
    }

    /// @brief To get the first index position of the character
    /// @param c 
    /// @return 
    int indexOf(char c){
        for(int i = 0; i < size; i++){
            if(data[i] == c){
                return i;
            }
        }
        return -1;
    }
    /// @brief Check wether two Strings are equal if it will will return 1 else 0
    /// @param new_str 
    /// @return 
    bool equals(const String& new_str){
        if(size != new_str.size) return false;
        for(int i = 0; i < size; i++){
            if(new_str.data[i] != data[i]) return false;
        }
        return true;
    }
    /// @brief Destructor which release the memeory
    ~String(){
        delete[] data;
    }
};

int main(){
    String str = "Nithwin";
    cout << str;
    return 0;
}

/*
// String str;
    // str.append("Nithwin");
    // str.append(" is a good person");
    // str.print();
    // cout << str.length() << "\n";
    // str.toupper();
    // str.print();
    // str.tolower();
    // str.print();
    // str.reverse();
    // str.print();
    // cout << str.substring(0,5) << "\n";
    // cout << str << "\n";
    //cout << str.at(3) <<"\n";
    //str.clear();
    // cout << str <<"\n";
    // cout << str.indexOf('i') <<"\n";
    // String str4 = "Nithwin";
    // cout << str4 << "\n";
    // str4 += " hello";
    // cout << str4 << "\n";

    //cout << str4 << "\n";
    // String s = "Nithwin";
    // s.remove('n');
    //cout << s;
    // cout << s.equals("Nithwin");
*/

/*
  //str.print();
    // str.append('n');
    // str.append('i');
    //str.print();
    // char* n = new char[3];
    // n[0] = 'N';
    // n[1] = 'i';
    // n[2] = 't';
    // n[3] = '\0';
    // int i = 0;
    // while(n[i] != '\0'){
    //     cout << n[i];
    //     i++;
    // }

*/