#include "App.h"
#include <thread>
#include <algorithm>
#include <iostream>
#include "AsyncFileReader.h"
#include "AsyncFileStreamer.h"

int main() {
    /* ws->getUserData returns one of these */
    struct PerSocketData {

    };

    /* Simple echo websocket server, using multiple threads */
    std::vector<std::thread *> threads(std::thread::hardware_concurrency());

    std::transform(threads.begin(), threads.end(), threads.begin(), [](std::thread *t) {
        return new std::thread([]() {

            /* Very simple WebSocket echo server */
            uWS::App().ws<PerSocketData>("/*", {
                /* Settings */
                .compression = uWS::SHARED_COMPRESSOR,
                .maxPayloadLength = 16 * 1024,
                .idleTimeout = 10,
                .maxBackpressure = 1 * 1024 * 1024,
                /* Handlers */
                .open = [](auto *ws) {

                },
                .message = [](auto *ws, std::string_view message, uWS::OpCode opCode) {
                    ws->send(message, opCode);
                },
                .drain = [](auto *ws) {
                    /* Check getBufferedAmount here */
                },
                .ping = [](auto *ws) {

                },
                .pong = [](auto *ws) {

                },
                .close = [](auto *ws, int code, std::string_view message) {

                }
            }).get("/*", [](auto *res, auto *req){
               res->onAborted([=](){ std::cout << "aborted" << std::endl; });
               std::cout << "received request: " << req->getUrl() << std::endl;
               std::string root {"./web"};
               AsyncFileStreamer asyncFileStreamer(root);     
               res->writeStatus(uWS::HTTP_200_OK);
               asyncFileStreamer.streamFile(res, req->getUrl());
            }).listen(9001, [](auto *token) {
                if (token) {
                    std::cout << "Thread " << std::this_thread::get_id() << " listening on port " << 9001 << std::endl;
                } else {
                    std::cout << "Thread " << std::this_thread::get_id() << " failed to listen on port 9001" << std::endl;
                }
            }).run();

        });
    });

    std::for_each(threads.begin(), threads.end(), [](std::thread *t) {
        t->join();
    });
}
