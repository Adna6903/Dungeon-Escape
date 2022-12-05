// CSCI 1300 Fall 2022
// Author: Adithya Narayanan & Benjamin E Apelman 
// Recitation: 106 –Chanheum Park (Adithya)
// Recitation: Section 105 – Raegan Rychecky (Benjamin)
// Project 3 

int split(string input_string, char separator, string arr[], int arr_size)
{

    int arrayIndex = 0;

    if (input_string.length() <= 0)
    {
        return 0;
    }

    for (int i = 0; i < input_string.length(); i++)
    {

        if (input_string[i] == separator)
        {

            arrayIndex++;
        }
        else
        {
            if (arrayIndex >= arr_size)
            {

                return -1;
            }
            arr[arrayIndex] += input_string[i];
        }
    }

    return arrayIndex + 1;
}