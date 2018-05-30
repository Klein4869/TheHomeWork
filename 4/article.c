#include "stdio.h"
#include "string.h"

struct words
{
    char content[50];
    int times;
};

struct treenode
{
    int index;
    int left_index;
    int right_index;
    char word[30];
    int value;
    int is_print;
};

struct words word[1000];

void qs(int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int i = left;
    int j = right;
    struct words key = word[left];
    while (i < j)
    {
        while (i < j && strcmp(word[j].content, key.content) >= 0)
            j--;
        word[i] = word[j];
        while (i < j && strcmp(word[i].content, key.content) <= 0)
            i++;
        word[j] = word[i];
    }

    word[i] = key;
    qs(left, j - 1);
    qs(i + 1, right);
}

int main(int argc, char const *argv[])
{
    int i, j, k, l;
    int counter = 0;
    int counter_1 = 0;
    struct treenode t[100];
    for (l = 0; l < 100; ++l)
    {
        t[l].left_index = -1;
        t[l].right_index = -1;
        t[l].value = 0;
        t[l].is_print = 0;
    }
    char words[200][30];
    FILE *fp = fopen("article.txt", "r");
    char word_tmp[30];
    //
    while (!feof(fp))
    {
        char temp[200];
        fgets(temp, 200, fp);
        i = 0;
        j = 0;
        //
        while (temp[i] != '\0')
        {
            if (temp[i] > 'z' || (temp[i] < 'a' && temp[i] > 'Z') || temp[i] < 'A' && temp[i] != '\0' && j != 0)
            {
                word_tmp[j] = '\0';
                if (!strcmp(word_tmp, ""))
                {
                    return 0;
                }
                j = 0;
                strcpy(words[counter++], word_tmp);
                for (k = 0; k < counter_1; ++k)
                {
                    if (strcmp(words[counter - 1], t[k].word) > 0)
                    {
                        if (t[k].right_index == -1)
                        {
                            t[counter_1].value++;
                            strcpy(t[counter_1].word, words[counter - 1]);
                            t[counter_1].index = k;
                            t[k].right_index = counter_1++;
                            break;
                        }
                        else
                        {
                            k = t[k].right_index - 1;
                            continue;
                        }
                    }
                    else if (strcmp(words[counter - 1], t[k].word) == 0)
                    {
                        t[k].value++;
                        break;
                    }
                    else if (strcmp(words[counter - 1], t[k].word) < 0)
                    {
                        if (t[k].left_index == -1)
                        {
                            t[counter_1].value++;
                            strcpy(t[counter_1].word, words[counter - 1]);
                            t[counter_1].index = k;
                            t[k].left_index = counter_1++;
                            break;
                        }
                        else
                        {
                            k = t[k].left_index - 1;
                            continue;
                        }
                    }
                }
                if (counter_1 == 0)
                {
                    strcpy(t[counter_1].word, words[counter - 1]);
                    t[counter_1].index = -1;
                    t[counter_1++].value++;
                }
                i++;
                continue;
            }
            while (temp[i] > 'z' || (temp[i] < 'a' && temp[i] > 'Z') || temp[i] < 'A' && temp[i] != '\0')
            {
                i++;
            }
            if (temp[i] >= 'A' && temp[i] <= 'Z')
            {
                temp[i] += 'a' - 'A';
            }
            word_tmp[j++] = temp[i++];
            if (temp[i - 1] == '\0')
            {
                break;
            }
        } //
        if (word_tmp[0] >= 'a' && word_tmp[0] <= 'z')
        {
            strcpy(words[counter++], word_tmp);
            j = 0;
            for (k = 0; k < counter_1; ++k)
            {
                if (strcmp(words[counter - 1], t[k].word) > 0)
                {
                    if (t[k].right_index == -1)
                    {
                        t[counter_1].value++;
                        strcpy(t[counter_1].word, words[counter - 1]);
                        t[counter_1].index = k;
                        t[k].right_index = counter_1++;
                        break;
                    }
                    else
                    {
                        k = t[k].right_index - 1;
                        continue;
                    }
                }
                else if (strcmp(words[counter - 1], t[k].word) == 0)
                {
                    t[k].value++;
                    break;
                }
                else if (strcmp(words[counter - 1], t[k].word) < 0)
                {
                    if (t[k].left_index == -1)
                    {
                        t[counter_1].value++;
                        strcpy(t[counter_1].word, words[counter - 1]);
                        t[counter_1].index = k;
                        t[k].left_index = counter_1++;
                        break;
                    }
                    else
                    {
                        k = t[k].left_index - 1;
                        continue;
                    }
                }
            }
        }
    }
    //
    printf("%s", t[0].word);
    if (t[0].right_index != -1)
    {
        printf(" %s", t[t[0].right_index].word);
        if (t[t[0].right_index].right_index != -1)
        {
            printf(" %s", t[t[t[0].right_index].right_index].word);
        }
    }
    printf("\n");
    i = 0;
    fclose(fp);
    //
    fp = fopen("article.txt", "r");
    char c;
    struct words tmp;
    int num = 0;
    // int i;
    int flag2 = 1;
    char content1[30];
    while (!feof(fp))
    {
        c = fgetc(fp);
        int i = 0;
        int isfind = 0;
        while ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = c + 'a' - 'A';
            }
            tmp.content[i++] = c;
            isfind = 1;
            c = fgetc(fp);
        }
        tmp.content[i] = '\0';
        if (isfind == 1)
        {
            tmp.times = 1;
            int flag = 0;
            for (i = 0; i < num; ++i)
            {
                if (!strcmp(tmp.content, word[i].content))
                {
                    word[i].times++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                word[num++] = tmp;
            }
        }
    }
    fclose(fp);
    // strcpy(content1, word[0].content);
    // int flag1 = 0;
    // printf("%s", content1);
    // for (i = 1; i < num; ++i)
    // {
    //     if (flag1 == 2)
    //     {
    //         break;
    //     }
    //     if (strcmp(word[i].content, content1) > 0)
    //     {
    //         printf(" %s", word[i].content);
    //         strcpy(content1, word[i].content);
    //         flag1++;
    //     }
    // }
    qs(0, num - 1);
    // printf("\n");
    for (i = 0; i < num; ++i)
    {
        printf("%s %d\n", word[i].content, word[i].times);
    }
    return 0;
}