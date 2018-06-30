//
// Created by 李杰 on 2018/6/29.
//

#include "tourism_budget_util.h"

void file_read() {
    char line[52][20];
    file = fopen("../route.dat", "r+");
    if (file == NULL)
        printf("无法打开文件");
    else {
        int i = 0;
        while (fgets(line[i], 20, file) != NULL) i++;
        distance = atof(line[0]);
        char *p = strtok(line[1], " ");
        i = 0;
        while (p != NULL) {
            if (i == 0) capacity = atof(p);
            else if (i == 1) consume = atof(p);
            else if (i == 2) cost = atof(p);
            else if (i == 3) num = (int) atof(p);
            i++;
            p = strtok(NULL, " ");
        }
        free(p);
        for (i = 2; i < 2 + num; i++) {
            char *p1 = strtok(line[i], " ");
            int j = 0;
            while (p1 != NULL) {
                if (j == 0) stations[i - 1]->length = atof(p1);
                else if (j == 1) stations[i - 1]->price = atof(p1);
                j++;
                p1 = strtok(NULL, " ");
            }
            free(p1);
        }
    }
}

void file_write() {
    file = fopen("../route.out", "w");
    if (file == NULL)
        printf("文件没有打开");
    else {
        int i;

        //写入最小的结果
        char *p;
        p = (char *) malloc(sizeof(char));
        sprintf(p, "%.2lf", MIN_BUDGET);
        fprintf(file, strcat(p, " "));
        free(p);

        //写入加油的站点的个数
        int book_1[51], count;
        count = 0;
        memset(book_1, 0, sizeof(book_1));
        for (i = 0; i <= num; i++)
            if (vis[i] == 1)
                book_1[count++] = i;
        char *p1 = (char *) malloc(sizeof(char));
        sprintf(p1, "%d", count);
        fprintf(file, strcat(p1, "\n"));
        free(p1);

        //写入停靠的站点
        for(i = 0; i < count; i++) {
            char *p2 = (char*) malloc(sizeof(char));
            sprintf(p2, "%d", book_1[i]);
            fprintf(file, strcat(p2, " "));
            free(p2);
        }
    }
}

void file_close() {
    fclose(file);
}
