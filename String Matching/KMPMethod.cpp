#include<iostream>
#include<string>
#include<vector>
using namespace std;
void fill_ar(vector<int> &ar, size_t index, size_t &value)
{
    ar[index] = value+1;
    ++value;
}
void build_lpa(string Test, vector<int>&ar)
{
    size_t len = Test.length(), j = 0;
    for(size_t i = 1; i < len; ++i)
    {
        if(Test[i] == Test[j])
            fill_ar(ar,i,j);
        else
        {
            while(j != 0)
            {
                if(Test[i] == Test[j])
                {
                    fill_ar(ar,i,j);
                    break;
                }
                j = ar[j-1];
            }
            if(j == 0)
            {
                if(Test[j] == Test[i])
                    fill_ar(ar,i,j);
                else ar[i] = 0;
            }
        }
    }
}
int main()
{
    string pattern, text;
    cout<<"Enter text to be searched within: ";
    cin>>text;
    cout<<"Enter pattern to be searched: ";
    cin>>pattern;
    size_t len_text = text.length(), len_pattern = pattern.length(), i = 0, j = 0;
    vector<int>vec(len_pattern,0);
    build_lpa(pattern,vec);
    for(; i < len_text; )
    {
        if(text[i] == pattern[j])
        {
            ++i; ++j;
            if(j == len_pattern)
            {
                cout<<"Match found........!\nMatch Found at the index : "<<i+1-len_pattern;
                return 0;
            }
        }
        else
        {
            if(j == 0)
                ++i;
            else
            j = vec[j - 1];
        }
    }
    cout<<"Entire text searched but no match found......!";
}
