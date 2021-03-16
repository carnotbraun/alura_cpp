#include <iostream>
#include <string>

using namespace std;
// serve para nao precisar declarar std antes das funcoes

// Utilizamos uma string, porque nao precisa mais utilizar um vetor do tipo char com [] tamanho, porque em c++, temos a string já para isso
const string PALAVRA_SECRETA = "MELANCIA"; 
// string = definir uma sequencia de caracteres

bool letra_existe(char chute)
{
    for(int i = 0; i < PALAVRA_SECRETA.size(); i++)
    // o .size se refere a quantidade de caracteres da palavra
        if(chute == PALAVRA_SECRETA[i])// [i] vai se incrementando por cada letra
        {
            return true;
        }
        return false;
}
int main()
{
    cout << PALAVRA_SECRETA;

    bool nao_acertou = true;

    bool nao_enforcou = true;

    while(nao_acertou && nao_enforcou)
    {
        char chute;

        cin >> chute;

        cout << "O seu chute foi " << chute << endl;

        if(letra_existe(chute))
        {
            cout << "Voce acertou! Seu chute esta na palavra." << endl;
        }
        else
        {
            cout << "Voce errou! Seu chute nao esta na palavra" << endl;
        }

    }
}
