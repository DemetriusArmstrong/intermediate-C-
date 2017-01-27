//Demetrius Armstrong
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <string>


using namespace std;

const int SIZE =23907;




bool sortCStrAlphabetically(char* word1, char* word2)
{
    if(strcmp(word1, word2) <= 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool binarySearch(int lower, int higher, char *array[], char *word )
{



    if(lower > higher)
        return false;
    if(lower==higher )
    {
        if(strcmp(array[lower],word)==0)
            return true;
        else
            return false;
    }

    int mid=(lower+higher)/2;
    if(strcmp(array[mid],word)==0)
    {
        return true;
    }
    if(strcmp(array[mid], word)>0)
        return binarySearch(lower, mid-1, array, word);
    else
        return binarySearch(mid+1, higher, array, word);
}


int main()
{
    //char *ptr = NULL;
    char* array[SIZE];
    int len = 0;
    string s;
    ifstream inputfile, testfile;
    inputfile.open("dictionary.txt");

    //char* array = new char[SIZE];

    if (inputfile)
    {
        for (int i = 0; i < SIZE; i++)
        {

            inputfile >> s ;
            for (int r = 0; r < s.length(); r++)
            {
                s[r] = tolower(s[r]);
            }
            len = strlen(s.c_str()) + 1;
            char* cstringptr = new char[len];
            strcpy (cstringptr, s.c_str());
            array[i] = cstringptr;
            //strcpy(array[i], s.c_str());        // copy to new space

            //cout << array[i] << endl;
        }


        sort (array, array + SIZE, sortCStrAlphabetically );
        for(int i =0; i< SIZE; i++)
        {

            //   cout << i<<" "<< array[i] << endl;

        }


    }
    else
    {

        cout << "file could not be opened" << endl;
    }

    string line;
    testfile.open("gettysburg.txt");
    int count=0;


    if(!testfile)
    {
        cerr << "file can't open" << endl;
        exit(1);
    }
    while(!testfile.eof())
    {

        while(getline(testfile, line))
        {
            count++;
            for (int t = 0; t < line.length(); t++)
            {
                line[t] = tolower(line[t]);
            }

            char* token = strtok(&line[0], ",-. ");

            while(token != NULL)
            {
                //   cout << token << endl;

                bool found = binarySearch(0, SIZE-1, array, token);
                if(!found)
                {
                    cout << "Misspelled word, " <<token<< " on line "<<count << endl;
                }
                token = strtok ( NULL, ",-. ");
            }
        }
    }



    for (int i = 0; i < SIZE; i++)
    {
        //	cout << array[i] << endl;
        delete [] array[i];
    }
    return 0;
}
