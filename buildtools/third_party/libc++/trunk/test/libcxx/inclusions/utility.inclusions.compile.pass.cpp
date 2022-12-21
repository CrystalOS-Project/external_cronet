//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// WARNING: This test was generated by generate_header_inclusion_tests.py
// and should not be edited manually.
//
// clang-format off

// <utility>

// Test that <utility> includes all the other headers it's supposed to.

#include <utility>
#include "test_macros.h"

#if !defined(_LIBCPP_UTILITY)
 #   error "<utility> was expected to define _LIBCPP_UTILITY"
#endif
#if TEST_STD_VER > 17 && !defined(_LIBCPP_COMPARE)
 #   error "<utility> should include <compare> in C++20 and later"
#endif
#if TEST_STD_VER > 03 && !defined(_LIBCPP_INITIALIZER_LIST)
 #   error "<utility> should include <initializer_list> in C++11 and later"
#endif
