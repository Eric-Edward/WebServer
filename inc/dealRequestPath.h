//
// Created by 25787 on 2021/11/24.
//

#ifndef WEBSERVER_DEALREQUESTPATH_H
#define WEBSERVER_DEALREQUESTPATH_H

#include <string>

std::string convertPath(char *reqUrl);

std::string concatPath(std::string convertUrl);


std::string serviceOfConvert(char *reqUrl);


#endif //WEBSERVER_DEALREQUESTPATH_H
