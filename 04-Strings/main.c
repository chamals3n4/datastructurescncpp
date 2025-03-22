#include <stdio.h>

/*
char name[10] = {'c','h','a','m','a','l','\0'};
char name2[] = {'c','h','a','m','a','l','\0'};
*/

void length(char s[]){
    int i;
    for(i=0; s[i]!='\0'; i++){
    }
    printf("length is %d\n",i);
}

//change CASE UtoL LtoU
/*
    A-65 a-97  97-65 = 32
    B-66 b-98  98-66 = 32   .. 
*/
void toLowerCase(char s[]){
    for(int i=0;s[i]!='\0';i++){
        s[i]=s[i]+32;
    }
    printf("%s\n",s);
}
void toUpperCase(char s[]){
    for(int i=0;s[i]!='\0';i++){
        s[i]=s[i]-32;
    }
    printf("%s\n",s);
}

void ToggleUtoLvv(char s[]){
    for(int i=0; s[i]!='\0'; i++){
        if(s[i]>=65 && s[i]<=90)
            s[i]+=32;
        else if(s[i]>='a' && s[i]<=122)
            s[i]-=32;
    }
    printf("%s\n",s);
}

// 65-90 a-122
//
//

void VowelsAndConsanants(char s[]){
    int vcount=0;
    int ccount=0;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='A' || s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' || 
           s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
            vcount++;
        }
        else if (s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122) {
            ccount++;
        }
    }
    printf("num of vowels : %d\n",vcount);
    printf("num of consanants : %d\n",ccount);
}


// COUNT WORDS IN A STRING
void countWords(char s[]){
    int wcount=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' ' && s[i-1]!=' ') //second condition for to whitespaces
            wcount++;
    }
    printf("number of words %d\n",wcount+1);
}

int valid(char* s){
    for(int i=0; s[i]!='\0'; i++){
        if( !(s[i]>=65 && s[i]<=90) && 
            !(s[i]>=97 && s[i]<=122) && 
            !(s[i]>=48 && s[i]<=57)
        ){
            return 0;
        }
    }
    return 1;
}

void reverse(char s[]){
    char R[10];
    int i,j;
    for(i=0;s[i]!='\0';i++){}
    i=i-1;
    for(j=0;i>=0;i--,j++){
        R[j]=s[i];
    }
    R[j]='\0';
    printf("%s\n",R);
}

void reverse2(char s[]){
    char temp;
    int i,j;
    for(j=0;s[j]!='\0';j++){}
    j=j-1;
    for(i=0;i<j;i++,j--){
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    printf("%s\n",s);
}

void comp(char a[],char b[]){
    int i,j;
    for(int i=0,j=0; a[i]!='\0',b[j]!='\0'; i++,j++){
        if(a[i]!=b[j])
            break;
    }
    if(a[i]==b[j]) printf("EQUAL\n");
    else if (a[i]<b[j]) printf("SMALLER\n");
    else printf("GREATER\n");
}

void palindrome(char s[]){
    int  i,j;
    for(j=0;s[j]!='\0';j++){}
    j=j-1;
    for(i=0;i<j;i++,j--){
        if(s[i]!=s[j]){
            printf("NOT A PALINDROME");
            return;
        }
    }
    printf("THIS IS PALINDROME\n");
}

void duplicates(char s[]){
    int H[26]={0};
    for(int i=0;s[i]!='\0';i++){
        H[s[i]-97]+=1;
    }
    for(int i=0;i<26;i++){
        if(H[i]>1){
            printf("%c - ",i+97);
            printf("%d times\n",H[i]);
        }
    }
}

void duplicates2(char s[]){
    int H=0,X=0;
    for(int i=0; s[i]!='\0'; i++){
        X=1;
        X=X<<(s[i]-97);
        if((X&&H)>0){
            printf("%c is duplicate\n",s[i]);
        }
        else {
            H=X||H;
        }
    }
}

void anagram(char s[],char t[]){
    int i;
    int H[26]={0};
    for(i=0;s[i]!='\0';i++){
        H[s[i]-97]+=1;
    }
    for(i=0; t[i]!='\0';i++){
        H[t[i]-97]-=1;
        if(H[t[i]-97]<0){
            printf("not ANAGRAM\n");
            return;
        }
    }
    if(t[i]=='\0'){
        printf("ANAGRAM\n");

    }
}

void perm(char s[],int k){
    static int A[10]={0};
    static char res[10];
    int i;

    if(s[k]=='\0'){
        res[k]='\0';
        printf("%s", res);
    }else{
        for(int i=0; i<s[i]!='\0'; i++){
            if(A[i]==0){
                res[k]=s[i];
                A[i]=1;
                perm(s, k+1);
                A[i]=0;
            }
        }
    }
}

int main(){
    //char temp = 'A';
    //printf("%c\n",temp);
    //printf("%d\n",temp);

    char name[] = "chamalsena";
    char name2[] = "CHAMALSENA";
    char greet[] = "wELCome";
    char A[]="VAIBHAV NANGIA";
    char W[]="WHERES MY BEAUTIPUL CRUSH";
    char *username = "chamals3n4";
    char *username2 = "chamalsen4#";
    char rev[] = "python";


    char X[] = "Painter";
    char Y[] = "Painting";

    char P[] = "madam";

    char F[] = "finding";


    char m[] = "decimal";
    char n[] = "medical";

    char strp[] = "ABC";

    printf("%s\n",name);    
    length(name);
    toLowerCase(name2);
    toUpperCase(name);
    ToggleUtoLvv(greet);
    VowelsAndConsanants(A);
    countWords(W);

    printf("------validations------\n");
    printf("%d\n",valid(username));
    printf("%d\n",valid(username2));

    printf("------reverse------\n");
    reverse(rev);
    reverse2(rev);

    comp(X, Y);

    palindrome(P);
    duplicates(F);
    //duplicates2(F);

    anagram(m, n);

    printf("permutation example\n");
    perm(strp,0);

    return 0;
}
