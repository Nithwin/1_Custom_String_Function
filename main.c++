#include <iostream>
using namespace std;

class String{
private:
    char* data;
    int size;
public:
    String(){
        data = new char[1];
        size = 0;
    }

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

    void print(){
        for(int i = 0; i < size; i++){
            cout << data[i];
        }
        //if(size != 0)cout << "\n";
    }

    int length(){
        return size;
    }

    void toupper(){
        for(int i = 0; i < size; i++){
            if(data[i] >= 'a' && data[i] <= 'z') data[i] = data[i]-32;
        }
    }

    void tolower(){
        for(int i = 0; i < size; i++){
            if(data[i] >= 'A' && data[i] <= 'Z') data[i] = data[i]+32;
        }
    }

    void reverse(){
        for(int l = 0, r = size -1; l < r; l++, r--){
            char tmp = data[l];
            data[l] = data[r];
            data[r] = tmp;
        }
    }

    char* substring(int l, int r){
        char* sub_str = new char[r-l];
        for(int i = l; i < r; i++){
            sub_str[i-l] = data[i];
        }
        sub_str[r-l] ='\0';
        return sub_str;
    }

    void clear(){
        delete[] data;
        size = 0;
    }

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

    friend ostream& operator<<(ostream& out, const String& s){
        for(int i = 0; i < s.size; i++){
            out << s.data[i];
        }
        return out;
    }

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

    String& operator+=(const char* new_str){
        append(new_str);
        return *this;
    }

    char at(int index){
        return data[index];
    }

    int indexOf(char c){
        for(int i = 0; i < size; i++){
            if(data[i] == c){
                return i;
            }
        }
        return -1;
    }

    bool equals(const String& new_str){
        if(size != new_str.size) return false;
        for(int i = 0; i < size; i++){
            if(new_str.data[i] != data[i]) return false;
        }
        return true;
    }
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