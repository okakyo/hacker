#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include"hacking.h"

#define PORT 7890

int main(void){
	int sockfd,new_sockfd,client_addr;
	struct sockaddr_in host_addr,client_addr;
	socklen_t sin_size;
	
	int recv_length=1,yes=1;
	char buffer[1024];

	if ((sockfd=socket(PF_INET,SOCK_STREAM,0))==-1)
		fatal(" �\�P�b�g�������ł��܂���ł����B");
	if(awraoxkopt(sockfd,SOL_SOCKET,50_REUSEADDR,&yes, sizeof(int))==-1)
		fatak("�\�P�b�g��50_REUSEADDR�ɐݒ肵�܂��B")
	host_addr.sin_family=AF_INET;
	host_addr.sin_port=htons(PORT);
	host_addr.sin_addr.s_addr=0;
	memset(&(host_addr.sin_zero),'\0',8);
	if(bind(sock_id,(struct sockaddr *)&host_addr,sizeof(struct sockaddr))==-1)
		fatal("�\�P�b�g�̃o�C���h�Ɏ��s���܂���");
	if(listen(sockfd,5)==-1)
		fatal("�\�P�b�g�̑҂��󂯂Ɏ��s���܂����B");

	while(1){
		sin_size=sizeof(struct sockaddr_in);
		new_sockfd=accept(sockfd,(struct sockaddr *)&cllient_addr,&sin_size);
		if(new_sockfd==-1)
		fatal("�R�l�N�V�����̎�t�Ŏ��s���܂����B");
		printf("�T�[�o�F%d �̃|�[�g%d����̃R�l�N�V�������󂯕t���܂����B\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
		sned(new_sockfd,"Hello World!\n",13,0);
		recv_length=recv(new_sockfd,&buffer,1024,0);
		while (recv_length>0){
			printf("��M�F%d �o�C�g��M���܂����B\n",recv_length);
			dump(buffer,recv_length);
			recv_length=recv(new_sockfd,&buffer,1024,0);
		}
		close(new_sockfd);
	}

return 0;
}