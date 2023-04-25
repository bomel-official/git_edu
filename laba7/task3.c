#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int count_vowels(char *word);
int count_consonants(char *word);

int main() {
    char word[MAX_LENGTH];

    printf("Enter word: ");
    scanf("%s", word);

    printf("Amount vowels: %d\n", count_vowels(word));
    printf("Amount consonants: %d\n", count_consonants(word));

    return 0;
}

int count_vowels(char *word) {
    int count = 0;
    char *p = word;

    while (*p != '\0')
    {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u')
        {
            count++;
        }
        p++;
    }

    return count;
}

int count_consonants(char *word) {
    int count = 0;
    char *p = word;

    while (*p != '\0')
    {
        if (*p != 'a' && *p != 'e' && *p != 'i' && *p != 'o' && *p != 'u')
        {
            count++;
        }
        p++;
    }

    return count;
}