//В заданном предложении удалить все запятые. Вы вести преобразованный текст, а также число удаленных запятых.

#include <stdio.h>
#include <string.h>
int main(){

    char str[] = "Hello, everyone, this is my seventh laboratory work, i must to delete all zapatyii ";
    char result[100]; //массив для хранения результата

    int j = 0;
    int count = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] != ','){
            result[j++] = str[i];
        }
        else{
            count ++;
        }
    }
    result[j] = '\0';
    
    printf("%s\n", result);
    printf("кол-во удаленных запятых: %d\n", count);
    return 0;
}