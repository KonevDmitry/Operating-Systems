#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct frame_table
{
    int page_num;
    int age;
}
*frame;

struct page_table
{
    int frame_num;
    bool valid;
}
*page;

int oldest_ind(int frames)
{
    int oldest = 1,ind;
    for (int i = 0; i < frames; i++)
        if (oldest< frame[i].age)
        {
            oldest = frame[i].age;
            ind = i;
        }
    return ind;

}

int main()
{
    printf("Number of frames:\n");
    int frames;
    scanf("%d", &frames);
    frame = malloc(sizeof(frame)* frames);
    page=malloc(sizeof(page));
    for (int i = 0; i < frames; i++)
        frame[i].age = 0;
    FILE *input = fopen("input.txt", "r");
    int request,mis_count = 0,hit_count = 0,
                requset_count = 0,frame_count = 0;

    while (!feof(input))
    {
        fscanf(input, "%d", &request);
        requset_count++;

        if(page[request].valid == false)
        {
            frame[frame_count].page_num = request;
            page[request].frame_num = frame_count;
            page[request].valid = true;
            mis_count++;
            frame_count++;
        }
        else
            hit_count++;
        if (frame_count == frames)
            break;
    }

    while(!feof(input))
    {
        fscanf(input, "%d", &request);
        requset_count++;
        for (int i = 0; i < frames; i++)
            frame[i].age++;
        if (page[request].valid == false)
        {
            int old_page = oldest_ind(frames);
            page[frame[old_page].page_num].valid = false;
            frame[old_page].page_num = request;
            frame[old_page].age = 0;
            page[request].frame_num = old_page;
            page[request].valid = true;
            mis_count++;
        }
        else
            hit_count++;
    }

    printf("Miss count: %d\n", mis_count);
    printf("Hit count: %d\n", hit_count);
    printf("Ratio %f\n",(float)hit_count / (float)mis_count );
    fclose(input);

    free(frame);
    free(page);
    return 0;

}
