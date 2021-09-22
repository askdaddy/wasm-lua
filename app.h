//
// Created by Seven on 2021/9/22.
//

#ifndef WASM_LUA__APP_H
#define WASM_LUA__APP_H

#include <emscripten/html5.h>
#include <emscripten/bind.h>

namespace e = emscripten;

class App {
public:
    void doString(std::string codes);




};

EMSCRIPTEN_BINDINGS(EMTest) {
    e::class_<App>("App")
            .constructor()
            .function("doString", std::function<void(App &, std::string)>(&App::doString));

}


#endif //WASM_LUA__APP_H
