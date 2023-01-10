#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row;
    int col;
    int data;
    struct Node *next;
};

void addSparseElementToLinkedList(struct Node **start, int i, int j, int nonZeroElem)
{

    struct Node *t, *s;
    t = *start;
    if (t == NULL)
    {

        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = nonZeroElem;
        t->row = i;
        t->col = j;
        t->next = NULL;
        *start = t;
    }
    else
    {

        while (t->next != NULL)
            t = t->next;

        s = (struct Node *)malloc(sizeof(struct Node));
        s->data = nonZeroElem;
        s->row = i;
        s->col = j;
        s->next = NULL;
        t->next = s;
    }
}

void displaySparseLinkedList(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    struct Node *start = NULL;
    int m, n;

    int s[3][5] = {
        {1, 0, 0, 2, 0}, {0, 0, 5, 0, 3}, {0, 0, 0, 6, 0}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (s[i][j] != 0)
                addSparseElementToLinkedList(&start, i, j, s[i][j]);
        }
    }

    displaySparseLinkedList(start);

    return (0);
}