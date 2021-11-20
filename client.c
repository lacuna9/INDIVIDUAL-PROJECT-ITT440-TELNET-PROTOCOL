#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

//create and connecting socket

 int main()
 {
    int sockfd;
    char buffer[1000];
    char server_reply[2000];
    ssize_t n;

    struct sockaddr_in servaddr;

 sockfd = socket(AF_INET,SOCK_STREAM,0);
   if (sockfd == -1)
    {
        perror("Could not create socket");
    }

//connecting to port

 printf("Created Socket \n");
   bzero(&servaddr,sizeof (servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(23);
   servaddr.sin_addr.s_addr = inet_addr("192.168.56.103");

//connecting to server


   connect(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr));


while (1)
   {
	printf("What's in your mind?: ");
    scanf("%s",buffer);

	 if (send(sockfd,buffer,strlen(buffer),0) < 0)
    {
	   printf("Error \n");
	   return 1;
    }
     if(recv(sockfd,server_reply,2000,0 ) < 0)
    {
	   puts("Error");
	   break;
    }
   printf("Server Reply: %s \n",server_reply );

   }

	return 0;

 }
