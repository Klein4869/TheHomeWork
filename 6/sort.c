#include "stdio.h"
#include "string.h"

struct treenode {
    int index;
    int left_index;
    int right_index;
    char word[30];
    int value;
};

struct treenode t[100];

void print_node(int i){
    if (i == -1){
        return;
    }
    print_node(t[i].left_index);
    printf("%s %d\n", t[i].word, t[i].value);
    print_node(t[i].right_index);
}

int main(int argc, char const *argv[]) {
    int i, j, k, l;
    int counter = 0;
    int counter_1 = 0;

    for (l = 0; l < 100; ++l) {
        t[l].left_index =  -1; t[l].right_index = -1; t[l].value = 0;
    }
    char words[200][30];
    FILE *fp = fopen("article.txt", "r");
    char word_tmp[30];
    while (!feof(fp)) {
        char temp[200];
        fgets(temp, 200, fp);
        i = 0;
        j = 0;
        //
        while (temp[i] != '\0') {
            if (temp[i] > 'z' || (temp[i] < 'a' && temp[i] > 'Z') || temp[i] < 'A' && temp[i] != '\0' && j != 0) {
                word_tmp[j] = '\0';
                if (!strcmp(word_tmp, "")){
                    return 0;
                }
                j = 0;
                strcpy(words[counter++], word_tmp);
                for (k = 0; k < counter_1; ++k) {
                    if (strcmp(words[counter - 1], t[k].word) > 0){
                        if (t[k].right_index == -1){
                            t[counter_1].value++;
                            strcpy(t[counter_1].word, words[counter - 1]);
                            t[counter_1].index = k;
                            t[k].right_index = counter_1++;
                            break;
                        } else{
                            k = t[k].right_index - 1;
                            continue;
                        }
                    } else if (strcmp(words[counter - 1], t[k].word)== 0){
                        t[k].value++; break;
                    } else if (strcmp(words[counter - 1], t[k].word) < 0){
                        if (t[k].left_index == -1){
                            t[counter_1].value++;
                            strcpy(t[counter_1].word, words[counter - 1]);
                            t[counter_1].index = k;
                            t[k].left_index = counter_1++;
                            break;
                        } else{
                            k = t[k].left_index - 1;
                            continue;
                        }
                    }
                }
                if (counter_1 == 0){
                    strcpy(t[counter_1].word, words[counter - 1]);
                    t[counter_1].index = -1;
                    t[counter_1++].value++;
                }
                i++;
                continue;
            }
            while (temp[i] > 'z' || (temp[i] < 'a' && temp[i] > 'Z') || temp[i] < 'A' && temp[i] != '\0') {
                i++;
            }
            if (temp[i] >= 'A' && temp[i] <= 'Z'){
                temp[i] += 'a' - 'A';
            }
            word_tmp[j++] = temp[i++];
            if (temp[i-1] == '\0'){
                break;
            }
        } //
        if (word_tmp[0] >= 'a' && word_tmp[0] <= 'z') {
            strcpy(words[counter++], word_tmp);
            j = 0;
            for (k = 0; k < counter_1; ++k) {
                if (strcmp(words[counter - 1], t[k].word) > 0) {
                    if (t[k].right_index == -1) {
                        t[counter_1].value++;
                        strcpy(t[counter_1].word, words[counter - 1]);
                        t[counter_1].index = k;
                        t[k].right_index = counter_1++;
                        break;
                    } else {
                        k = t[k].right_index - 1;
                        continue;
                    }
                } else if (strcmp(words[counter - 1], t[k].word) == 0) {
                    t[k].value++;
                    break;
                } else if (strcmp(words[counter - 1], t[k].word) < 0) {
                    if (t[k].left_index == -1) {
                        t[counter_1].value++;
                        strcpy(t[counter_1].word, words[counter - 1]);
                        t[counter_1].index = k;
                        t[k].left_index = counter_1++;
                        break;
                    } else {
                        k = t[k].left_index - 1;
                        continue;
                    }
                }
            }
        }
    }
    printf("%s", t[0].word);
    if (t[0].right_index != -1){
        printf(" %s", t[t[0].right_index].word);
        if (t[t[0].right_index].right_index != -1){
            printf(" %s", t[t[t[0].right_index].right_index].word);
        }
    }
    printf("\n");
    i = 0;
    print_node(0);
    return 0;
}