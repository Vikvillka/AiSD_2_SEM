#include <iostream>
#include <stack>

using namespace std;

bool skodichki(string s)
{
    stack <char> stk;
    for (char symbol : s) {
        switch (symbol) {

        case '(':
        case '[':
        case '{':
        case '<':
            stk.push(symbol);
            break;
        case ')':
        case ']':
        case '}':
        case '>':
            if (stk.empty() || (symbol == ')' && stk.top() != '(')
                || (symbol == ']' && stk.top() != '[')
                || (symbol == '}' && stk.top() != '{')
                || (symbol == '>' && stk.top() != '<')) {
                return false;
            }
            stk.pop();
            break;
        default:
            break;
        }
    }
    return stk.empty();
}

int main()
{
    setlocale(LC_ALL, "RUS");
    char s[200];
    cout << "Введите строку: ";
    cin.getline(s,200); // измененный ввод строки с учетом пробелов
    if (skodichki(s)) {
        cout << "Скобки расставлены верно" << endl;
    }
    else {
        cout << "Скобки расставлены неверно" << endl;
    }
}
