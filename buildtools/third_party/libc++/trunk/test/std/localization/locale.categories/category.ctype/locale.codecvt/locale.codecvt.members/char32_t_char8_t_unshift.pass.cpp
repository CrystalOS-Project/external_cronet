//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14, c++17

// This test relies on https://wg21.link/P0482 being implemented, which isn't in
// older Apple dylibs
// XFAIL: use_system_cxx_lib && target={{.+}}-apple-macosx{{10.9|10.10|10.11|10.12|10.13|10.14|10.15|11.0}}

// <locale>

// template <> class codecvt<char32_t, char8_t, mbstate_t>

// result unshift(stateT& state,
//                externT* to, externT* to_end, externT*& to_next) const;

#include <cassert>
#include <locale>

int main(int, char**) {
  using F = std::codecvt<char32_t, char8_t, std::mbstate_t>;
  const F& f = std::use_facet<F>(std::locale::classic());
  std::mbstate_t mbs = {};
  char8_t to[3];
  char8_t* to_next = nullptr;
  assert(f.unshift(mbs, to, to + 3, to_next) == F::noconv);
  assert(to_next == to);
  return 0;
}
