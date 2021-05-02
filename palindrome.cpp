///////////////////////////////////////////////////////////////////////////////
//
// Author:           Aayush Bhurtel
// Email:            aayushbhurtel@gmail.com
//
// Description:
//       Checks if the user entered string is palindrome or not!
//
// Usage:
//       Simply enter any string using the console
//
// Files:
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string.h>
using namespace std;

// prototypes
bool isPalindrome(string s);
string to_lower(string s);
string removeSpace(string s);

int main()
{
    string s;
    cout << "Enter a string to check for palindrome: ";
    getline(cin, s);
    while (s != "0")
    {
        string str = to_lower(s);
        str = removeSpace(str);
        bool checkPal = isPalindrome(str);
        if (checkPal == true)
        {
            cout << "Entered string '" << s << "' is a palindrome" << endl;
        }
        else
        {
            cout << "Entered string '" << s << "' is not a palindrome" << endl;
        }
        cout << "\nEnter 0 to quit or \nEnter a string to check for Palindrome: ";
        getline(cin, s);
    }
}

/**
 * Public : isPalindrome
 * 
 * Description:
 *      checks front and last letters from the string recursively to determine palindrome or not
 * 
 * Params:
 *      - [string] s - string entered by user
 * 
 * Returns:
 *      - [boolean] bool - returns true or false depending on palindrom result
*/

bool isPalindrome(string s)
{
    //base case
    if (s.length() <= 2)
    {
        return true;
    }
    // check the front and back characters recursively
    else if (s.front() == s.back())
    {
        string str = s.substr(1, s.length() - 2);
        return isPalindrome(str);
    }
    return false;
}

/**
 * Public : to_lower
 * 
 * Description:
 *      converts the user entered input into lowercase letters
 * 
 * Params:
 *      - [string] s - string entered by user
 * 
 * Returns:
 *      - [string] s - returns the same string with all lowercase letters
*/
string to_lower(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]); // change each char into lowercase
    }
    return s;
}

/**
 * Public : removeSpace
 * 
 * Description:
 *      remove addition space from user entered string
 * 
 * Params:
 *      - [string] s - string entered by user
 * 
 * Returns:
 *      - [string] s - returns the same string without any space
*/
string removeSpace(string s)
{
    string str;
    char charArray[s.length() + 1]; // create char array

    for (int i = 0; i < s.length(); i++)
    { //copy string into char
        charArray[i] = s[i];
    }
    for (int i = 0, j = 0; i < s.length(); i++)
    { // remove space char
        if (charArray[i] != ' ')
        {
            charArray[j++] = charArray[i];
            str = str + charArray[i]; // convert charArray to string
        }
    }
    return str;
}