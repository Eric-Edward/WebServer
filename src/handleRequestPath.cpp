//
// Created by 25787 on 2021/11/24.
//
#include "../inc/handleRequestPath.h"

///设置一个本地资源的基础路径。
std::string SOURCE_URL = "D:\\homework\\electroniccommerce\\WebServer\\";


///
/// \author Eric
/// \details 根据request请求的格式得从第4位至之后的第一个空格为请求地址。所以设置一个string用来获取这一部分的内容。
/// \attention 如果请求为 “/” ，则应该自动对应至index.html。
std::string convertPath(char *reqUrl) {
    int start = 4;
    int end = start + 1;

    while (reqUrl[end] != ' ') {
        end++;
    }

    std::string url;
    for (int i = start + 1; i < end; i++) {
        url += *(reqUrl + i);
    }

    if (url == "") return url.append("index.html");

    return url;
}

std::string concatPath(std::string convertUrl) {
    return SOURCE_URL + convertUrl;
}

std::string serviceOfConvert(char *reqUrl) {
    return concatPath(convertPath(reqUrl));
}