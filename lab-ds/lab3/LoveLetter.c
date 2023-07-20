#include <stdio.h>
#include <string.h>

int main() {
    char encoded[110] = {0};
    char decoded[110] = {0};
    char vowels[] = "aeiou";

    fgets(encoded, 101, stdin);

    int i = 0, j = 0;

    while (encoded[i] != 0) {
        decoded[j++] = encoded[i];
        if (strchr(vowels, encoded[i]) != NULL) {
            i += 3;
        } else {
            i++;
        }
    }

    printf("%s", decoded);
        
    return 0;
}