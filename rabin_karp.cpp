#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

map<char, int> rk_map;

void create_hashmap(string str)
{
    char min = 'a', max = 'a';
    for (char ch : str)
    {
        if (ch > max)
        {
            max = ch;
        }
        if (ch < min)
        {
            min = ch;
        }
    }
    int i = 1;
    for (char ch = min; ch <= max; ch++)
    {
        rk_map[ch] = i++;
    }
}

double hash_value(string str, int start, int end)
{
    int i = 0;
    double val = 0;
    for (int k = start; k <= end; k++)
    {
        val += rk_map[str[k]] * pow(10, i++);
    }
    return val;
}

int main(int argc, char const *argv[])
{
    string str ;
    string pattern;
    bool found = false;
    cin >> str >> pattern;
    int str_len = str.length();
    int pat_len = pattern.length();
    create_hashmap(str);
    double pat_hash_value = hash_value(pattern, 0, pat_len - 1);
    double temp_hash_value = 0;
    for (int z = 0; z <= str_len - pat_len; z++)
    {
        temp_hash_value = hash_value(str, z, z + pat_len-1);
        if (temp_hash_value == pat_hash_value)
        {
            for (int u = z; u < z + pat_len; u++)
            {
                if (str[u] == pattern[u%pat_len])
                {
                    found = true;
                    continue;
                }
                else
                {
                    found = false;
                    break;
                }
            }
        }
        if (found)
        {
            cout << z;
            break;
        }
    }
    if(!found){
        cout << "Not found";
    }
    return 0;
}
