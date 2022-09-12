#include <iostream>
#include <stdlib.h>
#include <string>

std::string lower(std::string); //input: upper case and/or lower case alphabet (string), output: lowercase string
std::string ProcessData(std::string); //input: data (string), output: processed data for encryption
std::string RemoveDupliKeys(std::string); //input: key, output: processed key (duplicates removed)
std::string EncryptData(std::string, std::string); //input: processed data and key, output: encrypted data

int main()
{
    std::cout << "Welcome to PlayFair Cipher" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::string data {}, key {}, processedData {}, encryptedData {}, processedKey {};

    std::cout << "\nEnter the data (alphabets only): ";
    std::getline(std::cin, data);

    std::cout << "\nEnter the key (alphabets only): "; 
    std::getline(std::cin, key);

    data = lower(data);
    key = lower(key);

    processedData = ProcessData(data);
    processedKey = RemoveDupliKeys(key);
    encryptedData = EncryptData(processedData, processedKey);  

    std::cout << "Processed Data: " << processedData << std::endl;
    std::cout << "Encrypted Data: " << encryptedData << std::endl; 

    return 0;
}

std::string ProcessData(std::string data)
{
    int dataStringLength = data.length();
    std::string processedData {};
    char charSeparater {}, spaceCharacter {};

    std::cout << "\nEnter the character to separate duplicate character: ";
    std::cin >> charSeparater;

    std::cout << "\nEnter the character to over-write space: ";
    std::cin >> spaceCharacter;

    for(int i = 0; i < dataStringLength; i++)
    {
        if(data[i] == data[i+1])
        {
            if(i % 2 == 0)
            {
                if(data[i] == ' ')
                    processedData += spaceCharacter;
                else
                    processedData += data[i];

                processedData += charSeparater;
            }
        }
        else
        {   
            if(data[i] == ' ')
                processedData += spaceCharacter;
            else
                processedData += data[i];
        }
    }

    if(processedData.length() % 2 != 0)
        processedData += charSeparater;
        
    return processedData;
}

std::string EncryptData(std::string data, std::string key)
{
    int keyLength = key.length(), dataLength = data.length(), i {}, j {}, k {}, l {}, m {};
    std::string encryptedData {};
    char playfair[5][5] {}, alphabet {'a'};
    
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(k < keyLength)  
                playfair[i][j] = key[k++];
            else
            {
                int a {}, b {}, c {};
                char present {0};
                check:
                for(a = 0; a <= i; a++)
                {
                    for(b = 0; b < 5; b++)
                    {
                        if(alphabet == 'j')
                            alphabet++;
                            
                        if(alphabet == playfair[a][b])
                        {
                            present = alphabet;      
                            break;
                        }                  
                    }
                }

                if(present == 'j')
                    alphabet++;

                if(!present)
                {
                    playfair[i][j] = alphabet;
                    alphabet++;
                }
                else
                {
                    alphabet++;
                    present = 0;
                    goto check;
                    playfair[i][j] = alphabet++;
                }
            }
        }
    }

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            std::cout << playfair[i][j] << "  ";
        }

        std::cout << std::endl;
    }

    for(i = 0; i < dataLength; i += 2)
    {
        int a {}, b {}, c {}, d {};
        l = i, m = i + 1;

        for(j = 0; j < 5; j++)
        {
            for(k = 0; k < 5; k++)
            {
                if(playfair[j][k] == data[l])
                    a = j, b = k;

                if(playfair[j][k] == data[m])
                    c = j, d = k;    
            }
        }

        if(a == c) //what happens when rows are equal
        {
            if(b == 4)
                encryptedData += playfair[a][0];
            else
                encryptedData += playfair[a][b+1];

            if(d == 4)
                encryptedData += playfair[c][0];
            else
                encryptedData += playfair[c][d+1];
        }
        else if(b == d) //what happens when coloumns are equal
        {
            if(a == 4)
                encryptedData += playfair[0][b];
            else
                encryptedData += playfair[a+1][b];

            if(c == 4)
                encryptedData += playfair[0][d];
            else
                encryptedData += playfair[c+1][d];
        }
        else //what happens when matrix formed
        {
            encryptedData += playfair[a][d];
            encryptedData += playfair[c][b];
        }
    }

    return encryptedData;
}

std::string RemoveDupliKeys(std::string key)
{
    int keyLength = key.length();
    bool charPresent {};

    for(int i = 0; i < keyLength; i++)
    {
        if(key[i] == 'j')
            key[i] = 'i';
    }

    std::string unifiedKey {key[0]};

    for(int i = 1; i < keyLength; i++)
    {
        for(int j = 0; j < unifiedKey.length(); j++)
        {
            if(unifiedKey[j] == key[i])
            {
                charPresent = true;
                j = unifiedKey.length();
            }           
        }

        if(charPresent)
            charPresent = false;
        else
            unifiedKey += key[i];
    }
    std::cout << unifiedKey << std::endl;

    return unifiedKey;
}

std::string lower(std::string data)
{
    int dataLength = data.length();
    std::string lowerData {};

    for(int i = 0; i < dataLength; i++)
    {
        if(data[i] == ' ')
        {
            lowerData += data[i];
        }
        else if((data[i] > 64 && data[i] < 91) || (data[i] > 96 && data[i] < 123))
        {
            if(data[i] > 64 && data[i] < 91)
                lowerData += (char) ((int)data[i] + 32); 
            else
                lowerData += data[i];
        }
        else
        {
            std::cout << "Wrong character occured, End of the Program." << std::endl;
            std::exit(0);
        }
    }

    return lowerData;
}