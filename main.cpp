#include <iostream>
#include <vector>
#include "request.h"
#include "loadBalancer.h"
#include "webServer.h"

int main(){
    vector<webServer> webServerVec;
    vector<request> requestVec;

    srand(time(0));
    
    int numServer = 1;
    int timeLoad = 0;
    int initalQSize;
    int simulationTime = 13;
    int currentId = numServer;
    // cout << "Enter the number of servers";
    // cin >> numServer;

    // cout << "Enter the timeLoad";
    // cin >> timeLoad;

    // cout << "Enter the simulation time for exit";
    // cin >> timeLoad;
    initalQSize = numServer * 5;
    loadBalancer lb;
    webServer server(lb, 0);
    for (int i = 0; i < initalQSize; i++){
        request request1;
        lb.queueRequest(request1);
        std::cout << request1.getTime() << std::endl;
    }
    for (int i = 0; i < numServer; i++){
        webServer server(lb, i);
        webServerVec.push_back(server);
    }

    // for (int i = 0; i < webServerVec.size();i++){
    //     webServerVec[i].printRequest();
    // }
    // lb.printRequestQ();
   
    int index = 0;

    int cnt = 0;

    int randomTimeRequest = rand() % 10;
    std::cout << "Random time: " << webServerVec.size() << std::endl;

    webServerVec[0].askRequest();
    webServerVec[0].askRequest();
    std::cout << webServerVec[0].getTime(0);
    std::cout << webServerVec[0].getTime(1);
    webServerVec[0].printRequest();
    
    // std::cout << "time ip: " << webServerVec[0].getTime(0) << std::endl;
    // while (timeLoad < simulationTime){

    //     webServerVec[index].askRequest();
    //     std::cout << "time ip: " << webServerVec[index].getTime() << std::endl;
    //     if (webServerVec[index].checkLimit() == true){
    //         std::cout << "creating another server" << std::endl;
    //         webServer server(lb, currentId);
    //         webServerVec.push_back(server);
    //         currentId += 1;
    //         index += 1;
    //     }
    //     else{
    //         std::cout << "It was processed" << std::endl;
    //     }
    //     timeLoad += 1; 
    //     // break;
    // }
    std::cout << "num of server: " << webServerVec.size() << std::endl;
    return 0;
}