// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

namespace ArduinoJson {
namespace Internals {

// Parse JSON string to create JsonArrays and JsonObjects
// This internal class is not indended to be used directly.
// Instead, use JsonBuffer.parseArray() or .parseObject()
template <typename TIterator>
class StringReader {
  TIterator _input;
  char _current, _next;

 public:
  StringReader(const TIterator& input) : _input(input) {
    _current = 0;
    _next = 0;
  }

  void move() {
    _current = _next;
    _next = 0;
  }

  char current() {
    if (!_current) _current = _input.next();
    return _current;
  }

  char next() {
    // assumes that current() has been called
    if (!_next) _next = _input.next();
    return _next;
  }
};
}
}
