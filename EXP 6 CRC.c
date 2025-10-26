#include <stdio.h>
#include<string.h>
void xor(char*dividend,char*divisor,int pos){
    for(int i=0;divisor[i]!='\0';i++){
        dividend[pos+i]=(dividend[pos+i]==divisor[i]) ? '0':'1';
    }
}

void crc(char* data,char*divisor,char*remainder){
    int datalen = strlen(data);
    int divisorlen = strlen(divisor);
    char temp[100];
    
    strcpy(temp,data);
    
    for(int i=0;i<divisorlen-1;i++){
        strcat(temp,"0");
    }
    
    char dividend[100];
    strcpy(dividend,temp);
    for(int i=0;i<= strlen(dividend)-divisorlen;i++){
        if(dividend[i]=='1'){
            xor(dividend,divisor,i);
        }
    }
    
    strcpy(remainder,dividend+datalen);
}

int main() {
    char data[100],divisor[100],remainder[100],received[100];
    printf("enter the data bits: ");
    scanf("%s",data);
    printf("enter the divisor: ");
    scanf("%s",divisor);
    
    crc(data,divisor,remainder);
    
    char codeword[100];
    strcpy(codeword,data);
    strcpy(codeword,remainder);
    printf("Code Word : %s",codeword);
    
    printf("enter the received bits: ");
    scanf("%s",received);
    
    char checkremainder[100];
    crc(received,divisor,checkremainder);
    
    int  error = 0;
    for(int i=0;i<strlen(checkremainder);i++){
        if((checkremainder[i])=='1'){
            error =1;
            break;
        }
    }
    
    if(error==0) printf("no error");
    else printf("error");
    return 0;
}