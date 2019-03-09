#include <iostream>
#include <cstring>
using namespace std;

bool compare(const char *sentence_p, const char *equivalente_p)
{
    bool match = false;
    size_t size_sentence = strlen(sentence_p) + 1;
    size_t size_equivalent = strlen(equivalente_p) + 1;
    char *sentence = new char[size_sentence];
    char *equivalent = new char[size_equivalent];
    memcpy(sentence, sentence_p, size_sentence);
    memcpy(equivalent, equivalente_p, size_equivalent);

    while (*sentence != 0)
    {
        if (*sentence == *equivalent)
        {
            sentence++;
            equivalent++;
            match = true;
            cout << ".";
        }
        else
        {
            if (*equivalent == '?')
            {
                sentence++;
                equivalent++;
                match = true;
                cout << ".";
            }
            else
            {
                if (*equivalent == '*')
                {
                    while (*equivalent == '*')
                    {
                        equivalent++;
                    }
                    equivalent--;
                    char *aux = equivalent;
                    aux++;
                    sentence++;
                    match = true;
                    cout << ".";

                    if (*aux == *sentence)
                    {
                        equivalent++;
                    }
                }
                else
                {
                    match = false;
                    cout << "X\n";
                    return match;
                }
            }
        }
    }

    if (*equivalent == 0 && *sentence == 0)
    {
        cout << "\n";
        return match;
    }
    else
    {
        if (*equivalent == '*')
        {
            cout << "\n";
            while (*equivalent != 0)
            {
                if (*equivalent != '*')
                {
                    match = false;
                    return match;
                }
                equivalent++;
            }
        }
        else
        {
            if (*equivalent == '?')
            {
                match = false;
                cout << "X\n";
                return match;
            }
        }
    }
    cout << "\n";
    delete[] sentence;
    delete[] equivalent;
    return match;
}

int main()
{
    bool result = false;
    const char *sentence;
    const char *equivalent;

    sentence = "hello world";
    equivalent = "hello world";
    cout << "===================================\n";
    cout << "sentence:     " << sentence << "\n";
    cout << "equivalent:   " << equivalent << "\n";
    cout << "comparing:    ";
    result = compare(sentence, equivalent);
    if (result)
        cout << "              MATCHED\n";
    else
        cout << "              DON'T MATCH\n";
    cout << "===================================\n\n";

    cout << "===================================\n";
    sentence = "hello world";
    equivalent = "hello dorld";
    cout << "sentence:     " << sentence << "\n";
    cout << "equivalent:   " << equivalent << "\n";
    cout << "comparing:    ";
    result = compare(sentence, equivalent);
    if (result)
        cout << "              MATCHED\n";
    else
        cout << "              DON'T MATCH\n";
    cout << "===================================\n\n";

    cout << "===================================\n";
    sentence = "hello world";
    equivalent = "he?lo?wor?d";
    cout << "sentence:     " << sentence << "\n";
    cout << "equivalent:   " << equivalent << "\n";
    cout << "comparing:    ";
    result = compare(sentence, equivalent);
    if (result)
        cout << "              MATCHED\n";
    else
        cout << "              DON'T MATCH\n";
    cout << "===================================\n\n";

    cout << "===================================\n";
    sentence = "hello world";
    equivalent = "he?lo*";
    cout << "sentence:     " << sentence << "\n";
    cout << "equivalent:   " << equivalent << "\n";
    cout << "comparing:    ";
    result = compare(sentence, equivalent);
    if (result)
        cout << "              MATCHED\n";
    else
        cout << "              DON'T MATCH\n";
    cout << "===================================\n\n";

    cout << "===================================\n";
    sentence = "hello world";
    equivalent = "?????********";
    cout << "sentence:     " << sentence << "\n";
    cout << "equivalent:   " << equivalent << "\n";
    cout << "comparing:    ";
    result = compare(sentence, equivalent);
    if (result)
        cout << "              MATCHED\n";
    else
        cout << "              DON'T MATCH\n";
    cout << "===================================\n\n";

    cout << "===================================\n";
    sentence = "hello world";
    equivalent = "?????????????";
    cout << "sentence:     " << sentence << "\n";
    cout << "equivalent:   " << equivalent << "\n";
    cout << "comparing:    ";
    result = compare(sentence, equivalent);
    if (result)
        cout << "              MATCHED\n";
    else
        cout << "              DON'T MATCH\n";
    cout << "===================================\n\n";

    cout << "===================================\n";
    sentence = "hello world";
    equivalent = "h***rld";
    cout << "sentence:     " << sentence << "\n";
    cout << "equivalent:   " << equivalent << "\n";
    cout << "comparing:    ";
    result = compare(sentence, equivalent);
    if (result)
        cout << "              MATCHED\n";
    else
        cout << "              DON'T MATCH\n";
    cout << "===================================\n\n";

    cout << "===================================\n";
    sentence = "hello world";
    equivalent = "hello worl*?";
    cout << "sentence:     " << sentence << "\n";
    cout << "equivalent:   " << equivalent << "\n";
    cout << "comparing:    ";
    result = compare(sentence, equivalent);
    if (result)
        cout << "              MATCHED\n";
    else
        cout << "              DON'T MATCH\n";
    cout << "===================================\n\n";
}