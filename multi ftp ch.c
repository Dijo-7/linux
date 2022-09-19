//server

#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>

int main(){
    char buf[100];
    int sock_desc,sock,sum[100]={0},i=0,j=0,len;
    struct sockaddr_in server,client;

    sock_desc = socket(AF_INET,SOCK_STREAM,0);
    server.sin_family = AF_INET;
    server.sin_port = 3030;
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
    listen(sock_desc,5) 
    len = sizeof(client);
    sock = accept(sock_desc,(struct sockaddr*)&client,&len);


    while(1){

        recv(sock,buf,sizeof(buf),0);


        if(strcmp(buf,"#")==0){
            break;
        }
        else{
            printf("%s",buf);
            for(i=0;i<strlen(buf);i++){
                if(buf[i] == ' '){
                    continue;
                }
                else
                    j++;

            }
            sum[0]= sum[0]+j-1;
            j =0;
        }
    }

    send(sock,sum,100,0);
}



//client

#include<stdio.h>
#include<string.h>
#include<netinet/in.h>

int main(){
    char ch[100];
    int buf[100];
    int sock_desc = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in client;

    client.sin_family = AF_INET;
    client.sin_port = 3030;
    client.sin_addr.s_addr = INADDR_ANY;
    
    connect(sock_desc,(struct sockaddr*)&client,sizeof(client));
    FILE* f = fopen("test.txt","r");


    while(fgets(ch,100,f) != NULL)
        send(sock_desc,ch,100,0);
    strcpy(ch,"#");
    send(sock_desc,ch,100,0);

    recv(sock_desc,buf,100,0);


    printf("text sended:\n");
    printf("%d",buf[0]);
}




