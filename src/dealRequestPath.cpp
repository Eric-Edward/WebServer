//
// Created by 25787 on 2021/11/24.
//
#include "../inc/dealRequestPath.h"

std::string SOURCE_URL = "D:\\homework\\electroniccommerce\\WebServer\\";

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