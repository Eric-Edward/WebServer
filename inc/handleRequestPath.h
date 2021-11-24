//
// Created by 25787 on 2021/11/24.
//

#ifndef WEBSERVER_HANDLEREQUESTPATH_H
#define WEBSERVER_HANDLEREQUESTPATH_H

#include <string>

///
/// \param reqUrl 从request请求中获得的请求地址。
/// \return 返回具体的请求地址。
std::string convertPath(char *reqUrl);


///
/// \param convertUrl 从上述函数中获取的具体地址。
/// \return 返回本地资源的地址。
std::string concatPath(std::string convertUrl);


///
/// \param reqUrl 输入request请求
/// \return 获取本地的资源
/// \brief 解析地址的总调用
std::string serviceOfConvert(char *reqUrl);


#endif //WEBSERVER_HANDLEREQUESTPATH_H
