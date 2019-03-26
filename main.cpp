#include <iostream>
#include <ctime>
#include <string>
#include "functions.h"

char alphabet[]=
{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z'
};//A Global variable which will contain letters from the English Alphabet
int glb_var; // Global variable to store the generated key during the encryption process
/*-----------------------------------------------------*/
void menu();
std::string encryption_process(const std::string& userPhrase);
std::string decrypt_process(const std::string& encrytedPhrase);
void QUIT();

/*-----------------------------------------------------*/
int main(int argc, char* argv[])
{
    std::string userPhrase;
    std::string encryptedMessage;
    std::string decryptedMessage;
    short choice;

    do
    {
        menu();
        std::cout << "Choice :";
        std::cin >> choice;

        switch(choice)
        {
        case 1:
            encryptedMessage= { };
            decryptedMessage= { };
            std::cout << "Enter a word or a phrase to encrypt :";
            std::cin.ignore();
            getline(std::cin, userPhrase);
            encryptedMessage=encryption_process(userPhrase);
            std::cout << "Your message have been encrypted " << std::endl;
            break;
        case 2:
            if(!encryptedMessage.empty())
            {
                std::cout << "Ongoing Decryption..." << std::endl;
                decryptedMessage=decrypt_process(encryptedMessage);
                std::cout << "Your message have been decrypted " << std::endl;
            }
            break;
        case 3:
            if(!encryptedMessage.empty())
                std::cout << "Encrypted Message :" << encryptedMessage << std::endl;
            if(!decryptedMessage.empty())
                std::cout << "Decrypted Message :" << decryptedMessage << std::endl;
            break;
        case 4:
            QUIT();
        default:
            std::cout << "unknown Key" << std::endl;
        }
    }
    while(choice!=4);

    return 0;
}
/*-----------------------------------------------------*/
/**--------------------------
    Function that displays the Menu
**/
void menu()
{
    std::cout << "               #########################" << std::endl;
    std::cout << "               #      CESAR CYPHER     #" << std::endl;
    std::cout << "               #########################" << std::endl;

    std::cout << "                  1) Encrypt A message" << std::endl;
    std::cout << "                  2) Decrypt A message" << std::endl;
    std::cout << "                  3) Display " << std::endl;
    std::cout << "                  4) Quit" << std::endl;

}
/**--------------------------
    Function that encrypts a phrase
    entered by the user
**/
std::string encryption_process(const std::string& userPhrase)
{
    std::string localString{userPhrase};
    srand(time(NULL));
    const int randomNum=(rand() %25) +1;
    glb_var=randomNum;
    int p{0};

    for(unsigned i{0}; i<userPhrase.length(); i++)
    {
        for(auto j{0}; j<26; j++)
        {
            if(userPhrase[i]==alphabet[j] && userPhrase[i]!=' ')
            {
                if(randomNum+j<25)
                {
                    localString[i]=alphabet[randomNum+j];
                }
                else
                {
                    p=randomNum+j-26;
                    localString[i]=alphabet[p];
                }
            }
        }
        p=0;
    }

    return localString;
}
/**--------------------------
    Function that Decrypts an
    encrypted phrase from the User
    input
**/
std::string decrypt_process(const std::string& encrytedPhrase)
{
    std::string localString{encrytedPhrase};
    int p{0};

    for(unsigned i{0}; i<encrytedPhrase.length(); i++)
    {
        for(auto j{0}; j<26; j++)
        {
            if(encrytedPhrase[i]==alphabet[j] && encrytedPhrase[i]!=' ')
            {
                if(j-glb_var>=0)
                {
                    localString[i]=alphabet[j-glb_var];
                }
                else
                {
                    p=26+j-glb_var;
                    localString[i]=alphabet[p];
                }

            }
        }
        p=0;
    }

    return localString;
}
/**--------------------------**/
void QUIT()
{
    exit(EXIT_SUCCESS);
}
