#include<stdio.h>
#include<string.h>
char* transform_uppercase(char s[])
{
    int i;
    for(i=0;s[i];i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            s[i]=s[i]-32;
    }
    return s;
    
}
int is_pallindrome(char str[])
{
    int l=strlen(str),i,j;
    
    for(i=0;i<l/2;i++)
    {
        if(str[i]!=str[l-1-i])
            return 0;
    }
    return 1; 
}
void trim_string(char str[])
{
    int l=strlen(str),m;
    int no_starting_space=0,no_ending_space=0,i=0;
    while (str[i]==' ')
    {
        no_starting_space+=1;
        i+=1;
    }
    while (str[l-1]==' ')
    {
        no_ending_space+=1;
        l-=1;
    }
    m=strlen(str)-no_ending_space-no_starting_space;
    for(i=0;i<m;i++)
    {
        str[i]=str[i+no_starting_space];
    }
    str[i]='\0';

    
}
int count_words(char str[])
{
    trim_string(str);
    int i=0,count=0;
    for(i=0;str[i];i++)
    {
        if(str[i]==' ')
        {
            if(str[i]==str[i+1])
                continue;
            else
                count++;
        }
        
    }
    return count+1;
}
char* reverse_string(char str[])
{
    int i,j,k,word_count;
    word_count=count_words(str);
    char s[word_count][50];
    for(i=0,j=0,k=0;str[i];i++,k++)
    {
        if(str[i]!=' ')
            s[j][k]=str[i];
        else
        {
            s[j][k]='\0';
            j++;
            k=-1;
        }
    }
    str[0]='\0';
    for(j=word_count-1;j>=0;j--)
    {
        if(str[0]!='\0')
            strcat(str," ");
        strcat(str,s[j]);
    }
    str[strlen(str)]='\0';
    return str;


}
int main()
{
    char s1[]="abcdef";
    printf("%s",reverse_string(s1));
}