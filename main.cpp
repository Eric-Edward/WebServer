#include <cstdio>
#include <winsock2.h>


int merror(unsigned long long redata, long long error, char *showinfo) {
    if (redata == error) {
        perror(showinfo);
        getchar();
        return -1;
    }
    return 0;
}

void sendWebHtml(SOCKET s, char *file) {
    FILE *pf = fopen(file, "r");

    if (pf == NULL) {
        printf("�ļ���ʧ�ܣ�");
        return;
    }

    char buf[1024]="";
    do {
        fgets(buf, 1024, pf);
        send(s, buf, (int)strlen(buf), 0);
    } while (!feof(pf));
}

int main() {
    printf("��ӭʹ�úο��ص�Web��������\n");


    WSADATA wsdata;
    int isOk = WSAStartup(MAKEWORD(2, 2), &wsdata);

    merror(isOk, WSAEINVAL, (char *) "����socketʧ��");
    SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    merror(server, INVALID_SOCKET, (char *) "����socketʧ��");


    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    address.sin_addr.s_addr = INADDR_ANY;

    isOk = bind(server, reinterpret_cast<const sockaddr *>(&address), sizeof(address));
    merror(isOk, SOCKET_ERROR, (char *) "��ʧ��...\n");

    isOk = listen(server, 5);
    merror(isOk, SOCKET_ERROR, (char *) "����ʧ��...\n");


    struct sockaddr_in cliAddress;
    int clilen = sizeof(cliAddress);
    while (true) {
        SOCKET client = accept(server, reinterpret_cast<sockaddr *>(&cliAddress), (int *) &client);
        merror(client, INVALID_SOCKET, (char *) "����ʧ��...\n");

        char recData[1024];
        recv(client, recData, 1024, 0);
        printf("%s\n�����յ�%d���ֽڵ����ݣ�", recData, strlen(recData));

        char *file = "D:\\homework\\electroniccommerce\\WebServer\\hh.html";
        sendWebHtml(client, file);
        closesocket(client);
    }

    closesocket(server);
    WSACleanup();


    getchar();
    return 0;
}