// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

#include <Stream.h>

#include "../TypeTraits/EnableIf.hpp"
#include "../TypeTraits/IsBaseOf.hpp"
#include "../TypeTraits/RemoveReference.hpp"

namespace ArduinoJson {
namespace Internals {

struct ArduinoStreamTraits {
  class Iterator {
    Stream& _stream;

   public:
    Iterator(Stream& stream) : _stream(stream) {}

    char next() {
      // don't use _stream.read() as it ignores the timeout
      char c = 0;
      _stream.readBytes(&c, 1);
      return c;
    }
  };
};

template <typename TStream>
struct StringTraits<TStream,
                    // match any type that is derived from Stream:
                    typename TypeTraits::EnableIf<TypeTraits::IsBaseOf<
                        Stream, typename TypeTraits::RemoveReference<
                                    TStream>::type>::value>::type>
    : ArduinoStreamTraits {};
}
}
