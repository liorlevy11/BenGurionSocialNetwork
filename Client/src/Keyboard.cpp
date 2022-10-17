//
// Created by Shust on 31/12/2021.
//
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "../include/Keyboard.h"
#include "../include/ConnectionHandler.h"

Keyboard::Keyboard(ConnectionHandler &handler) : handler(handler), loggedIn(true) {}

Keyboard::~Keyboard() {

}

void Keyboard::run() {
    std::string result;
    while (loggedIn) {

        //while (handler.availableHandler()) {
        getline(std::cin, result);
        std::vector<std::string> keyWordsList;
        boost::split(keyWordsList, result, boost::is_any_of(" "));


        
        std::string shouldTerminate = keyWordsList.at(0);
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
        handler.sendLine(result);

        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
        //std::string out = "ACK signout succeeded\n";

        if (shouldTerminate == "LOGOUT") {
            std::cout << "need to sign out" << std::endl;
            logout();
            return;
        }
        // }
    }

}

void Keyboard::logout() {
    loggedIn = false;
}
