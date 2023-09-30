#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int len1, len2;
    cout << "enter the size of the string1: ";
    cin >> len1;
    char str1[len1];
    cout << "enter string1: ";
    cin >> str1;
    cout << "enter the size of the string2: ";
    cin >> len2;
    char str2[len2];
    cout << "enter string2: ";
    cin >> str2;

    int lcs[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
    {
        lcs[i][0] = 0;
    }
    for (int j = 0; j <= len2; j++)
    {
        lcs[0][j] = 0;
    }

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            }
            else
            {
                if (lcs[i - 1][j] > lcs[i][j - 1])
                {
                    lcs[i][j] = lcs[i - 1][j];
                }
                else
                {
                    lcs[i][j] = lcs[i][j - 1];
                }
            }
        }
    }
    cout<<endl<<endl;
    cout << "   ^  ";
    for (int i = 0; i < len2; i++)
    {
        cout << str2[i] << "  ";
    }
    cout << endl;
    for (int i = 0; i < len1 + 1; i++)
    {
        if (i == 0)
            cout << "^  ";
        else
            cout << str1[i - 1] << "  ";
        for (int j = 0; j < len2 + 1; j++)
        {
            cout << lcs[i][j] << "  ";
        }
        cout << endl;
    }

    char lcsstr[3];
    int i, j, k=0;
    if (len1 < len2)
    {
        i = len1, j = len2;
        while (lcs[i][j])
        {
            if (lcs[i][j - 1] < lcs[i][j])
            {
                lcsstr[k] = str1[i - 1];
                k++;
                i--;
                j--;
            }
            else
            {
                j--;
            }
        }
    }
    else
    {
        i = len1, j = len2;
        while (lcs[i][j])
        {
            if (lcs[i - 1][j] < lcs[i][j])
            {
                lcsstr[k] = str1[i - 1];
                k++;
                i--;
                j--;
            }
            else
            {
                i--;
            }
        }
    }

    cout << endl<< endl;
    char revs[k];
    int counter = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        revs[counter++] = lcsstr[i];
    }
    cout<<"connmon sequence: ";
    for(int c =0; c<counter; c++)
        cout<<revs[c];
    
    cout<<endl<<"length of LCS: "<<k<<endl;
    return 0;
}
