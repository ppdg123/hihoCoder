#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct TreeNode
{
    struct TreeNode * son[26];
    int cnt[26];
};

struct TreeNode * root = NULL;

void insert(struct TreeNode * cur,char * str)
{
    int i,idx;
    i = 0;
    while(str[i]!='\0')
    {
        idx = str[i]-'a';
        cur->cnt[idx] ++;
        if(cur->son[idx] == NULL)
        {
            cur->son[idx] = (struct TreeNode * )malloc(sizeof(struct TreeNode));
        }
        i ++;
        cur = cur->son[idx];
    }
}

int check(struct TreeNode * cur, char * str)
{
    int i = 0;
    while(str[i+1]!='\0')
    {
      if(cur->son[str[i]-'a'] != NULL){
        cur = cur->son[str[i]-'a'];
        i++;
      }
      else return 0;
    }
    return cur->cnt[str[i]-'a'];
}

int main()
{
    int n,m,i,j;
    char str[100];
    while(EOF != scanf("%d",&n))
    {
        root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        while(n--)
        {
            scanf("%s",str);
            insert(root,str);
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",str);
            i = 0;
            struct TreeNode * cur = root;
            printf("%d\n",check(cur,str));
        }
    }
    return 0;
}