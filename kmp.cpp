#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int pif[100];
void generate_pi_function(string pattern, int ptr_len)
{
    int i = 1, j = 2;
    if (ptr_len == 1)
    {
        pif[1] = 0;
    }
    else
    {
        pif[1] = 0;
        while (j <= ptr_len)
        {
            if (pattern[i - 1] == pattern[j - 1])
            {
                pif[j] = i;
                if (pattern[i] == pattern[j])
                {
                    i++;
                }
                j++;
            }
            else
            {
                i = 1;
                pif[j++] = 0;
            }
        }
    }
}

void kmp(string str, string ptr, int ptr_len, int str_len)
{
    int i = 1, j = 1;
    while (i <= str_len - ptr_len + j)
    {
        if (str[i - 1] == ptr[j - 1])
        {
            if (j == ptr_len)
            {
                cout << "Pattern found at index " << i - ptr_len << endl;
                j = pif[j];
            }
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            j = pif[j];
            if (j == 0)
            {
                i++;
                j++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    string ptr, str;
    str = "ABACABCABC";
    ptr = "ABC";
    int ptr_len = ptr.length();
    int str_len = str.length();
    // int pi_fun[ptr_len+1];
    generate_pi_function(ptr, ptr_len);
    kmp(str, ptr, ptr_len, str_len);
    return 0;
}
