#include <iostream>

using namespace std;

void matrix_cout(char matr[][10])
{
    for(int i = 0; i < 12; i++)
    {
        std::cout << std::endl;
        for(int n = 0; n < 12; n++)
        {
            if(i == 0 || i == 11) {
                cout << "=";
                continue;
            }
            if (n == 0 || n == 11)
            {
                cout << "|";
                continue;
            }
            std::cout << matr[i - 1][n - 1] ;
        }
    }
    std::cout << std::endl;
}

void fill_matrix(char matr[][10])
{
    for(int i = 0; i < 10; i++)
    {
        for(int n = 0; n < 10; n++)
        {
            matr[i][n] = ' ';
        }
    }
}

bool check_cell(char matr[][10], int x, int y)
{
    if (x > 9 || x < 0 || y > 9 || y < 0
            || matr[x][y] == 'O') return false;
    return true;
}

void place_ship(char field[][10], int decks)
{
    int x;
    int y;
    int a = 0;
    int b = 0;

    cout << "Place " << decks << "-deck ship: " << endl;
    cin >> x;
    cin >> y;
    if (decks != 1)
    {
        cin >> a;
        cin >> b;
    }

    while(!(x == a || y == b) && decks != 1
            || !(decks != 1 && y == b && (abs(x - a) == decks - 1)
            || !(decks != 1 && x == a && abs(y - b) != decks - 1)))
    {
        sauna:
        cout << "Incorrect input, try again. Place " << decks << "-deck ship:\n ";
        cin >> x;
        cin >> y;
        if (decks != 1) {
            cin >> a;
            cin >> b;

        }
    }

    int c = a == 0 ? x : (x <= a ? x : a);
    int d = b == 0 ? y : (y <= b ? y : b);

    for (int i = 0; i < decks; i++)
    {
        if (x == a)
        {
            if (!check_cell(field, c - 1, d + i - 1)) goto sauna;
        }
        else if (y == b)
        {
            if (!check_cell(field, c + i - 1, d - 1)) goto sauna;
        }
        else
        {
            if (!check_cell(field, x - 1, y - 1)) goto sauna;
        }
    }
    for (int i = 0; i < decks; i++)
    {
        if (x == a)
        {
            field[c - 1][d + i - 1] = 'O';
        }
        else if (y == b)
        {
            field[c + i - 1][d - 1] = 'O';
        }
        else
        {
            field[x - 1][y - 1] = 'O';
        }
    }
}

void fill_fields(char field[][10])
{
    for(int i = 1; i < 5; i++) {
        for(int n = 0; n < 5-i; n++) {
            place_ship(field, i);
            matrix_cout(field);
        }
    }
}

void fire(char field [][10], int* loose)
{
    int x;
    int y;
    bool b = true;
    while(b)
    {
        cout << endl << "Fire! \n";
        cin >> x;
        cin >> y;

        while (x > 10 || x < 1 || y > 10 || y < 1
        || field[x - 1][y - 1] == 'X'
        || field[x - 1][y - 1] == '*')
        {
            cout << "Incorrect input, try again:\n ";
            cin >> x;
            cin >> y;
        }

        if (field[x - 1][y - 1] == 'O')
        {
            field[x - 1][y - 1] = 'X';
            cout << endl << "Hit! One more move!\n";
            (*loose)++;
        }
        else
        {
            field[x - 1][y - 1] = '*';
            cout << endl << "Away! Turn!\n";
            b = false;
        }
    }
}

int main() {

    char field[10][10];
    char field2[10][10];
    int loose = 0;
    int loose2 = 0;

    fill_matrix(field);
    fill_matrix(field2);

    matrix_cout(field);
    matrix_cout(field2);

    fill_fields(field);
    fill_fields(field2);

    matrix_cout(field);
    matrix_cout(field2);

    while(loose < 20 && loose2 < 20)
    {
        fire(field2, &loose2);
        matrix_cout(field2);

        fire(field, &loose);
        matrix_cout(field);
    }

    cout << endl << (loose == 20 ? 2 : 1) << " wins!!!";
    return 0;
}

