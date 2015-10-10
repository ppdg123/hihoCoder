#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    struct node * left, * right;
    char val;
    void init(){left=NULL,right=NULL;}
};

char chp[30], chm[30];

void generate(struct node * cur, int l,int r,int & ptr)
{
    cur->val = chp[ptr];
    int i;
    for(i=l;i<=r;i++)
    {
        if(chp[ptr]==chm[i]) break;
    }
    ptr++;
    if((i-l)>0)
    {
        cur->left = (struct node *)malloc(sizeof(struct node));
        cur->left->init();
        generate(cur->left,l,i-1,ptr);
    }
    if((r-i)>0)
    {
        cur->right = (struct node *)malloc(sizeof(struct node));
        cur->right->init();
        generate(cur->right,i+1,r,ptr);
    }
}

void DFS(struct node * cur)
{
    if(cur->left != NULL) DFS(cur->left);
    if(cur->right != NULL) DFS(cur->right);
    printf("%c",cur->val);
}

int main()
{
    int l,r,ptr;
    struct node root;
    while(EOF != scanf("%s%s",chp,chm))
    {
        l = 0;
        r = strlen(chp)-1;
        ptr = 0;
        root.init();
        generate(&root,l,r,ptr);
        DFS(&root);
        printf("\n");
    }
    return 0;
}