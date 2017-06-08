char *my_strnncpy(char *src, int i, int size)
 {
    char* str;
    int count;

    if((str = malloc(sizeof(char)*size)) == NULL)
        my_error(5);
    for (count = 0; src[i] != '\0' && count < size; ++i, ++count)
        str[count] = src[i];

    return str;
 }
 