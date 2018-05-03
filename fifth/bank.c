#include <stdio.h>

struct people
{
    int waittime;
};

int main()
{
    int time_circle;
    scanf("%d", &time_circle);
    int i;
    int waitpeople = 0;
    int circle_people[100];
    struct people p[1000];
    int num_people = 0;
    int windows_number = 3;
    for (i = 0; i < time_circle; ++i)
    {
        scanf("%d", &circle_people[i]);
        int j;
        for (j = 0; j < circle_people[i]; ++j)
        {
            p[num_people++].waittime = 0;
        }
    }
    int j;
    int counter = 0;
    int num_people_1 = 0;
    for (j = 0; j < time_circle; ++j)
    {
        while ((waitpeople + circle_people[j]) / windows_number >= 7 && windows_number < 5)
        {
            windows_number++;
        }
        num_people_1 += circle_people[j];
        int temp = circle_people[j] - windows_number;
        if (temp <= 0 && waitpeople + temp <= 0)
        {
            waitpeople = 0;
        }
        else
        {
            waitpeople += temp;
        }
        int k;
        for (k = 0; k < windows_number; ++k)
        {
            if (counter + 1 > num_people_1)
            {
                break;
            }
            printf("%d : %d\n", counter, p[counter++].waittime);
        }
        for (k = counter; k < num_people_1; ++k)
        {
            p[k].waittime++;
        }
        while (waitpeople / windows_number < 7 && windows_number > 3)
        {
            windows_number--;
        }
    }
    while (counter < num_people_1)
    {
        int temp = -windows_number;
        if (temp <= 0 && waitpeople + temp <= 0)
        {
            waitpeople = 0;
        }
        else
        {
            waitpeople += temp;
        }
        int k;
        for (k = 0; k < windows_number; ++k)
        {
            if (counter + 1 > num_people_1)
            {
                break;
            }
            printf("%d : %d\n", counter, p[counter++].waittime);
        }
        for (k = counter; k < num_people_1; ++k)
        {
            p[k].waittime++;
        }
        while (waitpeople / windows_number < 7 && windows_number > 3)
        {
            windows_number--;
        }
    }
    return 0;
}