//server
#include<stdio.h>
#include<string.h>
#include<netinet/in.h>

int main(){

    int buf[100],i,sum=0,send_sum[100];
    int sock, sock_desc = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server,client;

    server.sin_family = AF_INET;
    server.sin_port = 3003;
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
    while(1){
            listen(sock_desc,5);
            socklen_t len = sizeof(client);
            sock = accept(sock_desc,(struct sockaddr*)&client,&len);

            recv(sock,buf,100,0);     //recive value from client in array format

            for(i=0;i<5;i++)
                sum = sum+buf[i];    //perform addition


                send_sum[0] = sum;     //convert the integer sum value to array format
                printf("Answer sended: \n");

                send(sock,send_sum,100,0); //sends the value
                sum =0;
    }

    return 0;

}

//client

#include<stdio.h>
#include<string.h>
#include<netinet/in.h>

int main(){

    int buf[100],i,sum[100];
    int sock_desc = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in client;

    client.sin_family = AF_INET;
    client.sin_port = 3003;
    client.sin_addr.s_addr = INADDR_ANY;
    connect(sock_desc,(struct sockaddr*)&client,sizeof(client));

    for(i=0;i<5;i++){
        printf("enter number:");
        scanf("%d",&buf[i]);
    }

    printf("Message sended to server: \n");
    send(sock_desc,buf,100,0); //send value to server in array format
    recv(sock_desc,sum,100,0); //recive value from server in array format
    printf("message from server - sum: %d",sum[0]);


    return 0;

}
