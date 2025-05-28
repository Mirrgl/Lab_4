#include <vector>
#include <iostream>
#include <random>
#include <tuple>
#include <string>
#include <ctime>
#include <sstream>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << " ";
    }
    return os;
}

template<typename T>
istringstream& operator>>(istringstream& is, vector<T>& vec) {
    char i;
    while (is >> i) {
        vec.push_back(i);
    }
    return is;
}

template<typename T>
void inputArray(vector<T>& vec) {
    string input;
    getline(cin, input);
    istringstream iss (input);
    iss >> vec;
}

void countEvenNumbers(vector<int> arr1) {
    int count = 0;
    for(int i = 0; i < arr1.size(); i += 2) {
        if (arr1[i] % 2 == 0) {
            cout << arr1[i] << " ";
            count++;
        }
    }
    cout << endl << "Всего " << count << endl;
}

void arr2IntoArr1(vector<int> arr1, vector<int> arr2) {
    int count = 0;
    bool isThereCommonNumbers = 0;
    for (int numberFromArr2 : arr2) {
        for (int numberFromArr1 : arr1) {
            if (numberFromArr2 == numberFromArr1) {
                count++;
                isThereCommonNumbers = 1;
            }
        }
        if (isThereCommonNumbers) {
            cout << "Число " << numberFromArr2 << " повторяется " << count << endl;
            count = 0;
        }
    }
    if (!isThereCommonNumbers) {
        cout << "В первом и втором массивах нет общих чисел" << endl;
    }
}

vector<char> sortArrayOfSymbols(vector<char> array) {
    vector<char> sortedArray;
    vector<char> signArray;
    vector<char> upperArray;
    vector<char> bracketArray;
    vector<char> digitArray;
    vector<char> lowerArray;
    for (auto element : array) {
        if (int(element) == 33 || int(element) == 39 || int(element) == 46 || int(element) == 58 || int(element) == 59 || int(element) == 63) {
            signArray.push_back(element);
        }
        else if (int(element) >= 65 && int(element) <= 90) {
            upperArray.push_back(element);
        }
        else if (int(element) == 34 || int(element) == 39 || int(element) == 60 || int(element) == 62 || int(element) == 40 || int(element) == 41 || int(element) == 91 || int(element) == 93 || int(element) == 123 || int(element) == 125) {
            bracketArray.push_back(element);
        }
        else if (int(element) >= 48 && int(element) <= 57) {
            digitArray.push_back(element);
        }
        else if (int(element) >= 97 && int(element) <= 122) {
            lowerArray.push_back(element);
        }
    }
    sortedArray.insert(sortedArray.end(), signArray.begin(), signArray.end());
    sortedArray.insert(sortedArray.end(), upperArray.begin(), upperArray.end());
    sortedArray.insert(sortedArray.end(), bracketArray.begin(), bracketArray.end());
    sortedArray.insert(sortedArray.end(), digitArray.begin(), digitArray.end());
    sortedArray.insert(sortedArray.end(), lowerArray.begin(), lowerArray.end());
    return sortedArray;
}

vector<int> sortArrayOfNumbers(vector<int> array) {
    for (auto& number : array) {
        string str_number = to_string(number);
        sort(str_number.begin(), str_number.end());
        number = stoi(str_number);
    }
    sort(array.begin(), array.end());
    return array;
}

int main() {
    knuth_b engine;
    engine.seed(time(nullptr));

    uniform_int_distribution<> distribution(15, 30);
    int length = distribution(engine);
    vector<int> arr1;
    for (int i = 0; i < length; i++) {
        uniform_int_distribution<> distribution(10, 30);
        arr1.push_back(distribution(engine));
    }
    cout << arr1 << endl;

    vector<int> arr2;
    for (int i = 0; i < 5; i++) {
        uniform_int_distribution<> distribution(10, 30);
        arr2.push_back(distribution(engine));
    }
    cout << arr2 << endl;

    countEvenNumbers(arr1);
    arr2IntoArr1(arr1, arr2);
    cout << endl;

    vector<char> notsortedArray;
    inputArray(notsortedArray);
    cout << sortArrayOfSymbols(notsortedArray) << endl;

    uniform_int_distribution<> distribution2(5, 10);
    length = distribution2(engine);
    vector<int> arr3;
    for (int i = 0; i < length; i++) {
        uniform_int_distribution<> distribution2(1000, 9000);
        arr3.push_back(distribution2(engine));
    }
    cout << arr3 << endl;

    cout << sortArrayOfNumbers(arr3) << endl;

    return 0;
}