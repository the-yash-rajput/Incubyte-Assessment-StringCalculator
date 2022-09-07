#include <bits/stdc++.h>
using namespace std;
#define line "_____________________________________________________________________________\n"
class StringCalculator
{
public:
    int add(string numbers)
    {
        // vector to store the numbers in the string
        vector<int> all_number_add;
        // Temporary string to store the numbers
        string tem = "";
        for (int j = 0; j < numbers.size(); ++j)
        {
            char i = numbers[j];
            bool newLine = false;
            // check if the character is a new line
            if (j + 1 < numbers.size())
            {
                string temp = "";
                temp += numbers[j];
                temp += numbers[j + 1];
                string ok = "\\n";
                if (temp == ok)
                {
                    newLine = true;
                    j++;
                }
            }
            // check if the character is a delimiter and push the number in the vector
            if (i == ',' or newLine)
            {
                int val = stoi(tem);
                all_number_add.push_back(val);
                tem = "";
            }
            else
            {
                // store the number in the temporary string
                if (i >= 'a' and i <= 'z')
                {
                    tem += to_string((i - 'a') + 1);
                }
                else
                    tem.push_back(i);
            }
        }
        if (tem.size() and stoi(tem) <= 1000)
            all_number_add.push_back(stoi(tem));
        
        //if no number found
        if (all_number_add.size() == 0){
            cout<<"The system is unable to find any number!!\n";
            return 0;
        }

        // check if the number is negative and print the error message
        vector<int> negative_number;
        for (auto i : all_number_add)
        {
            if (i < 0)
                negative_number.push_back(i);
        }
        if (negative_number.size())
        {
            cout << "Negatives not allowed \n There are " << negative_number.size() << " negative numbers\n";
            for (int k = 0;k<negative_number.size(); k++)
            {
                cout << k + 1 << "] " << negative_number[k] << "\n";
            }
        }
        // add all the positive numbers and return the sum of the numbers and skiping the numbers greater than 1000 
        int answer = 0;
        for (int i = 0; i < all_number_add.size(); i++)
        {
            if (all_number_add[i] <= 1000 and all_number_add[i] >= 0)
                answer = all_number_add[i] + answer;
        }
        return answer;
    }

    // validate the string
    bool validate(string numbers)
    {
        // check if the last character is a delimiter
        if(numbers.back()==',')
            return false;
        for (int i = 0; i < numbers.size(); i++)
        {
            // check if the character is \n
            if (i + 1 < numbers.size())
            {
                string temp = "";
                temp += numbers[i];
                temp += numbers[i + 1];
                string ok = "\\n";
                if (temp == ok)
                {
                    i++;
                    continue;
                }
            }
            // check if invalid delimiter is present
            if (i + 1 < numbers.size() and numbers[i] == '-' and (numbers[i + 1] == '-' or numbers[i + 1] == ','))
                return false;
            // check if valid character is present
            if (numbers[i] >= 'a' and numbers[i] <= 'z')
            {
                continue;
            }
            //check if valid digit is present
            if (numbers[i] >= '0' and numbers[i] <= '9')
            {
                continue;
            }
            //check if valid delimiter is present
            if (numbers[i] == ',' or numbers[i] == '-')
            {
                continue;
            }
            // return false if invalid character is present
            return false;
        }
        // return true if all the characters are valid
        return true;
    }

    string findDelimeter(string s)
    {
        // find the delimeter
        string del = ",";
        if (s[0] == '/' and s[1] == '/')
        {
            string ans = "";
            for (int i = 2; i < s.size(); ++i)
            {
                if (s[i] == '\\' and i + 1 < s.size() and s[i + 1] == 'n')
                    break;
                ans.push_back(s[i]);
            }
            del = ans;
        }
        return del;
    }
    // function to remove the delimeter from the string
    string replaceDelimeter(string input, string del)
    {
        // replace the delimeter with comma
        string newInput = "";
        for (int i = 4 + del.size(); i < input.size(); i++)
        {
            newInput.push_back(input[i]);
        }
        input = newInput;
        while (input.find(del) != string::npos)
        {
            input.replace(input.find(del), del.size(), ",");
        }
        return input;
    }
};

signed main()
{
    // Main function to test the code
    cout << line;
    cout << "Hey!! Welcome To The Application\n";
    cout<<line;
    while (1)
    {
        //print the menu to the user
        cout << "MENU\n1. Add\n2. Exit\n";
        // input the choice
        int choice;
        cin >> choice;
        cout << line;
        if (choice == 2)
            break;
        // input the string
        string input;
        cout << "Please Enter The Input String: ";
        cin >> input;
        // create the object of the class
        StringCalculator obj;
        if (input.size() > 2 and input[0] == '/' and input[1] == '/')
        {
            // find the delimeter
            string del = obj.findDelimeter(input);
            input = obj.replaceDelimeter(input,del);
        }
        if (obj.validate(input) == 0)
        {
            // print the error message if the string is invalid
            cout << "Invalid Input :(\nPlease Try Again!!" << endl;
            cout << line;
            continue;
        }
        // print the sum of the numbers
        int sum=obj.add(input);
        cout << "The Answer is(Sum of all positive numbers): " << sum << endl;
        cout << line;
    }
    // print the exit message
    cout<<"Thank You For Using Our Service :)\n";
    cout << line;
    return 0;
}
