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
        printf("文件打开失败！");
        return;
    }

    char buf[1024]="";
    do {
        fgets(buf, 1024, pf);
        send(s, buf, (int)strlen(buf), 0);
    } while (!feof(pf));
}

int main() {
    printf("欢迎使用何科霖的Web服务器！\n");


    WSADATA wsdata;
    int isOk = WSAStartup(MAKEWORD(2, 2), &wsdata);

    merror(isOk, WSAEINVAL, (char *) "申请socket失败");
    SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    merror(server, INVALID_SOCKET, (char *) "创建socket失败");


    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    address.sin_addr.s_addr = INADDR_ANY;

    isOk = bind(server, reinterpret_cast<const sockaddr *>(&address), sizeof(address));
    merror(isOk, SOCKET_ERROR, (char *) "绑定失败...\n");

    isOk = listen(server, 5);
    merror(isOk, SOCKET_ERROR, (char *) "监听失败...\n");


    struct sockaddr_in cliAddress;
    int clilen = sizeof(cliAddress);
    while (true) {
        SOCKET client = accept(server, reinterpret_cast<sockaddr *>(&cliAddress), (int *) &client);
        merror(client, INVALID_SOCKET, (char *) "连接失败...\n");

        char recData[1024];
        recv(client, recData, 1024, 0);
        printf("%s\n共接收到%d个字节的数据！", recData, strlen(recData));

        char *file = "D:\\homework\\electroniccommerce\\WebServer\\hh.html";
        sendWebHtml(client, file);
        closesocket(client);
    }

    closesocket(server);
    WSACleanup();


    getchar();
    return 0;
}