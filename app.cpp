//
// Created by Seven on 2021/9/22.
//
#include <emscripten/bind.h>
#include <stdio.h>

using namespace emscripten;

std::string hello() {
    printf("hello world");
    return "hello world";
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("hello",&hello);
}